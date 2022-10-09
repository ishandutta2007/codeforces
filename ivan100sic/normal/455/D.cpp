#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int A[100005],B[100005],N;
vector <int> X[100005];

struct redirect{
    int l,r,offs;
    //l,r = gde se sad nalazi
    //l-offs,r-offs = u sta slika
};

redirect W[205],R2[205];
int RRR;

inline int izbroji(int x,int L,int R){
    //printf("brojim %d %d %d\n",x,L,R);
    if (L>R) return 0;
    int l,r,m,o1,o2;
    l = 0;
    r = X[x].size()-1;
    o1 = 199999;
    while (l<=r){
        m = (l+r)/2;
        if (X[x][m] >= L){
            o1 = m;
            r = m-1;
        } else {
            l = m+1;
        }
    }
    l = 0;
    r = X[x].size()-1;
    o2 = -1;
    while (l<=r){
        m = (l+r)/2;
        if (X[x][m] <= R){
            o2 = m;
            l = m+1;
        } else {
            r = m-1;
        }
    }
    return max(0,o2-o1+1);
}

void seci(int L,int R){
    int i,j,k=0;
    for (i=1; i<=RRR; i++){
        //segment [l,r-1] treba da se siftuje za jedno mesto udesno a [r,r] za r-l mesta ulevo
        if (W[i].l <= L && R <= W[i].r){ //segment sadrzi ceo upit

            if (W[i].l < L){
                k++;
                R2[k].l = W[i].l;
                R2[k].r = L-1;
                R2[k].offs = W[i].offs;
            }

            if (R < W[i].r){
                k++;
                R2[k].l = R+1;
                R2[k].r = W[i].r;
                R2[k].offs = W[i].offs;
            }

            k++;
            R2[k].l = L+1;
            R2[k].r = R;
            R2[k].offs = W[i].offs-1;

            k++;
            R2[k].l = L;
            R2[k].r = L;
            R2[k].offs = W[i].offs+(R-L);

            swap(W[i],W[RRR]);
            RRR--;i--;
        } else
        if (R < W[i].l || W[i].r < L){ //nema presecnih tacki
            ;
        } else
        if (L <= W[i].l && W[i].r <= R-1){ //segment ceo upada u masu upita
            W[i].l++;
            W[i].r++;
            W[i].offs--;
        } else
        if (W[i].r >= R){ //segment sadrzi R ali ne i celu masu zbog onog prvog

            k++;
            R2[k].l = L;
            R2[k].r = L;
            R2[k].offs = W[i].offs + (R-L);

            if (W[i].l < R){
                k++;
                R2[k].l = W[i].l + 1;
                R2[k].r = R;
                R2[k].offs = W[i].offs - 1;
            }

            if (W[i].r > R){
                k++;
                R2[k].l = R+1;
                R2[k].r = W[i].r;
                R2[k].offs = W[i].offs;
            }

            swap(W[i],W[RRR]);
            RRR--;i--;

        } else
        if (W[i].l < L){ //segment ne sadrzi R ali sadrzi nesto

            //printf("slucaj %d %d %d\n",W[i].l,W[i].r,W[i].offs);
            k++;
            R2[k].l = W[i].l;
            R2[k].r = L-1;
            R2[k].offs = W[i].offs;

            k++;
            R2[k].l = L+1;
            R2[k].r = W[i].r+1;
            R2[k].offs = W[i].offs - 1;

            swap(W[i],W[RRR]);
            RRR--;i--;

        } else {
            printf("nesto propustas\n");
        }

    }
    for (i=1; i<=k; i++){
        RRR++;
        W[RRR] = R2[i];
    }
}

int obradi(int x,int l,int r){
    int i,z=0,l2,r2;
    for (i=1; i<=RRR; i++){
        l2 = max(l,W[i].l) + W[i].offs;
        r2 = min(r,W[i].r) + W[i].offs;
        z += izbroji(x,l2,r2);
    }
    return z;
}

void debug(){
    int i;
    printf("debug >> %d\n",RRR);
    for (i=1; i<=RRR; i++) printf("%d %d %d\n",W[i].l,W[i].r,W[i].offs);
}

void ucitaj(){
    scanf("%d",&N);
    int i;
    for (i=1; i<=N; i++) scanf("%d",A+i);
    RRR=1;
    W[1].l = 1;
    W[1].r = N;
    W[1].offs = 0;
}

void rekonstruisi(){
    int i,j;
    for (i=1; i<=RRR; i++){
        for (j=W[i].l; j<=W[i].r; j++){
            B[j] = A[j+W[i].offs];
        }
    }
    for (i=1; i<=N; i++) X[i].clear();
    for (i=1; i<=N; i++){
        A[i] = B[i];
        X[A[i]].push_back(i);
    }
    RRR = 1;
    W[1].l = 1;
    W[1].r = N;
    W[1].offs = 0;
}

int main(){
    int ans=0,q,i,j,k,l,r,x,t;
    ucitaj();
    rekonstruisi();
    scanf("%d",&q);
    while (q--){
        scanf("%d",&t);
        if (t==1){
            scanf("%d%d",&l,&r);
            l = (l + ans - 1) % N + 1;
            r = (r + ans - 1) % N + 1;
            if (l>r) swap(l,r);
            seci(l,r);
            //debug();
            if (RRR > 100) rekonstruisi();
        } else {
            scanf("%d%d%d",&l,&r,&k);
            l = (l + ans - 1) % N + 1;
            r = (r + ans - 1) % N + 1;
            k = (k + ans - 1) % N + 1;
            if (l>r) swap(l,r);
            ans = obradi(k,l,r);
            printf("%d\n",ans);
        }
    }
    return 0;
}
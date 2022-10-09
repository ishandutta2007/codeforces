#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAXN 131072
#define OFFS 131071
using namespace std;

struct covek{
    int idx,sprat,zelja,t;
};

vector <covek> Lift[100005];
long long Sol[100005],Tot;
vector <covek> Sprat[100005];
covek A[100005];
covek Hrono[100005],q;
int N,M,F,HronoQ,Tree[2*MAXN],RMC[2*MAXN],LMC[2*MAXN];

/* <Kumulativna> */

int C[100005];

void ubaci(int p,int v){
    //printf("sta sve nece izmisle %d %d\n",p,v);
    while (p<=M){
        C[p] += v;
        p += p&(-p);
    }
}

int citaj(int p){
    //printf("kuku majko %d\n",p);
    int v=0;
    if (p<=0) return 0;
    while (p>0){
        v += C[p];
        p -= p&(-p);
    }
    return v;
}

int suma(int l,int r){
    return citaj(r) - citaj(l-1);
}

int prvimanji(int x);
int prviveci(int x);
void ubaci_tree(int p,int v);

/* </Kumulativna> */

void ucitaj(){
    scanf("%d%d",&N,&M);
    F=1;
    for (int i=1; i<=N; i++){
        scanf("%d%d%d",&A[i].t,&A[i].sprat,&A[i].zelja);
        A[i].idx = i;
        Hrono[i] = A[i];
    }
}

void idinasprat(int x){
    //printf("sacu idem na sprat %d\n",x);
    Tot += abs(x-F);
    F=x;
    //I deo : ostavljam ljude
    while (Lift[x].size() > 0){
        q = Lift[x][Lift[x].size()-1];
        Lift[x].pop_back();
        Sol[q.idx] = Tot;
        ubaci(q.zelja,-1);
        ubaci_tree(q.zelja,-1);
        //printf("ostavio ljude\n");
    }
    //II deo : pokupljam ljude
    while (Sprat[x].size() > 0){
        q = Sprat[x][Sprat[x].size()-1];
        Sprat[x].pop_back();
        Lift[q.zelja].push_back(q);
        ubaci(q.sprat,-1);
        ubaci_tree(q.sprat,-1);
        ubaci(q.zelja,1);
        ubaci_tree(q.zelja,1);
        //printf("pokupio ljude\n");
    }
}

bool cmp_hrono(covek a,covek b){
    return a.t < b.t;
}

void dovedi_narod(){
    //printf("sacu dovedem narod\n");
    while (HronoQ < N && Hrono[HronoQ+1].t <= Tot){
        HronoQ++;
        q = Hrono[HronoQ];
        Sprat[q.sprat].push_back(q);
        ubaci(q.sprat,1);
        ubaci_tree(q.sprat,1);
        //printf("kakav blesav narod da ne poverujes\n");
    }
}

void ubaci_tree(int p,int v){
    p+=OFFS;
    while (p>0){
        Tree[p] += v;
        p /= 2;
    }
}

void napravi_pos(){
    int i;
    for (i=MAXN; i<2*MAXN; i++){
        RMC[i] = i;
        LMC[i] = i;
    }
    for (i=OFFS; i>=1; i--){
        RMC[i] = RMC[2*i+1];
        LMC[i] = LMC[2*i];
    }
}

int prvimanji(int x){
    //printf("prvi manji brate lol\n");
    if (suma(1,x)==0) return -1;
    x += OFFS;
    while (true){
        //printf("znaci x je %d\n",x);
        if (Tree[x]>0) return x-OFFS;
        while (Tree[x/2]==0 && x%2==1) x/=2;
        x = LMC[x]-1;
    }
}

int prviveci(int x){
    //printf("znaci ima i prvi veci bate\n");
    if (suma(x,M)==0) return -1;
    x += OFFS;
    while (true){
        //printf("jea torimjau %d\n",x);
        if (Tree[x]>0) return x-OFFS;
        while (Tree[x/2]==0 && x%2==0) x/=2;
        x = RMC[x]+1;
    }
}

bool pokreni_lift(){
    bool gore = suma(F+1,M) >= suma(1,F-1);

    //printf("%d %lld\n",F,Tot);

    if (HronoQ == N && suma(1,M)==0) return false;
    if (suma(1,M)==0){
        Tot = Hrono[HronoQ+1].t;
        dovedi_narod();
        return true;
    }

    int i,j,k;
    if (gore){
        k = prviveci(F)-F;
        if (HronoQ == N){
            idinasprat(F + k);
        } else {
            j = Hrono[HronoQ+1].t - Tot;
            if (j<=k){
                idinasprat(F + j);
                dovedi_narod();
            } else {
                idinasprat(F + k);
            }
        }
    } else {
        k = F-prvimanji(F);
        if (HronoQ == N){
            idinasprat(F - k);
        } else {
            j = Hrono[HronoQ+1].t - Tot;
            if (j<=k){
                idinasprat(F - j);
                dovedi_narod();
            } else {
                idinasprat(F - k);
            }
        }
    }

    return true;
}

int main(){
    napravi_pos();
    ucitaj();
    sort(Hrono+1,Hrono+N+1,cmp_hrono);
    while (pokreni_lift());
    for (int i=1; i<=N; i++) printf("%lld\n",Sol[i]);
    return 0;
}
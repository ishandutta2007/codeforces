#include <cstdio>
#include <cstring>
#include <algorithm>
#define citanje "%lld"
using namespace std;

long long aps(long long x){
    if (x<0) return -x; else return x;
}

long long P[100005],A[100005];
//P - disk heads
//A - tracks (targets)
int N,M;

long long space(long long l,long long r,long long centar){
    return r-l + min(abs(centar-l),abs(r-centar));
}

bool probaj(long long gap){
    int l,r,i,j;
    l=1;
    r=1;
    for (i=1; i<=N; i++){
        //proverim da li mogu u ovo prazno da odem
        if (space(A[l],A[r],P[i]) > gap) continue;
        while (true){
            //probamo space
            if (space(A[l],A[r],P[i]) <= gap){
                //probacemo sledeci
                r++;
                if (r > M) return true;
            } else {
                //pukli smo
                r--;
                break;
            }
        }
        l = r+1;
        r = l;
        if (r > M) return true;
    }
    return r > M;
}


int main(){
    long long i,l,r,m,o;
    scanf("%d%d",&N,&M);
    for (i=1; i<=N; i++) scanf(citanje,P+i);
    for (i=1; i<=M; i++) scanf(citanje,A+i);
    l=0;
    r=9000000000000000000ll;
    while (l<=r){
        m = (l+r)/2;
        if (probaj(m)){
            o = m;
            r = m-1;
        } else {
            l = m+1;
        }
    }
    printf(citanje,o);
    return 0;
}
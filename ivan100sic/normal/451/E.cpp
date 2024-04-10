#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 1000000007
using namespace std;

long long A[25],X,sol,p,xx;
int N,i,j,k,mask,br;

long long stepen(long long b,long long e){
    int i;
    b %= MOD;
    long long r = 1;
    for (i=30; i>=0; i--){
        r = (r*r) % MOD;
        if ((1<<i)&e) r = (r*b) % MOD;
    }
    return r;
}

long long inv(long long x){
    return stepen(x,MOD-2);
}

long long konstanta;

void getc(){
    konstanta = 1;
    for (int i=1; i<=N-1; i++){
        konstanta = (konstanta*inv(i))%MOD;
    }
}

long long akutijabstvarimin0(long long a,long long b){
    if (b==0) return 1;
    if (b<0) return 0;
    //a-1 pregrada
    //b stvari
    //binomni koeficijenat b+a-1 nad a-1
    a--;
    b+=a;
    b %= MOD;
    int i;
    long long r = 1;
    for (i=1; i<=a; i++){
        r = (r*b)%MOD;
        b--;
    }
    r = (r*konstanta) % MOD;
    return r;
}

int main(){
    scanf("%d%lld",&N,&X);
    getc();
    for (i=0; i<N; i++) scanf("%lld",A+i);
    for (mask=0; mask<(1<<N); mask++){
        p = 1;
        xx = X;
        for (i=0; i<N; i++) if (mask & (1<<i)){
            p *= -1;
            xx -= A[i]+1;
        }
        sol += akutijabstvarimin0(N , xx) * p;
    }
    sol %= MOD;
    if (sol < 0) sol += MOD;
    printf("%lld\n",sol);
    return 0;
}
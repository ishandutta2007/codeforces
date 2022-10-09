#include <cstdio>
#define MOD 1000000007
#define citac "%I64d"
using namespace std;

long long A,B,N,i,j,k,l,bra,brb,alfa,beta,sol;

inline bool dobar(long long x){
    long long r;
    while (x>0){
        r = x%10;
        if (!(r == A || r == B)) return false;
        x /= 10;
    }
    return true;
}

long long Fact[1000005];

long long stepen(long long x,long long e){
    if (e==0) return 1;
    if (e==1) return x;
    long long z = stepen(x,e/2);
    z *= z;
    z %= MOD;
    if (e%2) z *= x;
    return z % MOD;
}

inline long long mod_inv(long long x){
    return stepen(x , MOD-2);
}

long long binom_k(long long n,long long k){
    if (k>n) return 0;
    long long r;
    r = Fact[n] * mod_inv(Fact[n-k]);
    r %= MOD;
    r *= mod_inv(Fact[k]);
    return r % MOD;
}

int main(){
    scanf(citac,&A);
    scanf(citac,&B);
    scanf(citac,&N);

    Fact[0] = 1;
    for (i=1; i<=N; i++){
        Fact[i] = Fact[i-1] * i;
        Fact[i] %= MOD;
    }

    for (i=1; i<=9*N; i++){
        if (dobar(i)){
            //printf(citac,i);
            //puts("");
            if ((i - B*N) % (A - B) == 0){
                alfa = (i - B*N) / (A - B);
                beta = N-alfa;
                if (alfa < 0 || beta < 0) continue;
                //printf("%lld %lld\n",alfa,beta);
                sol += binom_k(alfa+beta , alfa);
                sol %= MOD;
            }
        }
    }
    printf(citac,sol);
    return 0;
}
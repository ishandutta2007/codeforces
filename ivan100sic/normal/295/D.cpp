#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 1000000007
using namespace std;

int N,M;

inline void zbir(long long *S1,long long *S2,long long *D,int c1,int c2){
    for (int i=2; i<=M; i++) D[i] = (c1*S1[i] + c2*S2[i]) % MOD;
}

inline long long proizvod(long long *S1,long long *S2){
    long long r=0;
    for (int i=2; i<=M; i++){
        r += S1[i]*S2[i];
        r %= MOD;
    }
    return r;
}

inline long long proizvod_w(long long *S1,long long *S2){
    long long r=0,z;
    for (int i=2; i<=M; i++){
        z = S1[i]*S2[i];
        z %= MOD;
        z *= (M-i+1);
        z %= MOD;
        r += z;
        r %= MOD;
    }
    return r;
}


long long Vektor[2222][2222],ZbirVektor[2222][2222],ZbirVektor2[2222][2222],ZbirVektor3[2222][2222];
long long PreCarski[2222][2222],PreCarski2[2222][2222];

//vektor[vis][sir] = broj piramida tako da je najnizi nivno sirine tacno sir a ostali su strogo manji
//PreCarski = broj piramida tako da je najnizi nivo sirine tacno sir
//PreCarski2 = suma(2..i , Precarski[i])

int main(){
    scanf("%d%d",&N,&M);
    int sir,vis,t;
    long long sol=0,nov;
    sir=2;
    for (vis=1; vis<=N; vis++) PreCarski[vis][sir] = 1;
    vis=1;
    for (sir=1; sir<=M; sir++) PreCarski[vis][sir] = 1;
    for (sir=3; sir<=M; sir++){
        for (vis=2; vis<=N; vis++){
            PreCarski[vis][sir] = 2*PreCarski[vis][sir-1] - PreCarski[vis][sir-2] + PreCarski[vis-1][sir];
            PreCarski[vis][sir] %= MOD;
        }
    }

    for (vis=1; vis<=N; vis++){
        for (sir=2; sir<=M; sir++){
            PreCarski2[vis][sir] = PreCarski2[vis][sir-1] + PreCarski[vis][sir];
            PreCarski2[vis][sir] %= MOD;
        }
    }

    for (vis=1; vis<=N; vis++){
        for (sir=2; sir<=M; sir++){
            Vektor[vis+1][sir] = Vektor[vis+1][sir-1] + PreCarski2[vis][sir];
            Vektor[vis+1][sir] %= MOD;
        }
    }

    for (vis=1; vis<=N; vis++){
        for (sir=2; sir<=M; sir++){
            Vektor[vis+1][sir] -= PreCarski[vis][sir];
            if (Vektor[vis+1][sir] < 0) Vektor[vis+1][sir] += MOD;
        }
    }

    vis=1;
    for (sir=2; sir<=M; sir++) Vektor[vis][sir] = 1;
    sir=2;
    for (vis=2; vis<=N; vis++) Vektor[vis][sir] = 0;

    /*for (sir=2; sir<=M; sir++){
        for (vis=1; vis<=N; vis++){
            printf("%lld%c",Vektor[vis][sir],vis==N?'\n':' ');
        }
    }*/

    for (vis=1; vis<=N; vis++){
        zbir(ZbirVektor[vis-1],Vektor[vis],ZbirVektor[vis],1,1);
    }
    for (vis=1; vis<=N; vis++){
        zbir(ZbirVektor2[vis-1],ZbirVektor[vis],ZbirVektor2[vis],1,1);
    }
    for (vis=1; vis<=N; vis++){
        zbir(ZbirVektor3[vis-1],ZbirVektor2[vis],ZbirVektor3[vis],1,1);
    }
    for (vis=1; vis<=N; vis++){
        nov = proizvod_w(Vektor[vis],ZbirVektor3[N-vis+1]);
        sol += nov;
        sol %= MOD;
    }
    printf("%lld\n",sol);
    return 0;
}
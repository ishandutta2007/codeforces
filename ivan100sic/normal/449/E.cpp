#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 1000000007
using namespace std;

int FSF[1000005];

void sito(){
    int i,j,k;
    j = 2;
    for (i=1; i<=300; i++){
        while (FSF[j]>0) j++;
        for (k=j*j; k<=1000000; k+=j) if (FSF[k]==0) FSF[k] = j;
        j++;
    }
    for (i=1; i<=1000000; i++) if (FSF[i]==0) FSF[i] = i;
}

int Et[1000005];

void totienti(){
    int i,j,k,l,f,lf;
    for (i=1; i<=1000000; i++){
        k = i;
        l = i;
        lf = -1;
        while (k>1){
            f = FSF[k];
            k /= f;
            if (f != lf){
                l /= f;
                l *= f-1;
            }
            lf = f;
        }
        Et[i] = l;
    }
}

int Pu[1000005];

void pulen(){
    int d,n,i,j,k;
    for (d=1; d<=1000000; d++){
        for (n=d; n<=1000000; n+=d){
            Pu[n] += d * Et[n/d];
            if (Pu[n] >= MOD) Pu[n] -= MOD;
        }
    }
    for (i=1; i<=1000000; i++){
        Pu[i] += i;
        if (Pu[i] >= MOD) Pu[i] -= MOD;
    }
}

int Pe[1000005];

void peee(){
    long long n;
    for (n=1; n<=1000000; n++){
        Pe[n] = (n*(n+1)*(2*n-5) / 3 + 2ll * Pu[n]) % MOD;
        Pe[n] = (Pe[n] - 1ll*n*n) % MOD;
        if (Pe[n] < 0) Pe[n] += MOD;
    }
    //printf("%d %d %d\n",Pe[1],Pe[2],Pe[3]);
}

int SP[1000005],SPk[1000005],SPkk[1000005];

void sume(){
    int n,k,l;
    long long ludak;
    for (n=1; n<=1000000; n++){
        ludak = Pe[n];
        SP[n] = (ludak + SP[n-1]) % MOD;
        ludak = (ludak * n) % MOD;
        SPk[n] = (ludak + SPk[n-1]) % MOD;
        ludak = (ludak * n) % MOD;
        SPkk[n] = (ludak + SPkk[n-1]) % MOD;
    }
}

int resi(int x,int y){
    long long rez;
    if (x > y) swap(x,y);
    x++;
    y++;
    rez = 1ll*x*y % MOD * SP[x-1] % MOD;
    rez -= 1ll*(x+y)*SPk[x-1] % MOD;
    rez += SPkk[x-1];
    rez %= MOD;
    if (rez < 0) rez += MOD;
    return rez;
}

int main(){
    sito();
    totienti();
    pulen();
    peee();
    sume();
    int q,x,y;
    scanf("%d",&q);
    while (q--){
        scanf("%d%d",&x,&y);
        printf("%d\n",resi(x,y));
    }
    return 0;
}
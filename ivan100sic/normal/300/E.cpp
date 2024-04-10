#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool Slozen[10000005];
int A[1000005];
int P[10000005],N;
long long K[10000005];

void sito(){
    int i,j,k;
    j=2;
    for (i=1; i<=450; i++){
        while (Slozen[j]) j++;
        for (k=j*j; k<=10000000; k+=j) Slozen[k] = true;
        j++;
    }
}

void ucitaj(){
    scanf("%d",&N);
    int i;
    for (i=1; i<=N; i++){
        scanf("%d",A+i);
        P[A[i]]++;
    }
    for (i=1; i<=10000000; i++) P[i] += P[i-1];
}

inline int part_sum(int l,int r){
    if (l > 10000000) l = 10000000;
    if (r > 10000000) r = 10000000;
    return P[r] - P[l-1];
}

inline long long suma_div(long long k){
    int i;
    long long r=0;
    for (i=1; k*i<=10000000; i++){
        r += (long long)i * part_sum(k*i , k*(i+1) - 1);
    }
    return r;
}

void nadji_k(){
    int i,j;
    long long k;
    long long z;
    for (i=2; i<=10000000; i++){
        if (!Slozen[i]){
            z=0;
            for (k=i; k<=10000000; k*=i){
                z += suma_div(k);
            }
            K[i] = z;
        }
    }
    //for (i=1; i<=20; i++) printf("%d %lld\n",i,K[i]);
}

long long onaj_matematicar(long long nf,int p){
    long long r,k;
    for (k=p; k<=nf; k*=p){
        r += nf/k;
    }
    return r;
}

void resi(){
    long long l,r,m,o;
    int i;
    bool opstao;
    l=1;
    r=1000000000000000ll;
    while (l<=r){
        m = (l+r)/2;
        //rastavi
        opstao = true;
        for (i=2; i<=10000000; i++){
            if (!Slozen[i]){
                if (K[i] > onaj_matematicar(m,i)){
                    opstao = false;
                    break;
                }
            }
        }
        if (opstao){
            o = m;
            r = m-1;
        } else {
            l = m+1;
        }
    }
    printf("%lld\n",o);
}

int main(){
    sito();
    ucitaj();
    nadji_k();
    resi();
}
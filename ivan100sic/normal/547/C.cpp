#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int NPD[500005];
int Moebius[500005];

void sito(){
    int i,j,k;
    for (i=2; i*i<=500000; i++){
        if (NPD[i]==0){
            NPD[i] = i;
            for (k=i*i; k<=500000; k+=i) if (NPD[k]==0) NPD[k] = i;
        }
    }
    for (int i=1; i<=500000; i++) if (NPD[i]==0) NPD[i] = i;
}

void moebius(){
    Moebius[1] = 1;
    for (int i=2; i<=500000; i++){
        if (NPD[i]==i){
            Moebius[i] = -1;
        } else if ((i/NPD[i])%NPD[i]==0){
            Moebius[i] = 0;
        } else {
            Moebius[i] = Moebius[i/NPD[i]] * Moebius[NPD[i]];
        }
        //if (i<100) printf("%d %d\n",i,Moebius[i]);
    }
}

vector <int> Divs[500005];

int A[200005],N,Q;

void ucitaj(){
    scanf("%d%d",&N,&Q);
    for (int i=1; i<=N; i++) scanf("%d",A+i);
}

void delioci(){
    int i,j,x;
    for (int i=1; i<=N; i++){
        x = A[i];
        if (Divs[x].size()==0){
            for (j=1; j*j<=x; j++) if (x%j==0){
                if (j*j==x){
                    Divs[x].push_back(j);
                } else {
                    Divs[x].push_back(j);
                    Divs[x].push_back(x/j);
                }
            }
        }
    }
}

int DC[500005];

long long konj;
long long n;

void dodaj(int x){
    n++;
    for (int i=0; i<Divs[x].size(); i++){
        konj += Moebius[Divs[x][i]] * (DC[Divs[x][i]]++);
    }
}

void skloni(int x){
    n--;
    for (int i=0; i<Divs[x].size(); i++){
        konj -= Moebius[Divs[x][i]] * (--DC[Divs[x][i]]);
    }
}

bool U[200005];

int main(){
    sito();
    moebius();
    ucitaj();
    delioci();
    for (int i=1; i<=Q; i++){
        int x;
        scanf("%d",&x);
        if (U[x]){
            skloni(A[x]);
        } else {
            dodaj(A[x]);
        }
        printf("%lld\n",/*1ll*n*(n-1)/2 -*/ konj);
        U[x] ^= 1;
    }
    return 0;
}
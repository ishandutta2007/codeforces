#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define N_ 101000
#define pii pair<int,int>
using namespace std;

struct Trie{
    int Ch[2];
    int C;
}T[10100000];

int n, cnt = 1, w[301000];
void Go(int a, int x, int t){
    T[a].C++;
    if(t==-1){
        return;
    }
    int ck=(x>>t)&1;
    if(!T[a].Ch[ck])T[a].Ch[ck]=++cnt;
    Go(T[a].Ch[ck],x,t-1);

}
int Z[100];
long long s=0;
void Calc(int a, int x, int t){
    if(t==-1){
        return;
    }
    int ck=(x>>t)&1, tp = 0;
    if(T[a].Ch[!ck])tp = T[T[a].Ch[!ck]].C;
    if(!ck)Z[t]+=tp, s+=tp;
    else Z[t]-=tp;
    Calc(T[a].Ch[ck],x,t-1);
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        Go(1,w[i],29);
        Calc(1,w[i],29);
    }
    int A=0;
    for(i=0;i<30;i++){
        if(Z[i]>0){
            A|=(1<<i);
            s-=Z[i];
        }
    }
    printf("%lld %d\n",s,A);
}
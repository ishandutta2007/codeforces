#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=1<<20;
int num[mn];
int main(){
    int n;
    scanf("%d",&n);
    if(n==1){
        printf("1");
        return 0;
    }
    int lev=31-__builtin_clz(n);
    memset(num,-1,sizeof(num));
    for(int i=2;i<1<<lev;i++){
        if(i%2==0){
            num[i*2+1]=0;
            if(num[i]!=-1)num[i*2]=num[i]^num[i*2+1]^1;
        }
        else{
            num[i*2]=1;
            if(num[i]!=-1)num[i*2+1]=num[i]^num[i*2]^1;
        }
    }
    int ex=n+1-(1<<lev),eee=0;
    for(int i=(1<<lev)+1;i<(1<<lev+1)-1;i++){
        eee+=num[i];
    }
    if(ex==eee||ex==eee+1)printf("1");
    else printf("0");
}
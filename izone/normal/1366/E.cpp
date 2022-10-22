#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int n, K;
int A[201000], B[201000], Z[201000], ST[201000];
map<int,int>Map;
int main(){
    int i;
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }
    for(i=1;i<=K;i++){
        scanf("%d",&B[i]);
    }
    for(i=n;i>=1;i--){
        Z[i]=A[i];
        if(i!=n)Z[i]=min(Z[i],Z[i+1]);
        Map[Z[i]]++;
    }
    long long res=1,Mod=998244353;
    for(i=2;i<=K;i++){
        res=res*Map[B[i]]%Mod;
    }
    if(B[1]!=Z[1]){
        res=0;
    }
    printf("%lld\n",res);
}
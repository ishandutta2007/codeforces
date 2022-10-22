#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const ll mod=998244353;
const int mn=3e5+10;
int a[mn],b[mn];
vector<int>nums[mn];
int bes[2][mn],ind[mn];
int main(){
    int n,m,s,e;
    scanf("%d%d%d%d",&n,&m,&s,&e);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=m;i++){
        scanf("%d",b+i);
        nums[b[i]].push_back(i);
    }
    int ans=0;
    for(int i=1;i<=s/e;i++){
        memcpy(bes[0],bes[1],sizeof(bes[0]));
        memset(bes[1],0x3f,sizeof(bes[1]));
        memset(ind,0,sizeof(ind));
        for(int j=1;j<=n;j++)bes[0][j]=min(bes[0][j],bes[0][j-1]);
        for(int j=n;j>=1;j--){
            while(ind[a[j]]<nums[a[j]].size()&&nums[a[j]][ind[a[j]]]<=bes[0][j-1])ind[a[j]]++;
            if(ind[a[j]]<nums[a[j]].size())bes[1][j]=nums[a[j]][ind[a[j]]];
            if(j+bes[1][j]+e*i<=s)ans=i;
        }
    }
    printf("%d",ans);
}
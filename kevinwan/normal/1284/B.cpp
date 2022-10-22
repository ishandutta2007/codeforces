#include<bits/stdc++.h>
using namespace std;
#define mid (l+r>>1)
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=1e6+10;
vector<int>v[mn];
int num[mn];
bool inc[mn];
int lo[mn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int l;
        scanf("%d",&l);
        v[i].resize(l);
        for(int j=0;j<l;j++)scanf("%d",v[i].begin()+j);
        for(int j=0;j<l-1;j++)if(v[i][j]<v[i][j+1]){
            inc[i]=1;
        }
        if(!inc[i]) {
            num[v[i][0]]++;
            lo[i] = v[i][l - 1];
        }
    }
    for(int i=1;i<mn;i++)num[i]+=num[i-1];
    ll ans=1LL*n*n;
    for(int i=0;i<n;i++){
        if(!inc[i]){
            ans-=num[lo[i]];
        }
    }
    printf("%lld",ans);
}
#include<bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=2e5+10;
unordered_map<int,int>m[mn];
int bit[mn];
void up(int a,int b){for(;a<mn;a+=a&-a)bit[a]+=b;}
int qu(int a){int b=0;for(;a;a-=a&-a)b+=bit[a];return b;}
int a[mn],oc[mn],nxt[mn];
int ans[mn];
vector<int> nd[mn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)nxt[i]=n+1;
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        if(!oc[a[i]])up(i,1);
        else nxt[oc[a[i]]]=i;
        oc[a[i]]=i;
    }
    for(int i=1;i<=n;i++)nd[0].push_back(i);
    for(int i=0;i<n;i++){
        if(i)up(i,-1),up(nxt[i],1);
        for(int x:nd[i]){
            ans[x]++;
            int cur=0,cum=0;
            for(int j=1<<17;j;j>>=1){
                if(cur+j>n)continue;
                if(cum+bit[cur+j]<=x)cum+=bit[cur+=j];
            }
            nd[cur].push_back(x);
        }
    }
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}
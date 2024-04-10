#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<int,ll>pil;
typedef pair<ll,ll>pll;
const int mn=2e5+10;
const ll mod=998244353;
vector<pii>ans;
int a[mn],num[mn],mo[mn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)scanf("%d",a+i),num[a[i]]++;
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    for(int i=1;i<=n;i++)mo[i]=i;
    for(int i=1;i<=n;i++)if(!num[i])pq.push({mo[i],i});
    for(int i=n-2;i>=0;i--){
        int x=pq.top().first,y=pq.top().second;
        pq.pop();
        int p=a[i];
        ans.push_back({p,y});
        mo[p]=max(mo[p],x);
        num[p]--;
        if(!num[p])pq.push({mo[p],p});
    }
    printf("%d\n",pq.top().second);
    for(pii p:ans)printf("%d %d\n",p.first,p.second);
}
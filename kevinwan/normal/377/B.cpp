#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int mn=2e5+10;
int n,m,s;
pii vir[mn];
struct three{
    int b,c,i;
    bool operator<(three ot){return b<ot.b;}
};
three st[mn];
int sol[mn];
bool solve(int x){
    ll ans=0;
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    int i,j=n-1;
    for(i=m-1;i>=0;i-=x){
        while(j>=0&&st[j].b>=vir[i].first)pq.push({st[j].c,st[j].i}),j--;
        if(!pq.size())return 0;
        ans+=pq.top().first;
        for(int k=max(i-x+1,0);k<=i;k++)sol[vir[k].second]=pq.top().second+1;
        pq.pop();
    }
    return ans<=s;
}
int main()
{
    int i;
    scanf("%d%d%d",&n,&m,&s);
    for(i=0;i<m;i++)scanf("%d",&vir[i].first),vir[i].second=i;
    sort(vir,vir+m);
    for(i=0;i<n;i++)scanf("%d",&st[i].b);
    for(i=0;i<n;i++)scanf("%d",&st[i].c),st[i].i=i;
    sort(st,st+n);
    int cur=0;
    for(i=1<<18;i;i>>=1){
        if(!solve(cur+i))cur+=i;
    }
    cur++;
    if(solve(cur)){
        printf("YES\n");
        for(i=0;i<m;i++)printf("%d ",sol[i]);
    }
    else{
        printf("NO");
    }
}
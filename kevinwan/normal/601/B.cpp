#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e5+10;
ll a[mn];
struct comp{
    bool operator()(int l,int r){return a[l]<a[r];}
};
int l[mn],r[mn];
ll ans[mn];
int main()
{
    int n,q,i;
    scanf("%d%d",&n,&q);
    for(i=0;i<n;i++){
        scanf("%lld",a+i);
    }
    for(i=0;i<n-1;i++){
        a[i]=abs(a[i]-a[i+1]);
    }
    for(i=0;i<q;i++)scanf("%d%d",l+i,r+i),r[i]-=2,l[i]--;
    priority_queue<int,vector<int>,comp>pq;
    set<int> s;
    s.insert(-1);
    s.insert(n-1);
    for(i=0;i<n-1;i++)pq.push(i);
    while(pq.size()){
        int x=pq.top();
        pq.pop();
        auto it=s.lower_bound(x);
        int hi=*it,lo=*(--it);
        for(i=0;i<q;i++){
            if(x>r[i]||x<l[i])continue;
            ans[i]+=a[x]*(min(hi,r[i]+1)-x)*(x-max(lo,l[i]-1));

        }
        s.insert(x);
    }
    for(i=0;i<q;i++)printf("%lld\n",ans[i]);
}
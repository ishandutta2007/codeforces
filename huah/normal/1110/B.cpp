#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[100001];
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    scanf("%d",&a[1]);
    for(int i=2;i<=n;i++) scanf("%d",&a[i]),q.push(a[i]-a[i-1]);
    int t=n-k;
    long long ans=n;
    while(t--)
        ans+=-1+q.top(),q.pop();
    cout<<ans<<endl;
}
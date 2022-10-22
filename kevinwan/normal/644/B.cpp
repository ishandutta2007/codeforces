#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
const int mn=2e5+10;
ll t[mn],d[mn],ans[mn];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,b,i;
    cin>>n>>b;
    for(i=0;i<n;i++)cin>>t[i]>>d[i];
    queue<ll>q;
    ll lt=0;
    for(i=0;i<n;i++){
        while(q.size()&&q.front()<=t[i])q.pop();
        if(!q.size())lt=t[i];
        if(q.size()>b)ans[i]=-1;
        else{
            ans[i]=(lt+=d[i]);
            q.push(lt);
        }
    }
    for(i=0;i<n;i++)printf("%lld ",ans[i]);
}
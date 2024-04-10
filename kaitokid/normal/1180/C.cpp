#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,mx[100005],a[100005],q;
deque<ll>dq;
int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>q;
    ll tp=0;
    for(int i=0;i<n;i++)
        {cin>>a[i];tp=max(tp,a[i]);mx[i]=tp;dq.push_back(a[i]);}
        for(int i=0;i<n-1;i++)
        {
            int d1=*dq.begin();
            dq.pop_front();
            int d2=*dq.begin();
            dq.pop_front();
            dq.push_front(max(d1,d2));
            dq.push_back(min(d1,d2));
        }
ll x;

while(q--)
{
    cin>>x;
    if(x<n){cout<<mx[x-1]<<" "<<a[x]<<endl;continue;}
    x-=n;
    cout<<dq[0]<<" "<<dq[x%(n-1)+1]<<endl;
}
return 0;
}
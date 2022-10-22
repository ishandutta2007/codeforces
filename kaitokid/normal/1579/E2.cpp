#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200009],n;
int bt[200009];
int fr[200009];
int cal(int x)
{
    int res=0;
    while(x>0)
    {
        res+=bt[x];
        x-=(x&(-x));

    }
    return res;
}
void add(int x)
{
    while(x<=n)
    {
        bt[x]++;
        x+=(x&(-x));
    }
}
int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--)
{
cin>>n;
vector<int> hs;
for(int i=0;i<n;i++)
    {cin>>a[i];hs.push_back(a[i]);bt[i+1]=fr[i+1]=0;}

sort(hs.begin(),hs.end());
for(int i=0;i<n;i++)
        a[i]=lower_bound(hs.begin(),hs.end(),a[i])-hs.begin()+1;

    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ll r=cal(a[i]-1);
        r=min(r,i-r-fr[a[i]]);
        ans+=r;
        fr[a[i]]++;
        add(a[i]);
    }
    cout<<ans<<endl;
}
return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[300009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
int t;
cin>>t;
while(t--)
{int n;
cin>>n;
set<int>st;
int x;
cin>>a[0];
st.insert(a[0]);
bool ans=true;
for(int i=1;i<n;i++)
{
    cin>>a[i];
    int mn=min(a[i],a[i-1]);
    int mx=max(a[i],a[i-1]);
    set<int>::iterator it=st.upper_bound(mn);
    if((it!=st.end())&&((*it)<mx))ans=false;
    st.insert(a[i]);
}
if(ans)cout<<"YES\n";
else cout<<"NO\n";
}
    return 0;
}
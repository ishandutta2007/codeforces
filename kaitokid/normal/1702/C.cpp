#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int,int>st,en;
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--)
{
int n,k;
cin>>n>>k;
st.clear();
en.clear();
for(int i=1;i<=n;i++)
{
    int x;
    cin>>x;
    en[x]=i;
    if(st[x]==0)st[x]=i;
}
while(k--)
{
    int x,y;
    cin>>x>>y;
    if((st[x]==0)||(st[y]==0)){cout<<"NO"<<endl;continue;}
    if(st[x]<en[y]){cout<<"YES"<<endl;continue;}
    cout<<"NO"<<endl;
}
}

return 0;
}
#include <bits/stdc++.h>
#define pb push_back
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main()
{
    io
    long n,x,i,xo=0;
    vl v;
    cin>>n>>x;
    if(n==1) {cout<<"YES\n"<<x;return 0;}
    if(n==2 && x==0) {cout<<"NO";return 0;}
    for(i=0;i<n-1;++i)
    v.pb(i),xo^=i;
    v[0]+=(1<<18);
    if((xo^x)!=0)
    v.pb((xo^x)+(1<<18));
    else {v[1]+=(1<<19);v.pb((xo^x)+(1<<19)+(1<<18));}
    cout<<"YES\n";
    for(i=0;i<v.size();++i)
    cout<<v[i]<<" ";
    return 0;
}
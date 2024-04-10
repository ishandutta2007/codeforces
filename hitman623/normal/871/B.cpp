#include <bits/stdc++.h>
#define pb push_back
#define pll pair < int , int >
#define vll vector < pll >
#define ml map < int , int >
#define mll map < pll , int >
#define x first
#define y second
#define vl vector < int >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int p[5005],q[5005],pp[5005],qq[5005],i,j,l,n,ans=0;
int query(int a,int b)
{
    int x;
    cout<<"? "<<a<<" "<<b<<endl;
    fflush(stdout);
    cin>>x;
    return x;
}
int check(int x)
{
    int i;
    for(i=0;i<n;++i)
    {
        q[i]=(qq[i]^x);
        if(q[i]>=n) return 0;
    }
    for(i=0;i<n;++i)
    {
        p[i]=(pp[i]^q[0]);
        if(p[i]>=n) return 0;
    }
    for(i=0;i<n;++i)
    if(p[q[i]]!=i) return 0;
    return 1;
}
int main()
{
    io
    int i;
    cin>>n;
    for(i=0;i<n;++i)
    pp[i]=query(i,0);
    for(i=0;i<n;++i)
    qq[i]=query(0,i);
    for(i=0;i<n;++i)
    if(check(i)) ans++,l=i;
    check(l);
    cout<<"!\n"<<ans<<"\n";
    for(i=0;i<n;++i)
    cout<<p[i]<<" ";
    return 0;
}
#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define x first
#define y second
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    io
    long n,k,a,b,c,d,v[1002],l=3,i;
    cin>>n>>k;
    cin>>a>>b>>c>>d;
    if(n==4) {cout<<-1;exit(0);}
    v[1]=a;
    v[2]=d;
    v[n]=c;
    v[n-1]=b;
    for(i=1;i<=n;++i)
    if(i!=a && i!=b && i!=c && i!=d)
    v[l++]=i;
    if(k<n+1) {cout<<-1;exit(0);}
    for(i=1;i<n-1;++i)
    cout<<v[i]<<" ";
    cout<<v[n]<<" "<<v[n-1]<<endl;
    for(i=n;i>2;--i)
    cout<<v[i]<<" ";
    cout<<v[1]<<" "<<v[2]<<endl;
    return 0;
}
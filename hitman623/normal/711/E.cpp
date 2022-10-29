#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long h=1e6+3,hh=h-1;
long po(long a,long b)
{
    if(a==0) return 0;
    if(a==1 || b==0) return 1;
    long m=po(a,b/2);
    m=(m*m)%h;
    if(b&1) return (m*a)%h;
    return m;
}
int main()
{
    io
    long n,k,a=1,b=1,i;
    cin>>n>>k;
    if(n<=60 && (1LL<<n)<k) {cout<<"1 1";exit(0);}
    if(k>po(2,n%(h-1)))
    {
        k--;
        long t=((n%hh)*(k%hh))%hh;
        while(k>0)
        {
            t=(t-k/2+hh)%hh;
            k/=2;
        }
        a=po(2,t);
        cout<<a<<" "<<a;
        exit(0);
    }
    for(i=1;i<k;++i)
    {
        int c=0,j=i;
        while(j%2==0)
        j/=2,c++;
        a=(a*(po(2,(n-c)%(h-1))-j))%h;
        b=(b*po(2,(n-c)%(h-1)))%h;
    }
    cout<<(b-a+h)%h<<" "<<b;
    return 0;
}
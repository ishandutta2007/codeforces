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
int main()
{
    io
    long n,m,k,i,j,a[101][101],ans=0,ans2=0,l,cur;
    cin>>n>>m>>k;
    for(i=0;i<n;++i)
    for(j=0;j<m;++j)
    cin>>a[i][j];
    for(i=0;i<m;++i)
    {
        long m=-1,mm,cur=0;
        for(j=0;j<n;++j)
        {
            long s=0;
            for(l=j;l<min(n,j+k);++l)
            s+=a[l][i];
            if(s>m)
            m=s,mm=cur;
            cur+=a[j][i];
        }
        ans+=m;
        ans2+=mm;
    }
    cout<<ans<<" "<<ans2;
    return 0;
}
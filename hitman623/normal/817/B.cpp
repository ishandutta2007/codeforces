#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < long >
#define rep(i,n) for(int i=0;i<n;i++)
#define fd(i,a,b) for(int i=a; i>=b; i--)
using namespace std;
int main()
{
    long n,a[100005],i,c=1,j;
    cin>>n;
    for(i=0;i<n;++i)
    cin>>a[i];
    sort(a,a+n);
    for(j=3;j<n;++j)
    if(a[j]==a[j-1]) c++;
    else break;
    if(a[2]==a[1] && a[1]==a[0]) cout<<((c+2)*(c+1)*(c))/6;
    else if(a[2]==a[1]) cout<<((c+1)*(c))/2;
    else cout<<c;
    return 0;
}
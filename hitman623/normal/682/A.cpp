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
    long n,m,i,x,m1[5]={0},m2[5]={0};
    cin>>n>>m;
    for(i=1;i<=n;++i)
    m1[i%5]++;
    for(i=1;i<=m;++i)
    m2[i%5]++;
    cout<<(m1[0]*m2[0]+m1[1]*m2[4]+m1[2]*m2[3]+m1[3]*m2[2]+m1[4]*m2[1]);
    return 0;
}
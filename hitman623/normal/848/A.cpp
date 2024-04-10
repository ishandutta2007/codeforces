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
    long k,cur=0,i,j;
    cin>>k;
    if(k==0) {cout<<"ab";return 0;}
    u:
    for(i=1;(i*(i+1))/2<=k;++i);
    for(j=1;j<=i;++j)
    cout<<(char)('a'+cur);
    k-=(i*(i-1))/2;
    cur++;
    if(k>=3) goto u;
    if(k==1)
    {
        cout<<(char)('a'+cur)<<(char)('a'+cur);
    }
    else if(k==2)
    {
        cout<<(char)('a'+cur)<<(char)('a'+cur)<<(char)('a'+cur+1)<<(char)('a'+cur+1);
    }
    return 0;
}
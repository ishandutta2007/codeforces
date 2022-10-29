#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < long >
using namespace std;

int main()
{
    long l[4],s[4],r[4],p[4],i;
    for(i=0;i<4;++i)
    cin>>l[i]>>s[i]>>r[i]>>p[i];
    for(i=0;i<4;++i)
    if(p[i]==1)
    {
        if(l[i]!=0 || s[i]!=0 || r[i]!=0 || l[(i+1)%4]==1 || s[(i+2)%4]==1 || r[(i+3)%4]==1)
        {cout<<"YES";exit(0);}
    }
    cout<<"NO";
    return 0;
}
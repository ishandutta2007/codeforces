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
using namespace std;

int main()
{
    long n,m,i,f,j;
    string s[101];
    char ch;
    cin>>n>>m;
    for(i=0;i<n;++i)
    cin>>s[i];
    if(n%3==0)
    {
        ch=s[0][0];
        f=1;
        for(i=0;i<n/3;++i)
        for(j=0;j<m;++j)
        if(s[i][j]!=ch) {f=0;break;}
        if(f==0) goto pp;
        ch=s[n/3][0];
        for(i=n/3;i<2*(n/3);++i)
        for(j=0;j<m;++j)
        if(s[i][j]!=ch) {f=0;break;}
        if(f==0) goto pp;
        ch=s[(2*n)/3][0];
        for(i=2*(n/3);i<n;++i)
        for(j=0;j<m;++j)
        if(s[i][j]!=ch) {f=0;break;}
        if(f==0) goto pp;
        if(f && s[0][0]!=s[n/3][0] && s[n/3][0]!=s[n-1][0] && s[n-1][0]!=s[0][0]) {cout<<"YES";exit(0);}
    }
    pp:
    if(m%3==0)
    {
        ch=s[0][0];
        f=1;
        for(i=0;i<n;++i)
        for(j=0;j<m/3;++j)
        if(s[i][j]!=ch) {f=0;break;}
        if(f==0) goto ppp;
        ch=s[0][m/3];
        for(i=0;i<n;++i)
        for(j=m/3;j<2*(m/3);++j)
        if(s[i][j]!=ch) {f=0;break;}
        if(f==0) goto ppp;
        ch=s[0][(2*m)/3];
        for(i=0;i<n;++i)
        for(j=2*m/3;j<m;++j)
        if(s[i][j]!=ch) {f=0;break;}
        if(f==0) goto ppp;
        if(f && s[0][0]!=s[0][m/3] && s[0][m/3]!=s[0][m-1] && s[0][m-1]!=s[0][0]) {cout<<"YES";exit(0);}
    }
    ppp:
    cout<<"NO";
    return 0;
}
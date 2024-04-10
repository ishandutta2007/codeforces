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
    long i;
    map < char , char > v;
    string a,b,c;
    cin>>a>>b;
    for(i=0;i<26;++i)
    v[a[i]]=b[i];
    cin>>c;
    for(i=0;i<c.length();++i)
    if(isalpha(c[i]))
    {
        if(isupper(c[i]))
        cout<<(char)toupper(v[tolower(c[i])]);
        else cout<<v[c[i]];
    }
    else cout<<c[i];
    return 0;
}
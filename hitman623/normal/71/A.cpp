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
    long n,i;
    string s;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>s;
        if(s.size()>10)
        cout<<s[0]<<s.size()-2<<s[s.size()-1]<<endl;
        else cout<<s<<endl;
    }
    return 0;
}
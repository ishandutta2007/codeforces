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
    set<string>ss;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>s;
        if(ss.find(s)!=ss.end())
            cout<<"YES";
        else cout<<"NO";
        ss.insert(s);
        cout<<"\n";
    }
    return 0;
}
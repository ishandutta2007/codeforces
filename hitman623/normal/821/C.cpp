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
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    io
    long n,i,x,c=1,cnt=0,f=0;
    string s;
    vl v;
    cin>>n;
    for(i=0;i<2*n;++i)
    {
        cin>>s;
        if(s[0]=='a')
        {
            cin>>x;
            v.pb(x);
        }
        else
        {
            if(v[v.size()-1]!=c)
            {
                if(v.size()>f)
                cnt++,f=v.size();
                f--;
            }
            v.erase(v.end()-1);
            c++;
        }
    }
    cout<<cnt;
    return 0;
}
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
    string s;
    long n,k,i,c[26],cnt=0,v[26]={0};
    cin>>n>>k>>s;
    for(i=0;i<n;++i)
    c[s[i]-'A']=i;
    for(i=0;i<n;++i)
    {
        if(v[s[i]-'A']==0)
        cnt++,v[s[i]-'A']=1;
        if(cnt>k) {cout<<"YES";exit(0);}
        if(c[s[i]-'A']==i)
        cnt--;
    }
    cout<<"NO";
    return 0;
}
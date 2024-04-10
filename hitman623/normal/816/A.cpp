#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
long check(long hh,long mm)
{
    if(hh/10==mm%10 && hh%10==mm/10) return 1;
    return 0;
}
int main()
{
    io
    string s;
    cin>>s;
    long hh=(s[0]-'0')*10+s[1]-'0',mm=(s[3]-'0')*10+(s[4]-'0'),ans=0;
    if(!check(hh,mm))
    while(1)
    {
        ans++;
       hh=(hh+(mm+1)/60)%24;
       mm=(mm+1)%60;
       if(check(hh,mm)) break;
    }
    cout<<ans;
    return 0;
}
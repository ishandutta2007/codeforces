#include <bits/stdc++.h>
#define pb push_back
#define vl vector < int >
#define pll pair < int , int >
#define vll vector < pll >
#define x first
#define y second
#define ml map < int , int >
#define mll map < pll , int >
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
int main()
{
    io
    string a,b;
    cin>>a>>b;
    map < string , int > mp;
    mp["monday"]=0;
    mp["tuesday"]=1;
    mp["wednesday"]=2;
    mp["thursday"]=3;
    mp["friday"]=4;
    mp["saturday"]=5;
    mp["sunday"]=6;
    if((mp[a]+31)%7==mp[b] || (mp[a]+28)%7==mp[b] || (mp[a]+30)%7==mp[b])
        cout<<"YES";
    else cout<<"NO";
    return 0;
}
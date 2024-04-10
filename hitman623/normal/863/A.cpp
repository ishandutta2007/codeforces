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
    long i,j;
    string x;
    cin>>x;
    for(i=0;i<=x.size()+1;++i)
    {
        string temp=x;
        reverse(temp.begin(),temp.end());
        for(j=0;j<i;++j)
        temp+='0';
        string t=temp;
        reverse(temp.begin(),temp.end());
        if(t==temp) {cout<<"YES";return 0;}
    }
    cout<<"NO";
    return 0;
}
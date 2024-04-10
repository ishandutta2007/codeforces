/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

char mx(char a,char b,char c,char d)
{
    if(a==c || a==d) return a;
    else return b;
}

void solve()
{
    string s;
    cin>>s;

    int n=s.size();
    char x;

    if(n<=3){ cout<<s[0]<<endl; return; }

    vector<char> pal;
    int i=0,j=n-1;
    while(1)
    {
        x=mx(s[i],s[i+1],s[j-1],s[j]);
        pal.push_back(x);
        i+=2; j-=2;
        if(j-i<3) break;
    }

    for(int k=0;k<pal.size();k++) cout<<pal[k];
    if(i<=j) cout<<s[i];
    for(int k=(pal.size()-1);k>=0;k--) cout<<pal[k];
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k;
    cin>>n>>k;

    string s;
    cin>>s;

    for(int i=0; i<n; i++)
    {
        if(s[i]>s[0]) { s=s.substr(0, i); break; }
    }

    n = s.size();
    for(int i=0; i<n; i++)
    {
        if(s[i]<s[0]) continue;
        int j=0;
        while(1)
        {
            if(j==i || j+i==n) break;
            if(s[j]!=s[i+j]) break;
            j++;
        }
        if((j+i)==n) break;
        if(j==i) { i*=2; continue; }
        if(s[j]>s[i+j]) { i=(i+j); continue; }
        s = s.substr(0, i);
        break;
    }
    //cout<<s<<endl;
    
    while(s.size()!=1 && *s.rbegin()==s[0]) s.pop_back();
    n=s.size();

    n=s.size();
    for(int i=0; i<k; i++)
    {
        cout<<s[i%n];
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
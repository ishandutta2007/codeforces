/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

char nz(int i)
{
    char x = '0'+i;
    return x;
}

void solve()
{
    string a, s;
    cin>>a>>s;

    reverse(a.begin(), a.end());
    reverse(s.begin(), s.end());

    int n = a.size();
    int m = s.size();

    if(n>m) { cout<<-1<<endl; return; }

    string b;

    int j=0;
    for(int i=0; i<n; i++)
    {
        if(j>=m) { cout<<-1<<endl; return; }

        int x = (s[j++]-'0');
        int y = (a[i]-'0');
        if(x>=y) { b.push_back(nz(x-y)); continue; }

        if(j>=m) { cout<<-1<<endl; return; }

        x+=((s[j++]-'0')*10);
        int w = x-y;

        if(w>9 || w<0) { cout<<-1<<endl; return; }
        b.push_back(nz(x-y));
    }

    while(j!=m) b.push_back(s[j++]);

    reverse(b.begin(), b.end());
    int done=0;

    n = b.size();
    for(int i=0; i<n; i++)
    {
        char x = b[i];
        if(done==0 && x=='0') continue;
        done=1;
        cout<<x;
    }

    if(done==0) cout<<-1;
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
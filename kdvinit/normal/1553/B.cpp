/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    string s, t; cin>>s>>t;
    int n = s.size();
    int m = t.size();

    for(int i=0; i<m; i++)
    {
        int l = i+1;
        int r = m-i;
        if(l<=r)
        {
            int k = 2*l-1, flag=1;
            for(int j=0; j<k; j++)
            {
                if(t[j]!=t[k-1-j]) { flag=0; break; }
            }
            if(flag==0) continue;
            string tmp = t.substr(m-r, r);
            reverse(tmp.begin(), tmp.end());
            int x = s.find(tmp);
            if(x>=0 && x<n) { cout<<"YES"<<endl; return; }
        }
        else
        {
            int k = 2*r-1, flag=1;
            int base = i-r+1;
            for(int j=0; j<k; j++)
            {
                if(t[base+j]!=t[base+k-1-j]) { flag=0; break; }
            }
            if(flag==0) continue;
            string tmp = t.substr(0, l);
            int x = s.find(tmp);
            if(x>=0 && x<n) { cout<<"YES"<<endl; return; }
        }
    }
    cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int val(string s)
{
    int ans = 0;
    for(int i=0; i<s.size(); i++)
    {
        ans*=30;
        int x = s[i]-'a'+1;
        ans+=x;
    }
    return ans;
}

bool solve()
{
    int n;
    cin>>n;

    string a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    map<string, int> mp22, mp32, mp3;

    for(int i=1; i<=n; i++)
    {
        string rev = a[i];
        reverse(rev.begin(), rev.end());
        
        if(a[i]==rev) return true;

        if(a[i].size()==2)
        {
            if(mp22[rev]==1 || mp32[rev]==1) return true;
            mp22[a[i]]=1;
        }
        
        if(a[i].size()==3)
        {
            string f2 = a[i].substr(0, 2);
            string l2 = a[i].substr(1, 2);
            reverse(l2.begin(), l2.end());

            if(mp3[rev]) return true;
            if(mp22[l2]) return true;

            mp3[a[i]]=1;
            mp32[f2]=1;
        }
    }

    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--)
    {
        if(solve()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
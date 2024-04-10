/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

string Trans(string s, string ord)
{
    string t=s;

    int n = s.size();
    int m = ord.size();
    int done[26]={0};

    for(int i=0; i<m; i++)
    {
        done[ord[i]-'a']=1;
        for(int i=0; i<n; i++)
        {
            if(done[s[i]-'a']==1) continue;
            t+=s[i];
        }
    }

    return t;
}

void solve()
{
    string s;
    cin>>s;

    int n = s.size();

    int freq[26]={0};
    string ord;

    for(int i=n-1; i>=0; i--)
    {
        if(freq[s[i]-'a']==0) ord+=s[i];
        freq[s[i]-'a']++;
    }

    reverse(ord.begin(), ord.end());

    int cnt[26]={0};

    int m = ord.size();
    for(int i=0; i<m; i++)
    {
        int y = ord[i]-'a';
        if(freq[y]%(i+1)!=0) { cout<<-1<<endl; return; }
        cnt[y] = freq[y]/(i+1);
    }

    int tot = m;

    string org;
    for(int i=0; i<n; i++)
    {
        org+=s[i];
        int y = s[i]-'a';
        cnt[y]--;
        if(cnt[y]==0) tot--;
        if(cnt[y]<0) { cout<<-1<<endl; return; }
        if(tot==00)  break;
    }

    string t = Trans(org, ord);

    if(t==s) cout<<org<<" "<<ord<<endl;
    else cout<<-1<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
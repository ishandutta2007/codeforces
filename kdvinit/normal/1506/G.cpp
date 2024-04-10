/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    string s;
    cin>>s;

    int n = s.size();

    int freq[26]={0};
    for(int i=0; i<n; i++)
    {
        freq[s[i]-'a']++;
    }

    int used[26]={0};
    vector<char> ans;

    for(int i=0; i<n; i++)
    {
        if(used[s[i]-'a']==1) continue;

        int j=i;
        char mx=s[i];
        int mxi=i;

        while(1)
        {
            if(freq[s[j]-'a']==1 && used[s[j]-'a']==0) break;
            if(used[s[j]-'a']==1) { j++; continue; }
            freq[s[j]-'a']--;
            if(s[j]>mx) { mx=s[j]; mxi=j; }
            j++;
        }

        if(s[j]>mx) { mx=s[j]; mxi=j; }

        ans.push_back(mx);

        for(int k=mxi+1; k<j; k++)
        {
            freq[s[k]-'a']++;
        }

        //cout<<i<<" "<<s[i]<<" "<<mx<<" "<<mxi<<endl;

        used[s[mxi]-'a']=1;
        i=mxi;
    }

    for(int i=0; i<ans.size(); i++) cout<<ans[i];
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
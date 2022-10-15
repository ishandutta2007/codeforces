/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool solve()
{
    string s;
    cin>>s;

    int n = s.size();

    int cnt[3]={0};
    for(int i=0; i<n; i++) cnt[s[i]-'A']++;

    return (cnt[1]==(cnt[0]+cnt[2]));
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
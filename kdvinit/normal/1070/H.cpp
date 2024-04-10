/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    map<string, int> mp1, mp2;
    string a[n+1];

    for(int i=1; i<=n; i++)
    {
        string s; cin>>s;
        a[i]=s;
        map<string, int> mp3;

        int m = s.size();
        for(int j=0; j<m; j++)
        {
            for(int l=1; j+l-1<m; l++)
            {
                string tmp = s.substr(j, l);
                if(mp3[tmp]==1) continue;
                mp1[tmp]++;
                mp2[tmp]=i;
                mp3[tmp]=1;
            }
        }
    }

    int q;
    cin>>q;

    while(q--)
    {
        string p; cin>>p;
        int x = mp1[p];
        cout<<x<<" ";
        if(x==0) cout<<"-"<<endl;
        else cout<<a[mp2[p]]<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
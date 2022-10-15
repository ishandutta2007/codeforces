/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool solve()
{
    int n; cin>>n;
    string s, t, ss, st;
    cin>>s>>t;

    ss=s;   st=t;
    sort(ss.begin(), ss.end());
    sort(st.begin(), st.end());

    if(ss!=st) return false;

    int mp[3][n+5][3];
    int c[3]={0};

    for(char x: s)
    {
        int y=x-'a';
        c[y]++;
        for(int j=0; j<3; j++) mp[y][c[y]][j]=c[j];
    }

    for(int j=0; j<3; j++) c[j]=0;

    for(char x: t)
    {
        int y=x-'a';
        c[y]++;

        if(x=='a')
        {
            if(mp[0][c[0]][1]>c[1]) return false;
            if(mp[0][c[0]][2]!=c[2]) return false;
        }
        if(x=='b')
        {
            if(mp[1][c[1]][0]<c[0]) return false;
            if(mp[1][c[1]][2]>c[2]) return false;
        }
        if(x=='c')
        {
            if(mp[2][c[2]][0]!=c[0]) return false;
            if(mp[2][c[2]][1]<c[1]) return false;
        }
    }

    return true;
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
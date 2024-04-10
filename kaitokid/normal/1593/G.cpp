#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int fr[1000009][2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;
        int n=s.size();
        for(int i=1;i<=n;i++)
        {
            fr[i][0]=fr[i-1][0];
            fr[i][1]=fr[i-1][1];
            if(s[i-1]==')'||s[i-1]=='(')fr[i][(i%2)]++;
        }
        int q;
        cin>>q;
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            int u=fr[r][0]-fr[l-1][0];
            int v=fr[r][1]-fr[l-1][1];
            cout<<abs(u-v)<<endl;
        }
    }
    return 0;
}
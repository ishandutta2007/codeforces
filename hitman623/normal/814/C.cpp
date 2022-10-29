#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
long n,q,m,i,j,k,f[30][1503]={0},ans[30][1503]={0},cnt=0;
int main()
{
    io
    string s;
    char c;
    cin>>n;
    cin>>s;
    for(j=0;j<26;++j)
    {
        for(i=0;i<n;++i)
        {
            cnt=0;
            for(k=i;k<n;++k)
            {
                if(s[k]=='a'+j)
                cnt++;
                ans[j][k-i+1-cnt]=max(ans[j][k-i+1-cnt],k-i+1);
            }
        }
    }
    for(i=0;i<26;++i)
    for(j=1;j<=n;++j)
    ans[i][j]=max(ans[i][j],ans[i][j-1]);
    cin>>q;
    while(q--)
    {
        cin>>m>>c;
        cout<<ans[c-'a'][m]<<endl;
    }
    return 0;
}
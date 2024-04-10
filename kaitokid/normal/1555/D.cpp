#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum[7][2000009],n,m;
string s;
void go(string u,int z)
{
    sum[z][0]=0;
    for(int i=0;i<n;i++)
    {
        if(i>0)sum[z][i]=sum[z][i-1];
        if(s[i]!=u[(i%3)])sum[z][i]++;
    }

}
int main()
{
    cin>>n>>m>>s;
    go("abc",0);
    go("acb",1);
    go("bac",2);
    go("bca",3);
    go("cab",4);
    go("cba",5);
    for(int i=0;i<m;i++)
    {
        ll l,r,ans=n+10;
        cin>>l>>r;
        l--,r--;
        for(int j=0;j<6;j++)ans=min(ans,sum[j][r]-sum[j][l-1]);
        cout<<ans<<endl;
    }




    return 0;
}
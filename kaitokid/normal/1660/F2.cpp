#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int bit[500009][4],n;
void add(int x,int id)
{
    while(x<=2*n+6)
    {
        bit[x][id]++;
        x+=(x&(-x));
    }
}
ll cal(int x,int id)
{
    ll res=0;
    while(x>0)
    {
        res+=bit[x][id];
        x-=(x&(-x));
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>n>>s;
        for(int i=0;i<=2*n+6;i++)bit[i][0]=bit[i][1]=bit[i][2]=0;
        ll ans=0;
        int u=n+1;

        add(u,(u%3));
        for(int i=0;i<n;i++)
        {
            if(s[i]=='+')u--;
            else u++;
          ans+=cal(u,(u%3));
          add(u,(u%3));

        }
       cout<<ans<<endl;

    }
    return 0;
}
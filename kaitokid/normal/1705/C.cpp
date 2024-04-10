#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll num[59],l[59],r[59];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m,q;
        string s;
        cin>>n>>m>>q;
        cin>>s;
        num[0]=s.size();
        for(int i=1;i<=m;i++)
        {
            cin>>l[i]>>r[i];
            num[i]=num[i-1]+r[i]-l[i]+1;
        }
        while(q--)
        {
            ll k;
            cin>>k;
            for(int i=m;i>0;i--)

                if(k>num[i-1])k=l[i]+k-num[i-1]-1;
            cout<<s[k-1]<<endl;
        }
    }

    return 0;
}
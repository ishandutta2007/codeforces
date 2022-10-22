#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
string s;
int ch(int x)
{
    if(x<0||x>n-3)return 0;
    if(s[x]=='a'&&s[x+1]=='b'&& s[x+2]=='c')return 1;
    return 0;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>q>>s;
    int ans=0;
    for(int i=0;i<n;i++)ans+=ch(i);
    while(q--)
    {
        int u;
        char x;
        cin>>u>>x;
        u--;
        ans-=ch(u-2)+ch(u-1)+ch(u);
        s[u]=x;
        ans+=ch(u-2)+ch(u-1)+ch(u);
        cout<<ans<<endl;

    }
    return 0;
}
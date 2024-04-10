#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int fr[309],st[309],tk[309];
 string s,tmp;

ll ch()
{
    ll u=0;
    for(int i=0;i<4;i++)
        st[tmp[i]]=u,u+=fr[tmp[i]],tk[tmp[i]]=0;
    ll res=0;
    for(int i=0;i<s.size();i++)
    {
       ll r=st[s[i]];
       st[s[i]]++;
       tk[s[i]]++;
       for(int j=0;tmp[j]!=s[i];j++)
            r-=tk[tmp[j]];
      res+=r;
    }
    return res;
}
string ans;
void go()
{
    for(int i=0;i<ans.size();i++)
        for(int j=0;j<fr[ans[i]];j++)cout<<ans[i];
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        fr['A']=fr['N']=fr['T']=fr['O']=0;
        for(int i=0;i<s.size();i++)fr[s[i]]++;
        tmp="ANOT";
        ll rs=-1;
        do
        {
            ll p=ch();
            if(p>rs)ans=tmp,rs=p;
        }while(next_permutation(tmp.begin(),tmp.end()));
        go();
    }
}
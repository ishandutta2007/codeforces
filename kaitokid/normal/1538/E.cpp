#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll cal(string s)
{
    ll ans=0;
    for(int i=0;i+3<s.size();i++)
        if(s[i]=='h'&&s[i+2]=='h'&&s[i+1]=='a'&&s[i+3]=='a')ans++;
    return ans;
}
pair<ll,pair<string,string> > var(string s)
{   int z=s.size();
   ll ans=cal(s);
    string fr="";
    for(int i=0;i<min(3,z);i++)fr+=s[i];
    string en="";
    for(int i=max(0,z-3);i<z;i++)en+=s[i];
    return {ans,{fr,en} };
}

pair<ll,pair<string,string> > mrg(pair<ll,pair<string,string> > x,pair<ll,pair<string,string> > y)
{
    ll ans=x.first+y.first;
    string u=x.second.second +y.second.first;
    ans+=cal(u);
    string fr=x.second.first;
    for(int i=0;i<y.second.first.size();i++)
        if(fr.size()<3)fr+=y.second.first[i];
    string en=y.second.second;
    for(int i=x.second.second.size()-1;i>=0;i--)
        if((en.size())<3)en=x.second.second[i]+en;
        return {ans,{fr,en}};

}
map<string,pair<ll,pair<string,string> > >mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {   mp.clear();
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            string name,type;
            cin>>name>>type;
            if(type==":="){string x;cin>>x;
            mp[name]=var(x);
            }
            else
            {
                string x,y,u;
                cin>>x>>u>>y;
                mp[name]=mrg(mp[x],mp[y]);
            }
           if(i==n-1)cout<<mp[name].first<<endl;
        }
    }
    return 0;
}
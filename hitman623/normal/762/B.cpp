#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
#define F first
#define S second
using namespace std;
ll a,b,c,m,p,cnt=0,i,j,price=0,r,t;
string s,s1,s2;
map < string , vector < ll > > ma;
int main()
{
    s1="USB";
    s2="PS/2";
    cin>>a>>b>>c;
    cin>>m;
    for(i=0;i<m;++i)
        {cin>>p>>s;
        ma[s].pb(p);}
        sort(ma[s1].begin(),ma[s1].end());
        sort(ma[s2].begin(),ma[s2].end());
        if(ma[s1].size()>=a)
            { cnt+=a;
        for(i=0;i<a;++i)
            {price+=ma[s1][i];ma[s1][i]=1000000007;}
            r=a;
            a=0;}
        else
        { cnt+=ma[s1].size();
        r=ma[s1].size();
        for(i=0;i<ma[s1].size();++i)
            {price+=ma[s1][i];ma[s1][i]=1000000007;}
            a-=ma[s1].size();
        }
        if(ma[s2].size()>=b)
            { cnt+=b;
        for(i=0;i<b;++i)
            {price+=ma[s2][i];ma[s2][i]=1000000007;}
            t=b;
            b=0;}
        else
        { cnt+=ma[s2].size();
        for(i=0;i<ma[s2].size();++i)
            {price+=ma[s2][i];ma[s2][i]=1000000007;}
            t=ma[s2].size();
            b-=ma[s2].size();
        }
        i=0;j=0;
        sort(ma[s1].begin(),ma[s1].end());
        sort(ma[s2].begin(),ma[s2].end());
        while(c>0 && i<ma[s1].size()-r && j<ma[s2].size()-t)
        {
            if(ma[s1][i]<ma[s2][j])
            {
                price+=ma[s1][i];i++;
            }
            else
            {
                price+=ma[s2][j];j++;
            }
            cnt++;
            c--;
        }
        while(c>0 && i<ma[s1].size()-r)
        {
            price+=ma[s1][i];i++;
            c--;cnt++;
        }
         while(c>0 && j<ma[s2].size()-t)
        {
            price+=ma[s2][j];j++;
            c--;cnt++;
        }
        cout<<cnt<<" "<<price;
    return 0;
}
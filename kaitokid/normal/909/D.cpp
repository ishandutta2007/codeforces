#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
list<pair<int,char> >ls;
string s;
int ans;
int main()
{
    ios::sync_with_stdio(0);
cin>>s;
char x=s[0];;
int u=1;
for(int i=1;i<s.size();i++)
    if(s[i]==x)u++;
else {ls.push_back(make_pair(u,x));u=1;x=s[i];}
ls.push_back(make_pair(u,x));
while(ls.size()>1)
{
    ans++;
    list<pair<int,char> >::iterator it1=ls.begin(),it2,it3;
    it3=ls.end();
    it3--;
    (*(it1)).first--;
    it2=it1;it1++;if((*it2).first==0)ls.erase(it2);
    while(it1!=it3)
        {(*(it1)).first-=2;it2=it1;it1++;if((*it2).first<=0)ls.erase(it2);}
        (*(it3)).first--;
        if((*(it3)).first==0)ls.erase(it3);
if(ls.size()<1)break;
it1=ls.begin();
it3=ls.end();
it3--;
while(it3!=it1)
{it2=it3;
it2--;
if((*it2).second==(*it3).second){(*it2).first+=(*it3).first;it2=it3;it3--;ls.erase(it2);continue;}
it3--;
}

}
cout<<ans;
    return 0;
}
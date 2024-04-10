#include<bits/stdc++.h>
using namespace std;
long long war[1000005];
vector<int> v;
vector<int> v2;
vector<pair<pair<int,int> , long long>> out;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a,b,c,d,e;
	cin>>a>>b;
	while(b--)
    {
        cin>>c>>d>>e;
        war[c]+=e;
        war[d]-=e;
    }
    for(int x=1;x<=a;x++)
    {
        if(war[x]>0)
            v.push_back(x);
        else if(war[x]<0)
            v2.push_back(x);
    }
    int where1=0,where2=0;
    while(where1!=v.size() && where2!=v2.size())
    {
        out.push_back(make_pair(make_pair(v[where1],v2[where2]),min(abs(war[v[where1]]),abs(war[v2[where2]]))));
        long long pom=war[v[where1]]+war[v2[where2]];
        if(pom>0)
        {
            where2++;
            war[v[where1]]=pom;
        }
        else if(pom<0)
        {
            where1++;
            war[v2[where2]]=pom;
        }
        else
        {
            where1++;
            where2++;
        }
    }
    cout<<out.size()<<'\n';
    for(auto x:out)
    {
        cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<'\n';
    }
	return 0;
}
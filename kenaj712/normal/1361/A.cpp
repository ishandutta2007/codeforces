#include<bits/stdc++.h>
using namespace std;
int ktory[1000005];
vector<pair<int,int>> v;
vector<int> pol[1000005];
set<int> s[1000005];
int tom[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c,d;
    cin>>a>>b;
    while(b--)
    {
        cin>>c>>d;
        pol[c].push_back(d);
        pol[d].push_back(c);
    }
    for(int x=1;x<=a;x++)
        cin>>ktory[x];
    for(int x=1;x<=a;x++)
    {
        v.push_back(make_pair(ktory[x],x));
    }
    sort(v.begin(),v.end());
    for(auto x:v)
    {
        for(int y=1;true;y++)
        {
            if(s[x.second].find(y)==s[x.second].end())
            {
                tom[x.second]=y;
                for(auto z:pol[x.second])
                    s[z].insert(y);
                break;
            }
        }
    }
    for(int x=1;x<=a;x++)
        if(tom[x]!=ktory[x])
    {
        cout<<-1;
        return 0;
    }
    for(auto x:v)
        cout<<x.second<<" ";
	return 0;
}
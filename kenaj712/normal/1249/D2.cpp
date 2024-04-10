#include<bits/stdc++.h>
using namespace std;
set<pair<int,int>> s;
vector<pair<int,int>> v[1000005];
vector<int> out;
set<pair<int,int>>::iterator it;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a,b,c,d;
	cin>>a>>b;
	for(int x=1;x<=a;x++)
    {
        cin>>c>>d;
        v[c].push_back(make_pair(d,x));
    }
    for(int x=1;x<=2e5;x++)
    {
        for(auto y:v[x])
            s.insert(y);
        while(b<s.size())
        {
            it=s.end();
            it--;
            out.push_back((*it).second);
            s.erase(it);
        }
        while(1)
        {
            it=s.begin();
            if(it==s.end())
                break;
            if((*it).first==x)
                s.erase(it);
            else
                break;
        }
    }
    sort(out.begin(),out.end());
    cout<<out.size()<<'\n';
    for(auto x:out)
        cout<<x<<" ";
	return 0;
}
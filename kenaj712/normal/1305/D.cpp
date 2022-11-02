#include<bits/stdc++.h>
using namespace std;
vector<int> pol[1000005];
bool odw[1000005];
int in[1000005];
vector<int> v;
vector<int> v2;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    int c,d;
    for(int x=0;x<a-1;x++)
    {
        cin>>c>>d;
        pol[d].push_back(c);
        pol[c].push_back(d);
        in[c]++;
        in[d]++;
    }
    for(int x=1;x<=a;x++)
        if(in[x]==1)
            v.push_back(x);
    int xd;
    while(v.size()>1)
    {
        cout<<"? "<<v[v.size()-1]<<" "<<v[v.size()-2]<<'\n';
        cout.flush();
        cin>>xd;
        if(xd==v[v.size()-1] || xd==v[v.size()-2])
        {
            cout<<"! "<<xd<<'\n';
            cout.flush();
            return 0;
        }
        for(auto x:pol[v[v.size()-1]])
        {
            in[x]--;
            if(in[x]==1)
                v2.push_back(x);
        }
        for(auto x:pol[v[v.size()-2]])
        {
            in[x]--;
            if(in[x]==1)
                v2.push_back(x);
        }
        v.pop_back();
        v.pop_back();
        for(auto x:v2)
            v.push_back(x);
        v2.resize(0);
    }
    cout<<"! "<<v.back()<<'\n';
	return 0;
}
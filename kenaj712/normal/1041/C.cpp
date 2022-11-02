#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > v;
priority_queue <pair<int,int> > q;
int out[200005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c,d;
    cin>>a>>b>>c;
    for(int x=1;x<=a;x++)
    {
        cin>>d;
        v.push_back(make_pair(d,x));
    }
    sort(v.begin(),v.end());
    q.push(make_pair(-v[0].first-c-1,1));
    out[v[0].second]=1;
    int licz=2;
    for(int x=1;x<a;x++)
    {
        if(v[x].first>=-q.top().first)
        {
            q.push(make_pair(-v[x].first-c-1,q.top().second));
            out[v[x].second]=q.top().second;
            q.pop();
        }
        else
        {
            out[v[x].second]=licz;
            q.push(make_pair(-v[x].first-c-1,licz));
            licz++;
        }
    }
    cout<<licz-1<<'\n';
    for(int x=1;x<=a;x++)
        cout<<out[x]<<" ";
	return 0;
}
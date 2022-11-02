#include<bits/stdc++.h>
using namespace std;
bool odw[1000005];
vector<int> v;
vector<pair<int,int>> v2;
void solve()
{
    int a,b;
    cin>>a>>b;
    for(int x=0;x<b;x++)
    {
        int c,d;
        cin>>c>>d;
        if(c > d)
            swap(c,d);
        odw[c] = true;
        odw[d] = true;
        v2.push_back(make_pair(c,d));
    }
    for(int x=1;x<=2*a;x++)
        if(!odw[x])
            v.push_back(x);
    int pom = v.size() / 2;
    for(int x=0;x<pom;x++)
        v2.push_back(make_pair(v[x], v[x+pom]));
    int licz = 0;
    for(int x=0;x<a;x++)
        for(int y=x+1;y<a;y++)
        {
            int xd = 0;
            if(v2[y].first > v2[x].first && v2[y].first < v2[x].second)
                xd^=1;
            if(v2[y].second > v2[x].first && v2[y].second < v2[x].second)
                xd^=1;
            licz += xd;
        }
    cout<<licz<<'\n';
    for(int x=1;x<=2*a;x++)
        odw[x] = false;
    v.resize(0);
    v2.resize(0);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}
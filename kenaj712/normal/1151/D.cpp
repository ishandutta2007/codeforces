#include<bits/stdc++.h>
using namespace std;
vector<pair<int,pair<int,int>>> v;
long long jeden=1;
long long suma;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,c,d;
    cin>>a;
    for(int x=0;x<a;x++)
    {
        cin>>c>>d;
        v.push_back(make_pair(d-c,make_pair(c,d)));
    }
    sort(v.begin(),v.end());
    for(int x=0;x<a;x++)
    {
        suma+=jeden*x*(v[x].second.first)+jeden*(a-x-1)*(v[x].second.second);
    }
    cout<<suma;
	return 0;
}
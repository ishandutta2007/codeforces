#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v1;
vector<pair<int,int>> v2;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,c,d;
    cin>>a;
    for(int x=1;x<=a;x++)
    {
        cin>>c>>d;
        if(c<d)
            v1.push_back(make_pair(-d,x));
        else
            v2.push_back(make_pair(c,x));
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    if(v1.size()>v2.size())
    {
        cout<<v1.size()<<'\n';
        for(auto x:v1)
            cout<<x.second<<" ";
    }
    else
    {
        cout<<v2.size()<<'\n';
        for(auto x:v2)
            cout<<x.second<<" ";
    }
	return 0;
}
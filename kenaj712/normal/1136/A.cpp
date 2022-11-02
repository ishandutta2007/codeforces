#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,c,d,b,pom=0;
    cin>>a;
    while(a--)
    {
        cin>>c>>d;
        v.push_back(d);
    }
    v.push_back(1e9);
    cin>>b;
    while(b>v[pom])
        pom++;
    cout<<v.size()-1-pom;
	return 0;
}
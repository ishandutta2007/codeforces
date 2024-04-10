#include<bits/stdc++.h>
using namespace std;
vector<long long> v;
void solve()
{
    long long a,b;
    cin>>a>>b;
    long long pom=1;
    long long ret=1;
    while(pom<=a)
    {
        v.push_back(pom+1);
        a-=pom;
        pom*=2;
    }
    v.push_back(a+1);
    for(auto x:v)
        ret=(ret*x)%b;
    v.resize(0);
    ret=(ret-1+b)%b;
    cout<<ret<<'\n';
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
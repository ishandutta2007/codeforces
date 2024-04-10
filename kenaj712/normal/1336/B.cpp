#include<bits/stdc++.h>
using namespace std;
int dl[3];
vector<int> v[3];
long long mini=8e18;
void f(long long a,long long b,long long c)
{
    mini=min(mini,(a-b)*(a-b)+(b-c)*(b-c)+(a-c)*(a-c));
}
void solve2()
{
    for(auto x:v[0])
    {
        int pom1=lower_bound(v[1].begin(),v[1].end(),x)-v[1].begin();
        int pom2=upper_bound(v[2].begin(),v[2].end(),x)-v[2].begin();
        pom2--;
        if(pom1<0)
            pom1++;
        if(pom1==v[1].size())
            pom1--;
        if(pom2<0)
            pom2++;
        if(pom2==v[2].size())
            pom2--;
        f(x,v[1][pom1],v[2][pom2]);
    }
    swap(v[1],v[2]);
    for(auto x:v[0])
    {
        int pom1=lower_bound(v[1].begin(),v[1].end(),x)-v[1].begin();
        int pom2=upper_bound(v[2].begin(),v[2].end(),x)-v[2].begin();
        pom2--;
        if(pom1<0)
            pom1++;
        if(pom1==v[1].size())
            pom1--;
        if(pom2<0)
            pom2++;
        if(pom2==v[2].size())
            pom2--;
        f(x,v[1][pom1],v[2][pom2]);
    }
    swap(v[1],v[2]);
}
void solve()
{
    int d;
    for(int x=0;x<3;x++)
        cin>>dl[x];
    for(int y=0;y<3;y++)
        for(int x=0;x<dl[y];x++)
        {
            cin>>d;
            v[y].push_back(d);
        }
    for(int x=0;x<3;x++)
        sort(v[x].begin(),v[x].end());
    solve2();
    swap(v[1],v[2]);
    solve2();
    swap(v[1],v[2]);
    swap(v[0],v[1]);
    solve2();
    swap(v[1],v[2]);
    solve2();
    swap(v[0],v[1]);
    solve2();
    swap(v[1],v[2]);
    solve2();
    cout<<mini<<'\n';
    for(int x=0;x<3;x++)
        v[x].resize(0);
    mini=8e18;
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
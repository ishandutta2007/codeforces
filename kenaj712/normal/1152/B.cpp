#include<bits/stdc++.h>
using namespace std;
set<int> s;
set<int> s2;
vector<int> v;
int check(int a)
{
    int pom=1;
    for(int x=0;x==x;x++)
    {
        if(pom-1==a)
            return x;
        pom*=2;
    }
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int pom=1,t=25;
    while(t--)
    {
        s2.insert(pom);
        s.insert(pom-1);
        pom*=2;
    }
    int a;
    cin>>a;
    while(0==0)
    {
        if(s.find(a)!=s.end())
            break;
        if(s2.find(a)!=s2.end())
        {
            v.push_back(0);
            a++;
            continue;
        }
        v.push_back(*s.lower_bound(a));
        a^=*s.lower_bound(a);
        a++;
    }
    cout<<2*v.size()<<'\n';
    for(auto x:v)
        cout<<check(x)<<" ";
	return 0;
}
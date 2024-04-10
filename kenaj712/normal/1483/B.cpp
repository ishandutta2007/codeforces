#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
//int tree[1000005];
//int pot = (1<<17);
int lewo[1000005];
int prawo[1000005];
set<int> s;
vector<int> out;
/*void ins(int a,int b)
{
    int pom = a+pot;
    while(pom != 0)
    {
        tree[pom]+=b;
        pom/=2;
    }
}
int check(int a,int b)
{
    int l = a+pot , r = b+pot;
    int war = tree[l];
    if(l!=r)
        war += tree[r];
    while(l/2!=r/2)
    {
        if(l%2==0)
            war += tree[l+1];
        if(r%2==1)
            war += tree[r-1];
        l/=2;
        r/=2;
    }
    return war;
}*/
void solve()
{
    int a;
    cin>>a;
    for(int x=1;x<=a;x++)
    {
        cin>>tab[x];
        if(x>1 && __gcd(tab[x] , tab[x-1]) == 1)
            s.insert(x);
        lewo[x] = x-1;
        prawo[x] = x+1;
    }
    if(__gcd(tab[a] , tab[1]) == 1)
        s.insert(1);
    lewo[1] = a;
    prawo[a] = 1;
    int where = 2;
    while(!s.empty())
    {
        if(where > a)
            where -= a;
        auto it = s.lower_bound(where);
        if(it == s.end())
            it = s.begin();
        int pom = *it;
        where = prawo[prawo[pom]];
        out.push_back(pom);
        lewo[prawo[pom]] = lewo[pom];
        prawo[lewo[pom]] = prawo[pom];
        s.erase(pom);
        s.erase(prawo[pom]);
        if(__gcd(tab[lewo[pom]] , tab[prawo[pom]]) == 1 && prawo[pom]!=pom)
            s.insert(prawo[pom]);
    }
    cout<<out.size()<<" ";
    for(auto x:out)
        cout<<x<<" ";
    cout<<'\n';
    out.resize(0);
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
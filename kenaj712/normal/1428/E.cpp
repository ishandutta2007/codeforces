#include<bits/stdc++.h>
using namespace std;
#define int long long
priority_queue<pair<int,pair<int,int>>> q;
long long f(long long a,long long b)
{
    if(b>a)
        return a;
    long long pom1=a%b;
    long long pom2=b-pom1;
    return pom1*((a/b+1)*(a/b+1)) + pom2*(a/b)*(a/b);
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long out=0;
    int a,b;
    cin>>a>>b;
    b-=a;
    for(int x=0;x<a;x++)
    {
        int d;
        cin>>d;
        q.push(make_pair(f(d,1)-f(d,2),make_pair(d,1)));
    }
    for(int t=0;t<b;t++)
    {
        pair<int,pair<int,int>> p=q.top();
        q.pop();
        int pom2=p.second.second+1,pom=p.second.first;
        q.push(make_pair(f(pom,pom2) - f(pom,pom2+1) , make_pair(pom,pom2)));
    }
    while(!q.empty())
    {
        out+=f(q.top().second.first,q.top().second.second);
        q.pop();
    }
    cout<<out;
	return 0;
}
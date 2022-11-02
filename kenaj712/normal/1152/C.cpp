#include<bits/stdc++.h>
using namespace std;
vector<long long> dz;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b;
    cin>>a>>b;
    if(a<b)
        swap(a,b);
    long long c=a-b;
    for(int x=1;x*x<=c;x++)
        if(c%x==0)
    {
        dz.push_back(x);
        dz.push_back(c/x);
    }
    pair<long long,long long> maks=make_pair(a*b/__gcd(a,b),0);
    long long pom;
    for(auto x:dz)
    {
        pom=a%x;
        pom=x-pom;
        maks=min(maks,make_pair((a+pom)*(b+pom)/x,pom));
    }
    cout<<maks.second;
	return 0;
}
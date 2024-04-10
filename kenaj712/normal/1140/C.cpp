#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,long long>> v2;
multiset<int> s;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    long long c,d;
    cin>>a>>b;
    for(int x=0;x<a;x++)
    {
        cin>>c>>d;
        v2.push_back(make_pair(d,c));
    }
    sort(v2.begin(),v2.end());
    int pom=b;
    long long suma=0;
    long long maks=0;
    for(int x=a-1;x==x;x--)
    {
        suma+=v2[x].second;
        s.insert(v2[x].second);
        maks=max(maks,v2[x].first*suma);
        pom--;
        if(pom==0)
        {
            pom=x-1;
            maks=max(maks,v2[x].first*suma);
            break;
        }
    }
    for(int x=pom;x>=0;x--)
    {
        suma-=*s.begin();
        s.erase(s.begin());
        suma+=v2[x].second;
        s.insert(v2[x].second);
        maks=max(maks,v2[x].first*suma);
    }
    cout<<maks;
	return 0;
}
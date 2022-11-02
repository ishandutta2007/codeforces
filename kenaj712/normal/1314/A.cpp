#include<bits/stdc++.h>
using namespace std;
multiset<long long> s;
vector<pair<long long,long long>> v;
long long tab1[1000005];
long long tab2[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=0;x<a;x++)
        cin>>tab1[x];
    for(int x=0;x<a;x++)
    {
        cin>>tab2[x];
        v.push_back(make_pair(tab1[x],tab2[x]));
    }
    sort(v.begin(),v.end());
    long long last=0,sum=0;
    long long out=0;
    for(auto x:v)
    {
        while(!s.empty() && last<x.first)
        {
            out+=sum;
            sum+=*s.begin();
            out+=*s.begin();
            s.erase(s.begin());
            last++;
        }
        s.insert(-x.second);
        sum+=x.second;
        last=x.first;
    }
    while(!s.empty() )
    {
        out+=sum;
        sum+=*s.begin();
        out+=*s.begin();
        s.erase(s.begin());
        last++;
    }
    cout<<out;
	return 0;
}
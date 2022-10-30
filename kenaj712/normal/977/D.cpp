#include<bits/stdc++.h>
using namespace std;
vector<pair<int,unsigned long long> > v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    unsigned long long b,c;
    int pom1,pom2;
    for(int x=0;x<a;x++)
    {
        cin>>b;
        c=b;
        pom1=0;
        pom2=0;
        while(b%3==0)
        {
            b/=3;
            pom1++;
        }
        while(b%2==0)
        {
            b/=2;
            pom2++;
        }
        v.push_back(make_pair(pom2-pom1,c));
    }
    sort(v.begin(),v.end());
    for(int x=0;x<a;x++)
        cout<<v[x].second<<" ";

	return 0;
}
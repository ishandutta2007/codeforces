#include<bits/stdc++.h>
using namespace std;
long long tab[1000005];
vector<long long> v;
int cnt(long long a)
{
    int pom1=upper_bound(v.begin(),v.end(),a)-v.begin()-(lower_bound(v.begin(),v.end(),a)-v.begin());
    return pom1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    long long pom=0;
    cin>>a;
    for(int x=1;x<=a;x++)
    {
        cin>>tab[x];
        pom+=tab[x];
        v.push_back(pom);
    }
    sort(v.begin(),v.end());
    pom=0;
    int maks=0;
    for(int x=a;x>=1;x--)
    {
        maks=max(maks,cnt(-pom));
        pom+=tab[x];
    }
    cout<<a-maks;
	return 0;
}
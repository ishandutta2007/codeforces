#include<bits/stdc++.h>
using namespace std;
set<long long> s1;
set<long long> s2;
long long tab[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=0;x<a;x++)
        cin>>tab[x];
    long long pom=0;
    for(int x=0;x<a;x++)
    {
        pom+=tab[x];
        s1.insert(pom);
    }
    pom=0;
    for(int x=a-1;x>=0;x--)
    {
        pom+=tab[x];
        s2.insert(pom);
    }
    long long maks=0;
    for(auto x:s1)
        if(s2.find(x)!=s2.end()&&2*x<=pom)
            maks=x;
    cout<<maks;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
vector<int> v[2];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,suma=0;
    cin>>a;
    while(a--)
    {
        cin>>b;
        v[b%2].push_back(-b);
        suma+=b;
    }
    sort(v[0].begin(),v[0].end());
    sort(v[1].begin(),v[1].end());
    int pom=min(v[0].size(),v[1].size());
    int sum2=0;
    for(int x=0;x<min(pom+1,int(v[0].size()));x++)
        sum2-=v[0][x];
    for(int x=0;x<min(pom+1,int(v[1].size()));x++)
        sum2-=v[1][x];
    cout<<suma-sum2;
	return 0;
}
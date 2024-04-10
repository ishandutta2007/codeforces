#include<bits/stdc++.h>
using namespace std;
long long tab[1005][1005];
vector<long long> v;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=0;x<a;x++)
        for(int y=0;y<a;y++)
            cin>>tab[x][y];
    long long nwd=0;
    for(int x=0;x<a;x++)
        nwd=__gcd(nwd,tab[0][x]);
    v.push_back(nwd);
    for(int x=1;x<a;x++)
        v.push_back(tab[0][x]/nwd);
    long long pom=(tab[1][2]/v[1])/v[2];
    pom=sqrt(pom);
    for(int x=0;x<a;x++)
    {
        if(x==0)
            cout<<v[x]/pom;
        else
            cout<<v[x]*pom;
        cout<<" ";
    }
	return 0;
}
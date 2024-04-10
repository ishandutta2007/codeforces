#include<bits/stdc++.h>
using namespace std;
vector<long long> v[70];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    long long b,c,d,e,maks=0,indeks=-1;
    for(int x=0;x<a;x++)
    {
        cin>>b;
        c=b;
        d=0;
        while(c%2==0)
        {
            c/=2;
            d++;
        }
        v[d].push_back(b);
        if(v[d].size()>maks)
        {
            maks=v[d].size();
            indeks=d;
        }
    }
    cout<<a-maks<<'\n';
    for(int x=0;x<=65;x++)
        if(x!=indeks)
            for(auto y:v[x])
                cout<<y<<" ";
	return 0;
}
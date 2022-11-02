#include<bits/stdc++.h>
using namespace std;
vector<long long> v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b,c;
    long long suma=0,licz=0,pom=0,maks=0;
    cin>>a>>b;
    for(int x=0;x<a;x++)
    {
        cin>>c;
        suma+=c;
        maks=max(maks,c);
        v.push_back(c);
    }
    sort(v.begin(),v.end());
    for(int x=0;x<a;x++)
    {
        licz++;
        if(v[x]>pom)
            pom++;
    }
    long long zero=0;
    licz+=max(zero,maks-pom);
    cout<<suma-licz;
	return 0;
}
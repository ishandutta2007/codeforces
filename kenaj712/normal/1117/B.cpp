#include<bits/stdc++.h>
using namespace std;
long long tab[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b,c,d,e;
    cin>>a>>b>>c;
    for(int x=0;x<a;x++)
        cin>>tab[x];
    sort(tab,tab+a);
    d=tab[a-2];
    e=tab[a-1];
    cout<<(b/(c+1))*d+(b-(b/(c+1)))*e;
	return 0;
}
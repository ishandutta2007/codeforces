#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b;
    cin>>a>>b;
    long long licz=0,pocz,kon;
    int pom=0;
    if(b%2==0)
        pom++;
    pocz=b/2;
    kon=b/2+b%2;
    cout<<max(licz,min(pocz,a-kon+1)-pom);

	return 0;
}
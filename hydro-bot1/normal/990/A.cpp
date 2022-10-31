// Hydro submission #625922c637de167dd82bd5f6@1650008775069
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m;int a,b;
	cin>>n>>m>>a>>b;
	printf("%lld\n",min((m-n%m)*a,(n%m)*b));
	return 0;
}
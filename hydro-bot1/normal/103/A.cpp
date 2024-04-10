// Hydro submission #6253bf30ca530601467153d5@1649655600444
#include<bits/stdc++.h>
using namespace std;
long long a[100],s;
int main()
{
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0;i<n;i++)
	s+=a[i]*(i+1)-i;
	printf("%lld\n",s);
	return 0;
}
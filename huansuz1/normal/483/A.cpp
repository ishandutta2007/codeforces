#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m;
long long gcd ( long long a, long long b )
{
  long long c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}
int main(){
	cin>>n>>m;
	for (long long i=n; i<=m-2; i++)
		for (long long j=i+1; j<=m-1; j++)
			for (long long o=j+1; o<=m; o++){
				long long k1=gcd(i,j);
				long long k2=gcd(i,o);
				long long k3=gcd(j,o);
				if ((k1==1 && k2!=1 && k3==1)) {cout<<i<<" "<<j<<" "<<o; exit(0);}


			}
	cout<<-1;


return 0;
}
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k;

int main()
{
	scanf("%lld%lld",&n,&k);
	printf("%lld\n", (2*n+k-1)/k+(5*n+k-1)/k+(8*n+k-1)/k);
}
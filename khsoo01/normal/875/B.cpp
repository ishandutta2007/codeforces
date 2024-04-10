#include<bits/stdc++.h>
using namespace std;
const int N = 300005;

int n, a[N], x[N], c;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n+1;i++) {
		while(c<n && x[n-c]) c++;
		printf("%d ", i-c);
		x[a[i]] = 1;
	}
}
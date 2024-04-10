#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int N = 100005, inf = 1e9;

int n;

int main()
{
	scanf("%d",&n);
	int ans = inf, x;
	for(int i=1;i<=n;i++) {
		int j = (n + i - 1) / i;
		if(i+j < ans) {
			ans = i+j;
			x = i;
		}
	}
	for(int i=1;i<=n;i+=x) {
		for(int j=min(n,i+x-1);j>=i;j--) {
			printf("%d ",j);
		}
	}
}
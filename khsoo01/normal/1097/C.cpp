#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int N = 500005;

int n, a[N], b[N], c;

char ipt[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%s",ipt);
		int L = strlen(ipt), A = 0, B = 0;
		for(int i=0;i<L;i++) {
			A += (ipt[i] == '(' ? 1 : -1);
			B = min(B, A);
		}
		if(A == 0 && B == 0) c++;
		else if(A > 0 && B == 0) a[A]++;
		else if(A < 0 && A == B) b[-A]++;
	}
	int ans = c/2;
	for(int i=1;i<N;i++) {
		ans += min(a[i], b[i]);
	}
	printf("%d\n",ans);
}
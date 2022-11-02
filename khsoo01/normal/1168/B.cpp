#include<bits/stdc++.h>
using namespace std;

bool dt[15][1<<15];

int getbit (int B, int I) {
	return !!(B & (1<<I));
}

bool calc (int X, int Y) {
	for(int i=0;i<X;i++) {
		for(int j=1;j<X;j++) {
			if(i - j < 0 || i + j >= X) break;
			int A = getbit(Y, i-j), B = getbit(Y, i), C = getbit(Y, i+j);
			if(A == B && B == C) return false;
		}
	}
	return true;
}

int n;
char a[300005];

long long ans;

int main()
{
	for(int i=1;i<12;i++) {
		for(int j=0;j<(1<<i);j++) {
			dt[i][j] = calc(i, j);
		}
	}
	scanf("%s",a+1);
	n = strlen(a+1);
	for(int i=1;i<=n;i++) {
		int I = 0;
		for(int j=i;j<=n;j++) {
			I = 2*I + (a[j] - '0');
			if(dt[j-i+1][I]) continue;
			ans += n - j + 1;
			break;
		}
	}
	printf("%lld\n", ans);
}
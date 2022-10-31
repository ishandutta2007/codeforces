#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int n, m, nr = 0, mr = 0;
bool pm[10];
int a[50];

int rec(int sz) {
	if(sz == 0) {
		int c1 = 0;
		for(int i = 1, v = 1; i <= nr; i++, v *= 7) {
			c1 += v * a[i];
		}
		int c2 = 0;
		for(int i = nr + 1, v = 1; i <= nr + mr; i++, v *= 7) {
			c2 += v * a[i];
		}
		if(c1 < n && c2 < m) {
			return(1);
		}
	}
	int ret = 0;
	for(int i = 0; i < 7; i++) {
		if(pm[i]) continue;
		pm[i] = 1;
		a[sz] = i;
		ret += rec(sz - 1);
		pm[i] = 0;
	}
	return(ret);
}

int main() {

	scanf("%d%d", &n, &m);
	n--, m--;
	{
		int c = n;
		while(c) {
			c /= 7;
			nr++;
		}
		nr += nr == 0;
	}
	{
		int c = m;
		while(c) {
			c /= 7;
			mr++;
		}
		mr += mr == 0;
	}
	n++, m++;

	printf("%d", rec(nr + mr));

	return 0;
}
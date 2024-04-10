#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

int gcd(int a, int b) {
	while (b) b^=a^=b^=a%=b;
	return a;
}

const int maxn=100100;

int n,ans,k;
int a[2*maxn],b[2*maxn],c[2*maxn];
bool used[2*maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%d",&a[i]);
		c[a[i]]=i;
	}
	for (int i=0; i<n; i++)
		scanf("%d",&b[i]);

	for (int i=0; i<n; i++) {
		while (used[a[i-k]]) k--;
		if (!used[a[i-k]] && a[i-k]!=b[i]) {
			k++;
			used[b[i]]=true;
			ans=max(ans,n-c[b[i]]);
		}
	}
	cout << ans;
	return 0;
}
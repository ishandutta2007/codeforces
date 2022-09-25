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
const int mod=(1e9)+7;

int n,k,x,y;
int w[maxn],p[maxn],sm[maxn];
int sum;

void norm(int &x) {
	while (x<0) x+=mod;
	while (x>=mod) x-=mod;
}

int findparent(int x, bool f) {
	if (p[x]==x) return x;
	if (!f) return findparent(p[x],f);
	int pr=p[x];
	p[x]=findparent(p[x],f);
	sm[x]+=sm[pr]; norm(sm[x]);
	return p[x];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d",&n);
	for (int i=1; i<=n; i++) {
		scanf("%d",&k);
		p[i]=i;
		for (int j=0; j<k; j++) {
			scanf("%d%d",&x,&y);
			int pr=findparent(x,1);
			int o=y+sm[x]; norm(o);
			sm[pr]=o;
			//w[i]+=w[findparent(x)]+1;
			p[findparent(x,0)]=i;
			findparent(x,1);
			sum+=o; norm(sum);
		}
	}
	cout << sum;
	return 0;
}
#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

int i,n,m,k,p;
string s;
int pr[10000];
bool f[10000];

const ll mod=1000000007;


int get(int x) {
	if (pr[x]==x) return x;
	int k=get(pr[x]);
	return pr[x]=k;
}

void unionn(int i, int j) {
	int a=get(i),b=get(j);
	if (a==b) return;
	if (rand()&1) 
		pr[a]=b;
	else 
		pr[b]=a;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> m >> k;
	ll ans=1;

	if (k>n) {
		for (int i=0; i<n; i++) ans=(ans*(long long)m)%mod;
		cout << ans;
		return 0;
	}

	if (m==1) {
		cout << 1;
		return 0;
	}

	for (int i=0; i<=n; i++) {
		pr[i]=i;
		f[i]=false;
	}

	for (int i=0; i<n-k+1; i++) {
		for (int j=0; j<k/2; j++) 
			unionn(i+j,i+k-j-1);
	}

	for (int i=0; i<n; i++) {
		int k=get(i);
		if (!f[k]) {
			ans=(ans*(long long)m)%mod;
		}
		f[k]=true;
	}
	cout << ans;
	return 0;
}
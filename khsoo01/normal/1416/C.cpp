#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;

const int N = 300005, X = 30, inf = 1e9;
typedef long long ll;

int n, a[N];
ll cnt[32][2];

void solve (vector<int> &V, int D) {
	if(D < 0 || V.size() < 2) return;
	vector<int> W[2];
	int Z = (1<<D);
	for(int i=0;i<(int)V.size();i++) {
		int B = !!(V[i] & Z);
		cnt[D][B] += ((int)W[B^1].size());
		W[B].push_back(V[i]);
	}
	solve(W[0], D-1);
	solve(W[1], D-1);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	vector<int> V;
	for(int i=1;i<=n;i++) {
		V.push_back(a[i]);
	}
	solve(V, X);
	ll ans1 = 0, ans2 = 0;
	for(int i=X;i>=0;i--) {
		int B = 0;
		if(cnt[i][1] < cnt[i][0]) B = 1;
		ans1 += cnt[i][B];
		ans2 += (1<<i) * B;
	}
	printf("%lld %lld\n", ans1, ans2);
}
#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;

const int N = 10005, inf = 1e9;

int n, a[N];
vector<pair<pii, int> > ops;

void solve () {
	scanf("%d",&n);
	int ob = 0;
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		ob += a[i];
	}
	if(ob % n != 0) {
		puts("-1");
		return;
	}
	ob /= n;
	ops.clear();
	for(int i=2;i<=n;i++) {
		if(a[i] % i != 0) {
			int T = i - a[i] % i;
			ops.push_back({{1, i}, T});
			a[i] += T;
			a[1] -= T;
		}
		ops.push_back({{i, 1}, a[i] / i});
	}
	for(int i=2;i<=n;i++) {
		ops.push_back({{1, i}, ob});
	}
	printf("%d\n", (int)ops.size());
	for(int i=0;i<(int)ops.size();i++) {
		printf("%d %d %d\n", ops[i].X.X, ops[i].X.Y, ops[i].Y);
	}
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--) solve();
}
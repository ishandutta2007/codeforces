#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

const int N = 105;

int n, c[2], a[N], ans;
vector<int> v[2], w[2];

int main()
{
	scanf("%d",&n);
	if(n == 1) {
		puts("0");
		return 0;
	}
	c[1] = (n+1)/2;
	c[0] = n/2;
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if(!a[i]) {
			a[i] = -1;
		}
		else {
			a[i] %= 2;
			c[a[i]]--;
		}
	}
	for(int i=1,j=0;i<=n+1;i++) {
		if(a[i] == -1) continue;
		if(j == 0) {
			w[a[i]].push_back(i-j-1);
		}
		else if(i == n+1) {
			w[a[j]].push_back(i-j-1);
		}
		else if(a[i] == a[j]) {
			v[a[i]].push_back(i-j-1);
		}
		else {
			ans += 1;
		}
		j = i;
	}
	for(int i=0;i<2;i++) {
		sort(v[i].begin(), v[i].end());
		sort(w[i].begin(), w[i].end());
		for(auto &T : v[i]) {
			if(c[i] >= T) {
				c[i] -= T;
			}
			else {
				ans += 2;
			}
		}
		for(auto &T : w[i]) {
			if(c[i] >= T) {
				c[i] -= T;
			}
			else {
				ans += 1;
			}
		}
	}
	printf("%d\n", ans);
}
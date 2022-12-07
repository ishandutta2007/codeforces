#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<long long,int> pii;
typedef vector<long long> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(long long i=a;i<b;++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (long long)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const long long N = 505;

long long n, a[N], k, b[N];
vector<pair<long long, int> > ans;

bool solve(long long l, int r) {
	long long Max = 0;
	long long sum = 0;
	if (r - l + 1 == 1) return true;
	for (long long i = l; i <= r; i++) sum += a[i];
	for (long long i = l; i <= r; i++) Max = max(Max, a[i]);
	long long f = 0;
	for (long long i = l; i <= r; i++) {
		if (a[i] == Max) {
			if (i - 1 >= l && a[i - 1] < Max) {
				for (long long j = 0; j < i - l; j++)
					ans.push_back(mp(i - j, 0));
				for (long long j = 0; j < r - i; j++)
					ans.push_back(mp(l, 1));
				f = 1;
				break;
			}
			if (i + 1 <= r && a[i + 1] < Max) {
				for (long long j = 0; j < r - i; j++)
					ans.push_back(mp(i, 1));
				for (long long j = 0; j < i - l; j++)
					ans.push_back(mp(i - j, 0));
				f = 1;
				break;
			}
		}
	}
	if (f == 0) return false;
	a[l] = sum;
	long long len = r - l;
	for (long long i = r + 1; i <= n; i++) a[i - len] = a[i];
	n -= len;
	return true;
}

int main(){
	scanf("%lld", &n);
	for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
	scanf("%lld", &k);
	for (long long i = 1; i <= k; i++) scanf("%lld", &b[i]);
	long long s1 = 0, s2 = 0;
	for (long long i = 1; i <= n; i++) {
		s1 += a[i]; s2 += b[i];
	}
	if (s1 != s2) {
		printf("NO\n");
		return 0;
	}
	long long f = 1;
	for (long long i = 1; i <= k; i++) {
		long long sum = 0;
		for (long long j = i; j <= n; j++) {
			sum += a[j];
			if (sum == b[i]) {
				if (!solve(i, j)) {
					f = 0;
					break;
				}
				break;
			} else if (sum > b[i]) {
				f = 0;
				break;
			}
		}
		if (f == 0) break;
	}
	if (!f) printf("NO\n");
	else {
		printf("YES\n");
		for (long long i = 0; i < ans.size(); i++) {
			long long v = ans[i].first;
			long long tp = ans[i].second;
			printf("%lld %c\n", v, tp == 0 ? 'L' : 'R');
		}
	}
    return 0;
}
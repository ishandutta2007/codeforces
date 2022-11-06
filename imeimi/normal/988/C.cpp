#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

struct node {
    int ks, ns, val;
    bool operator<(const node &x) const {
        return val < x.val;
    }
};

int k;
vector<int> arr[200001];
int sum[200001];
set<node> mp;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> k;
	int n;
	set<node>::iterator it;
	for (int i = 1; i <= k; ++i) {
        cin >> n;
        arr[i].resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
            sum[i] += arr[i][j];
        }
        for (int j = 0; j < n; ++j) {
            arr[i][j] = sum[i] - arr[i][j];
            it = mp.find({ 0, 0, arr[i][j] });
            if (it != mp.end()) {
                printf("YES\n%d %d\n%d %d\n", it->ks, it->ns, i, j + 1);
                return 0;
            }
        }
        for (int j = 0; j < n; ++j) {
            mp.insert({ i, j + 1, arr[i][j] });
        }
	}
	printf("NO\n");
	return 0;
}
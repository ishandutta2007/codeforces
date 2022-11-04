#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int get_p(int a) {
	if(a == 0 || a == 1) {
		return 0;
	}
	return (1 << (32 - __builtin_clz(a - 1))) - a;
}

int get_dist(int a, int b) {
	if(a == b) {
		return 0;
	}
	if(a < b) {
		swap(a, b);
	}
	return get_dist(get_p(a), b) + 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    int mx = -1;
    int id1 = 0;
    for(int i = 1; i < n; i++) {
    	int here = get_dist(a[i], a[0]);
    	if(here > mx) {
    		mx = here;
    		id1 = i;
    	}
    }
    mx = -1;
    int id2 = id1;
    for(int i = 0; i < n; i++) {
    	if(i == id1) {
    		continue;
    	}
    	int here = get_dist(a[id1], a[i]);
    	if(here > mx) {
    		mx = here;
    		id2 = i;
    	}
    }
    cout << id1 + 1 << ' ' << id2 + 1 << ' ' << mx;
}
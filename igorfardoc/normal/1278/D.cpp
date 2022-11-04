#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vi p;

int get_par(int a) {
	if(p[a] == a) {
		return a;
	}
	int par1 = get_par(p[a]);
	p[a] = par1;
	return par1;
}

bool eq(int a, int b) {
	return get_par(a) == get_par(b);
}

void join(int a, int b) {
	a = get_par(a);
	b = get_par(b);
	if(a == b) {
		return;
	}
	p[a] = b;
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
    p.resize(n);
    for(int i = 0; i < n; i++) {
    	p[i] = i;
    }
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    set<pair<int, int>> s;
    int am = 0;
    for(int i = 0; i < n; i++) {
    	auto it = s.lower_bound({a[i].first, 0});
    	for(; it != s.end() && (*it).first < a[i].second; ++it) {
    		if(eq(i, (*it).second)) {
    			cout << "NO";
    			return 0;
    		}
    		++am;
    		join(i, (*it).second);
    	}
    	s.insert({a[i].second, i});
    }
    if(am == n - 1) {
    	cout << "YES";
    } else {
    	cout << "NO";
    }
}
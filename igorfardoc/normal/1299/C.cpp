#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

bool operator<=(pair<ll, int> a, pair<ll, int> b) {
	return a.first * b.second <= a.second * b.first;
}

bool operator>(pair<ll, int> a, pair<ll, int> b) {
	return !(a <= b);
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
    vector<pair<ll, int>> st;
    for(int i = 0; i < n; i++) {
    	pair<ll, int> here = {a[i], 1};
    	while(!st.empty() && here <= st[st.size() - 1]) {
    		here.first += st[st.size() - 1].first;
    		here.second += st[st.size() - 1].second;
    		st.pop_back();
    	}
    	st.push_back(here);
    }
    for(int i = 0; i < st.size(); i++) {
    	for(int j = 0; j < st[i].second; j++) {
    		cout << fixed << setprecision(10) << (long double)st[i].first / st[i].second << ' ';
    	}
    }

}
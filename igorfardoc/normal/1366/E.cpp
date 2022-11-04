#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 998244353;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n, m;
    cin >> n >> m;
    vi a(n);
    map<int, vector<int>> pos;
    vi b(m);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    	pos[a[i]].push_back(i);
    }
    vi last(m);
    for(int i = 0; i < m; i++) {
    	cin >> b[i];
    	if(pos[b[i]].empty()) {
    		cout << 0;
    		return 0;
    	}
    	last[i] = pos[b[i]][pos[b[i]].size() - 1];
    }
    for(int i = 0; i < m - 1; i++) {
    	if(last[i] > last[i + 1]) {
    		cout << 0;
    		return 0;
    	}
    }
    if(pos.find(b[0]) != pos.begin()) {
    	cout << 0;
    	return 0;
    }
    int res = 1;
    for(int i = last[m - 1] + 1; i < n; i++) {
    	if(a[i] < b[m - 1]) {
    		cout << 0;
    		return 0;
    	}
    }
    for(int i = 0; i < m - 1; i++) {
    	for(int j = last[i] + 1; j < last[i + 1]; j++) {
    		if(a[j] < b[i]) {
    			cout << 0;
    			return 0;
    		}
    	}
    	int am = 0;
    	for(int j = last[i + 1]; j > last[i]; j--) {
    		if(a[j] < b[i + 1]) {
    			break;
    		}
    		++am;
    	}
    	res = ((ll)res * am) % mod;
    }
    cout << res;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for(auto &s: a){
		cin >> s;
	}
	for(int i = 0; i < n; i ++){
		if(a[i] != string(m, 'W')){
			int l = find(a[i].begin(), a[i].end(), 'B') - a[i].begin(), r = find(a[i].rbegin(), a[i].rend(), 'B') - a[i].rbegin();
			int R = (l + (m - 1) - r) / 2 + 1;
			int L = (m - 1) - r - l;
			cout << i + L / 2 + 1 << " " << R;
			break;
		}
	}
	return 0;
}
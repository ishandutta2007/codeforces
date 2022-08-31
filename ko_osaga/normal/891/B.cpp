#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const int MAXN = 500005;
const int mod = 1e9 + 7;
typedef pair<int, int> pi;

int n, a[22], pos[22];
vector<pi> v;

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		v.push_back(pi(x, i));
	}
	sort(v.begin(), v.end());
	for(int i=1; i<n; i++){
		if(v[i-1].first == v[i].first){
			puts("-1");
			return 0;
		}
	}
	for(int i=0; i<n; i++){
		int nxt = v[(i+1)%n].second;
		pos[nxt] = v[i].first;
	}
	for(int i=0; i<n; i++) cout << pos[i] << " ";
}
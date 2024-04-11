#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 100005;

vector<int> gph[MAXN];

int main(){
	int n;
	cin >> n;
	for(int i=2; i<=n; i++){
		int x;
		cin >> x;
		gph[x].push_back(i);
	}
	for(int i=1; i<=n; i++){
		if(gph[i].empty()) continue;
		int cnt = 0;
		for(auto &j : gph[i]){
			if(gph[j].size() == 0) cnt++;
		}
		if(cnt < 3){
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
}
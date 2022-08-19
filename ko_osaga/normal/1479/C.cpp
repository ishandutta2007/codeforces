#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;

vector<tuple<int, int, int>> v;

void addEdge(int s, int e, int x){
	if(x > 1000000) return;
	v.emplace_back(s, e, x);

}

int main(){
	int l, r;
	cin >> l >> r;
	printf("YES\n%d ", 32);
	addEdge(1, 32, l);
	r -= l;
	for(int i = 2; i <= 25; i++){
		addEdge(28 - i, 32, l);
		for(int j = i + 1; j <= 25; j++){
			addEdge(28 - j, 28 - i, (1 << (i - 2)));
		}
	}
	int sum = 0;
	for(int i = 19; i >= 0; i--){
		if(r & (1 << i)){
			addEdge(1, 28 - (i + 2), sum + 1);
			sum += (1 << i);
		}
	}
	cout << sz(v) << endl;
	for(auto &[x, y, z] : v){
		printf("%d %d %d\n", x, y, z);
	}
}
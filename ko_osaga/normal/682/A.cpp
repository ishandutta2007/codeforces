#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

int cnt(int x, int p){
	int ret = 0;
	for(int i=1; i<=x; i++){
		if(i%5==p) ret++;
	}
	return ret;
}

int main(){
	int n, m;
	cin >> n >> m;
	lint ret = 0;
	for(int i=0; i<5; i++){
		ret += 1ll * cnt(n, i) * cnt(m, (5 - i) % 5);
	}
	cout << ret;
}
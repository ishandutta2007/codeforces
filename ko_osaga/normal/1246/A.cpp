#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 8005;
#define sz(v) ((int)(v).size())

int popcnt(lint x, lint y){
	if(x < 0) return 0;
	int ret = 0;
	lint z = x;
	while(x){
		if(x & 1) ret++;
		x >>= 1;
	}
	return ret <= y && y <= z;
}

int main(){
	lint n, p;
	cin >> n >> p;
	for(int i=1; i<=1000000; i++){
		if(popcnt(n - p * i, i)){
			cout << i << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
}
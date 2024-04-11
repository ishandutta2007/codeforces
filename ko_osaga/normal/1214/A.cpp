#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int main(){
	int n, e, d;
	cin >> n >> d >> e;
	e = e * 5;
	int ret = 0;
	for(int i=0; i<=n; i+=e){
		ret = max(ret, i + d * ( (n - i) / d) );
	}
	cout << n - ret << endl;
}
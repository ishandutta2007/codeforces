#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using lint = long long;
const int MAXN = 1005;

int n, m, a[MAXN], b[MAXN];

bool trial(double v){
	for(int i=0; i<n; i++){
		v -= (v + m) / a[i];
		if(v < 0) return false;
		v -= (v + m) / b[i];
		if(v < 0) return false;
	}
	return true;
}
int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n; i++) cin >> b[(i+n-1)%n];
	if(!trial(1e10)){
		cout << -1 << endl;
		return 0;
	}
	double s = 0, e = 1e9;
	for(int i=0; i<100; i++){
		double m = (s+e)/2;
		if(trial(m)) e = m;
		else s = m;
	}
	printf("%.10f\n", s);
}
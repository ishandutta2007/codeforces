#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

double p[100005];

double ipow(double x, int d){
	double ret = 1, piv = x;
	while(d){
		if(d&1) ret = ret * piv;
		piv = piv * piv;
		d >>= 1;
	}
	return ret;
}

int main(){
	int n, m;
	cin >> m >> n;
	double ret= 0;
	for(int i=0; i<m; i++){
		ret += (i+1) * (ipow(1.0 * (i+1) / m, n) - ipow(1.0 * i / m, n));
	}
	printf("%.10f", ret);
}
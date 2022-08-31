#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
int main(){
	int n, m;
	cin >> m >> n;
	double ans = 0;
	for(int k = 1; k <= m; k++){
		if(n * (log(k) - log(m)) >= -100)
		ans += k * (pow(k / (double)m, n) - pow((k-1) / (double)m, n));
	}
	cout << setprecision(10) << fixed << ans;
}
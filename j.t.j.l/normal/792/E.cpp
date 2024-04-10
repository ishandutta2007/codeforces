#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){

}

int a[MAXN];

ll check(int p){
	if (p == 0) return -1;
	ll ret = 0;
	for(int i = 1; i <= n; i++){
		if (a[i] >= p && (a[i] % p <= a[i] / p)){
			if (a[i] % (p + 1) == 0)
				ret += a[i] / (p + 1);
			else
				ret += a[i] / (p + 1) + 1;
		}
		else
			return -1;
	}
	return ret;
}

ll solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	ll ans = 1ll << 60;
	for(int gp = 1; (gp-1) * (gp-1) <= a[1]; gp++){
		if (a[1] % gp == 0){
			ll tmp = check(a[1] / gp - 1);
			if (tmp != -1) ans = min(ans, tmp);
			tmp = check(a[1] / gp);
			if (tmp != -1) ans = min(ans, tmp);
		}
		else{
			ll tmp = check(a[1] / gp);
			if (tmp != -1) ans = min(ans, tmp);
		}
	}
	for(int pp = sqrt(a[1]) + 2; pp >= 1; pp--){
		ll tmp = check(pp);
		if (tmp != -1){
			ans = min(ans, tmp);
		}
	}
	return ans;
}

void printans(){

}


int main(){
//	std::ios::sync_with_stdio(false);
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		cout<<solve(0)<<endl;
	}
	return 0;
}
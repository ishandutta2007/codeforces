#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 2005;
const int MOD = 1000000007;

int x, y;
int dp[MAXN];
vector <int> v;

int add (int a, int b) {
	a+=b;
	if (a>=MOD) return a-MOD; return a;
}

int sub (int a, int b) {
	a-=b;
	if (a<0) return a+MOD; return a;
}

void div () {
	for (int i=1; i*i<=y; i++) {
		if (y%i==0) {
			v.push_back(i);
			if (i*i!=y) v.push_back(y/i);
		}
	}
}

int pot (int x, int e) {
	if (e==0) return 1;
	if (e&1) {
		return ((long long) x)*pot(x, e-1)%MOD;
	} else {
		long long t=pot(x, e/2);
		return t*t%MOD;
	}
}

int f (int ind) {
	if (dp[ind]) return dp[ind];
	int val=v[ind];
	int res=pot(2, val-1);
	for (int i=0; i<v.size(); i++) {
		int d=v[i];
		if (d!=val && val%d==0) res=sub(res, f(i));
	}
	dp[ind]=res;
	return res;
}

int main () {
	cin >> x >> y;
	if (y%x!=0) {
		cout << 0;
	} else {
		y/=x;
		div();
		if (y==1) cout << 1; else cout << f(1);
	}
	return 0;
}
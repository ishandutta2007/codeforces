#include <bits/stdc++.h>

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";\n"

using namespace std;

struct mat
{
	int v[2][2];
	mat(int a, int b, int c, int d)
	{
		v[0][0] = a;
		v[0][1] = b;
		v[1][0] = c;
		v[1][1] = d;
	}


};


mat& mul(mat a, mat b)
{
	mat *ans = new mat(0, 0, 0, 0);
	ans->v[0][0] = a.v[0][0] * b.v[0][0] + a.v[0][1] * b.v[1][0];
	ans->v[0][1] = a.v[0][0] * b.v[0][1] + a.v[0][1] * b.v[1][1];
	ans->v[1][0] = a.v[1][0] * b.v[0][0] + a.v[1][1] * b.v[1][0];
	ans->v[1][1] = a.v[1][0] * b.v[0][1] + a.v[1][1] * b.v[1][1];
	return *ans;
}

mat& Pow(mat &x, int exp)
{

	if(exp == 1)
		return x;
	int m = exp/2;
	mat ans = Pow(x, m);
	ans = mul(ans, ans);
	if(exp % 2 == 1)
		ans = mul(ans, x);
	mat * ma = new mat(0, 0, 0, 0);
	ma->v[0][0] = ans.v[0][0];
	ma->v[1][0] = ans.v[1][0];
	ma->v[1][1] = ans.v[1][1];
	ma->v[0][1] = ans.v[0][1];
	return *ma;

}


int n, k;

int main()
{
	ios_base::sync_with_stdio(false);
/*
	mat m(0, 1, 1, 1);

	mat g = Pow(m, 3);
*/
	int ans = 2;
	long long n = 1000000000000000000;
	cin >> n;
	if(n == 2)
		return cout << 1, 0;
	long long a = 2;
	long long b = 3;
	long long 
	c = a+b;

	while(c<=n)
	{
		a = b;
		b = c;
		c = a+ b;
		ans++;
	}

	cout << ans; 
	return 0;
}
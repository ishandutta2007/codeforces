#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string, int> en;
string de[5001];
bool op[5001];
string v[5001];
char u[5001];
int a[5001], b[5001],n;
string al, ah;
int eval(int m) {
	int i;
	int k=0;
	for (i = 1; i <= n; i++) {
		if (!op[i])continue;
		if (u[i] == 'A')v[i][m] = (v[a[i]][m] & v[b[i]][m])|'0';
		if (u[i] == 'X')v[i][m] = (v[a[i]][m] ^ v[b[i]][m])|'0';
		if (u[i] == 'O')v[i][m] = v[a[i]][m] | v[b[i]][m];
	}
	for (i = 1; i <= n; i++)if (v[i][m] == '1')k++;
	return k;
}
int main() {
	int  m,i,j;
	string s;
	scanf("%d%d", &n, &m);
	de[0] = "?";
	en["?"] = 0;
	for (i = 1; i <= n; i++) {
		cin >> de[i];
		en[de[i]] = i;
		cin >> s >> s;
		if (s[0] == '0' || s[0] == '1')v[i] = s;
		else {
			for (j = 0; j < m; j++)v[i].push_back('0');
			op[i] = 1;
			a[i] = en[s];
			cin >> s;
			u[i] = s[0];
			cin >> s;
			b[i] = en[s];
		}
	}
	for (i = 0; i < m; i++)v[0].push_back('0');
	for (i = 0; i < m; i++) {
		int a0 = 0, a1 = 0;
		a0 = eval(i);
		v[0][i] = '1';
		a1 = eval(i);
		if (a0 < a1)al.push_back('0'), ah.push_back('1');
		else if(a0==a1)al.push_back('0'), ah.push_back('0');
		else al.push_back('1'), ah.push_back('0');
	}
	cout << al << '\n' << ah;
	getchar(); getchar();
}
#include <iostream>
#include <string>
using namespace std;

int p[1000009], v[1000009][2];
bool r[1000009][2], ans[1000009];

bool dfs(int n)
{
	if (p[n] < 2)
		return p[n];
	else if (p[n] == 2) {
		r[n][0] = true;
		return !dfs(v[n][0]);
	}
	else if (p[n] == 3) {
		bool a = dfs(v[n][0]), b = dfs(v[n][1]), g = (a | b);
		if (((!a) | b) != g) r[n][0] = true;
		if ((a | (!b)) != g) r[n][1] = true;
		return g;
	}
	else if (p[n] == 4) {
		bool a = dfs(v[n][0]), b = dfs(v[n][1]), g = (a & b);
		if (((!a) & b) != g) r[n][0] = true;
		if ((a & (!b)) != g) r[n][1] = true;
		return g;
	}
	else {
		bool a = dfs(v[n][0]), b = dfs(v[n][1]), g = (a ^ b);
		if (((!a) ^ b) != g) r[n][0] = true;
		if ((a ^ (!b)) != g) r[n][1] = true;
		return g;
	}
}

void dfs1(int n)
{
	if (p[n] < 2) {
		ans[n] = true;
		return;
	}
	if (r[n][0]) dfs1(v[n][0]);
	if (r[n][1]) dfs1(v[n][1]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);	
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		if (s == "IN") 
			cin >> p[i];
		else if (s == "NOT") {
			cin >> v[i][0];
			p[i] = 2; 
		}
		else if (s == "OR") {
			cin >> v[i][0] >> v[i][1];
			p[i] = 3;
		}
		else if (s == "AND") {
			cin >> v[i][0] >> v[i][1];
			p[i] = 4;
		}
		else {
			cin >> v[i][0] >> v[i][1];
			p[i] = 5;
		}
	}
	bool t = dfs(1);
	dfs1(1);
	for (int i = 1; i <= n; i++)
		if (p[i] < 2)
			cout << (int)(t ^ ans[i]);
	cout << '\n';
	return 0;
}
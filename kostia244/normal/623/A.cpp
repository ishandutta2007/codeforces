#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<ll>
#define pi pair<int, int>
#define all(x) x.begin(), x.end()
#define mod 1000000007ll
//using namespace __gnu_pbds;
using namespace std;
int n, f, d = 0, t, m, mat[505][505], col[505], comp[505];
string s;
void dfs(int v, int c) {
	bool l = true;
	comp[v] = d;
	col[v] = c;
	for (int i = 0; i < n; i++)
		if (mat[v][i]) {
			l = false;
			if (col[i] == 2)
				dfs(i, c ^ 1);
			else if(col[i] == c) {
				cout << "No\n";
				exit(0);
			}
		}
	if (l)
		col[v] = 2;
}

int main() {
//	cin.tie();
//	cout.tie();
//	ios::sync_with_stdio(0);
	cin >> n >> m;
	s = string(n, '.');
	for (int i = 0; i < n; i++)
		col[i] = 2;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if(i != j)
				mat[i][j] = 1;
	while (m--) {
		cin >> f >> t, f--, t--;
		mat[f][t] = mat[t][f] = 0;
	}
	for (int i = 0; i < n; i++)
		if (col[i] == 2)
			dfs(i, 0), ++d;
	for(int i = 0; i < n; i++)
		if(col[i] == 1)
			s[i] = 'a';
		else if(col[i] == 2)
			s[i] = 'b';
		else
			s[i] = 'c';
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if(i != j && mat[i][j] == 1 && (abs(s[i]-s[j]) == 1 || s[i] == s[j])) {
				cout << "No\n";
				exit(0);
			} else if(i != j && mat[i][j] == 0 && (abs(s[i]-s[j]) != 1 && s[i] != s[j])) {
				cout << "No\n";
				exit(0);
			}
	cout << "Yes\n" << s;
}
//8 9
//1 2
//1 3
//2 4
//3 4
//4 5
//5 6
//5 8
//6 7
//7 8
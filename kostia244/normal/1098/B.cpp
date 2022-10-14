#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 1000000007ll;
int n, m;
using chmat=vector<vector<char>>;
chmat mat;
int calc(chmat &mat, string &perm, vi &ans) {
	ans.assign(mat.size(), 0);
	int res = 0;
	for(int i = 0; i < mat.size(); i++) {
		int ans1 = 0, ans2 = 0;
		for(int j = 0; j < mat[0].size(); j++) {
			ans1 += mat[i][j] != perm[(2*(i&1)+(j&1))];
		}
		for(int j = 0; j < mat[0].size(); j++) {
			ans2 += mat[i][j] != perm[(2*(i&1)+(j&1)) ^ 1];
		}
		if(ans2 < ans1)
			ans[i]=1;
		res += min(ans1, ans2);
	}
	return res;
}
void get(chmat &mat, string &perm, vi &ans) {
	for(int i = 0; i < mat.size(); i++) {
		for(int j = 0; j < mat[0].size(); j++) {
			mat[i][j] = perm[(2*(i&1)+(j&1)) ^ ans[i]];
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n >> m;
	chmat mat;
	mat.resize(n);
	for(auto &i : mat) {
		i.resize(m);
		for(auto &j : i)
			cin >> j;
	}
	string perm, besto, bestr;
	besto = bestr = perm = "ACGT";
	int boc, brc, c;
	boc = brc = INT_MAX;
	vi anso, bao;
	do {
		c = calc(mat, perm, anso);
		if(boc > c)
			boc = c, besto = perm, bao = anso;
	} while(next_permutation(all(perm)));

	chmat matr(m, vector<char>(n));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			matr[j][i] = mat[i][j];

	vi ansr, bar;
	perm = "ACGT";
	do {
		c = calc(matr, perm, ansr);
		if(brc > c)
			brc = c, bestr = perm, bar = ansr;
	} while(next_permutation(all(perm)));
	if(boc <= brc) {
		get(mat, besto, bao);
	} else {
		get(matr, bestr, bar);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				mat[i][j] = matr[j][i];
	}
	for(int i = 0; i < n; i++, cout << "\n")
		for(int j = 0; j < m; j++)
			cout << mat[i][j];

}
#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

int n, a;
map <int, int> m;

vector <pair<int, int> > v, w;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n;i++) cin >> a, m[a]++;


	for(auto i : m) v.push_back({i.nd, i.st});

	sort(v.begin(), v.end());	

	int j = 0, nr = 0, Res = 0, maxI, maxJ;

	for(int i = 1; i <= n; i++) {

		while(j < v.size() && v[j].st <= i) nr += v[j++].st;

		int extra = ((int) v.size() - j) * i;

		if(i * ((nr + extra) / i) > Res && 1LL * i * i <= 0LL + nr + extra) {
			Res = i * ((nr + extra) / i);
			maxI = i;
			maxJ = (nr + extra) / i;
		}
	}	

	cout << Res << '\n';
	cout << maxI << ' ' << maxJ << '\n';

	nr = 0;
	for(int i = 0; i < v.size() && nr < Res; i++) {
		int need = min(min(v[i].st, Res - nr), maxI);
		nr += need;
		w.push_back({need, v[i].nd});
	}

	sort(w.begin(), w.end(), greater<pair<int, int>> ());

	queue <int> q;
	for(auto i : w)
		for(int j = 0; j < i.st; j++)
			q.push(i.nd);

	vector <vector <int>> ANS = vector < vector <int> > (maxI, vector <int>(maxJ, 0));
	for(int j = 0; j < maxJ; j++)
		for(int i = 0; i < maxI; i++)
			ANS[i][j] = q.front(), q.pop();

	for(int i = 0; i < maxI; i++)
		rotate(ANS[i].begin(), ANS[i].begin() + maxI - i, ANS[i].end());

	for(int i =0;i < maxI; i++)
		for(int j = 0; j < maxJ; j++)
			cout << ANS[i][j] << " \n"[j == maxJ - 1];
}
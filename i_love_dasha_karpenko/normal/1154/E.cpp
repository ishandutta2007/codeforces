#include <bits/stdc++.h>

using namespace std;
#define DIM 200007
#define INF 10E16
#define MAXN 10000007
#define MODULO 1000000007 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pairll;
typedef ll arr[DIM];
typedef pairll parr[DIM];
typedef vector<ll> graph[DIM];
struct pp { ll a, b; };

ll n, k, turn = 1;
arr A, V;
parr R;
set<ll> pos;
set<pairll> skill;
map<ll, ll> N;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		R[i] = { A[i],i };
		pos.insert(i);

		//skill.insert({ A[i],i });
	}
	sort(R + 1, R + 1 + n);
	ll g = n;
	while (!pos.empty()) {
		while (V[R[g].second] != 0)g--;
		pairll p = R[g];
		auto et = pos.find(p.second);
		ll res = 1;
		while (res <= k && et != pos.end()) {
			et++;
			auto ut = et;
			et--;
			if (ut == pos.end())break;
			V[*ut] = turn;


			pos.erase(*ut);
			res++;
			//ll ss = *ut;
			//V[k] = turn;
		}
		res = 1;
		while (res <= k && et != pos.begin()) {
			et--;
			auto ut = et;

			et++;
			if (ut == pos.end())break;
			V[*ut] = turn;

			pos.erase(*ut);
			res++;

		}

		pos.erase(p.second);
		V[p.second] = turn;
		turn = 3 - turn;
	}
	for (int i = 1; i <= n; i++) {
		cout << V[i];
	}
	cout << endl;

}
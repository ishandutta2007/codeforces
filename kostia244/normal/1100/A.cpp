#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int, int>
#define LL long long
#define MAX 100010

int n, k, t, c = 0, cc = 0;
vi D[2];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> k;
	D[1].resize(k + 1, 0);
	D[0].resize(k + 1, 0);
	for(int i = 0; i < n; i++) {
		cin >> t;
		if(t > 0)
			D[0][i%k]++, c++;
		else
			D[1][i%k]++, cc++;
	}
	for(int i = 0; i < k; i++)
		D[0][i] = abs((c - D[0][i]) - (cc - D[1][i]));
	cout << *max_element(D[0].begin(), D[0].end());
}
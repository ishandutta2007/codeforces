#include <bits/stdc++.h>

using namespace std;
#define DIM 200007
#define INF 10E16
#define MAXN 10000007
#define MODULO 998244353 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pairll;
typedef ll arr[DIM];
typedef pairll parr[DIM];
typedef vector<ll> graph[DIM];

ll n;
string s;
arr V;
vector<ll> A, B;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	cin >> s;
	ll l = s.length();
	for (int i = 0; i < l; i++) {
		if (s[i] == '(')A.push_back(i);
		if (s[i] == ')')B.push_back(i);
	}
	ll pos = 0,colour = 1;
	for (int i = 0; i < A.size(); i++) {
		V[A[i]] = colour;
		V[B[pos++]] = colour;
		colour ^= 1;
	}
	for (int i = 0; i < l; i++)cout << V[i];
}
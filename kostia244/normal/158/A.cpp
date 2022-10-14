#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pi pair<int, int>
#define __V vector
#define vi __V<int>
using namespace std;
int n, k, a = 0;
vi p;
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> k;
	p.resize(n);
	for(auto& i : p) cin >> i;
	for(auto& i : p) a += (i >= p[k-1] && i > 0);
	cout << a;
}
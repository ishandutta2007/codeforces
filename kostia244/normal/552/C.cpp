#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<int>
#define pi pair<int, int>
#define mod 1000000007ll

using namespace __gnu_pbds;
using namespace std;
ll w, m;
int f[110];
int main() {
	cin >> w >> m;
	for(int i = 0; m; i++) {
		f[i] = m%w;
		m /= w;
	}
	for(int i = 0; i < 100; i++) {
		if(f[i] == 0 || f[i] == 1) continue;
		f[i] -= w, f[i+1]++;
		if(f[i] == 0 || f[i] == -1) continue;
		return cout << "No", 0;
	}
	return cout << "Yes", 0;

}
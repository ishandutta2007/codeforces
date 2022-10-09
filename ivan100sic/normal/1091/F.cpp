#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, f, hw;
ll a[100005], free_stamina[100005], sol;
string s;

basic_string<int> basin, water_basin, grass_basin;

void get_stamina_lava(ll amt) {
	while (amt > 0) {
		if (water_basin.size() == 0 && grass_basin.size() == 0) {
			sol += (hw ? 4 : 6) * amt;
			return;
		} else if (water_basin.size() && free_stamina[water_basin.back()] == 0) {
			water_basin.pop_back();
		} else if (water_basin.size()) {
			ll w = min(amt, free_stamina[water_basin.back()]);
			free_stamina[water_basin.back()] -= w;
			amt -= w;
			sol += w;
		} else if (grass_basin.size() && free_stamina[grass_basin.back()] == 0) {
			grass_basin.pop_back();
		} else if (grass_basin.size()) {
			ll w = min(amt, free_stamina[grass_basin.back()]);
			free_stamina[grass_basin.back()] -= w;
			amt -= w;
			sol += w;
		}
	}
}

void get_stamina_grass(ll& amt) {
	while (amt > 0) {
		if (basin.size() == 0) {
			return;
		} else if (free_stamina[basin.back()] == 0) {
			basin.pop_back();
		} else {
			ll w = min(amt, free_stamina[basin.back()]);
			free_stamina[basin.back()] -= w;
			amt -= w;
			sol -= 4*w;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	cin >> s;

	for (int i=0; i<n; i++) {
		char x = s[i];
		ll y = a[i];
		if (x == 'G') {
			sol += 5*y;
			free_stamina[i] = y;
			grass_basin += i;
		} else if (x == 'W') {
			hw = 1;
			sol += 3*y;
			free_stamina[i] = y;
			water_basin += i;
		} else if (x == 'L') {
			get_stamina_lava(y);
		}
	}

	// investiraj free staminu u grass
	for (int i=0; i<n; i++)
		if (s[i] == 'G')
			get_stamina_grass(free_stamina[i]);
		else if (s[i] == 'W')
			basin += i;

	// reinvestiraj free staminu
	for (int i=0; i<n; i++)
		sol -= (s[i] == 'W' ? 1 : 2) * free_stamina[i];

	cout << sol << '\n';
}
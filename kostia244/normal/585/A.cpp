#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<ll>
#define pi pair<int, int>
#define all(x) x.begin(), x.end()
#define mod 1000000007ll

using namespace __gnu_pbds;
using namespace std;
int XTCY;

struct lil_m_Fer {
	ll v, p, d;
	void steal() {
		cin >> v >> d >> p;
	}
};
__V<int> eddables_for_breakfest;
int main() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
	cin >> XTCY;
	__V<lil_m_Fer> v(XTCY);
	for(auto& i : v) i.steal();
	for(int lean_iterator = 0; lean_iterator < XTCY; lean_iterator++) {
		if(v[lean_iterator].p >= 0) {
			eddables_for_breakfest.pb(lean_iterator+1);
			ll i_had_a_great_pot = 0;
			for(int dark_sprite_greater_than_sprite = lean_iterator+1; dark_sprite_greater_than_sprite < v.size(); dark_sprite_greater_than_sprite++) {
				if(v[dark_sprite_greater_than_sprite].p < 0) continue;
				v[dark_sprite_greater_than_sprite].p -= (v[lean_iterator].v+i_had_a_great_pot);
				if(v[lean_iterator].v > 0) v[lean_iterator].v--;
				if(v[dark_sprite_greater_than_sprite].p < 0) i_had_a_great_pot += v[dark_sprite_greater_than_sprite].d;
			}
		}
	}
	cout << eddables_for_breakfest.size()<< "\n";
	for(auto& imhigh : eddables_for_breakfest) {
		cout << imhigh << " ";
	}
}
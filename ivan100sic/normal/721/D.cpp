#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k, w;
set<pair<ll, int>> a;

pair<ll, int> loabsval() {
	auto it = a.lower_bound({1, -1});
	pair<ll, int> vr;
	if (it == a.end()) {
		vr = *prev(it);
	} else if (it == a.begin()) {
		vr = *it;		
	} else if (it->first < -prev(it)->first) {
		vr = *it;
	} else {
		vr = *prev(it);
	}
	return vr;
}

pair<ll, int> hiabsval() {
	auto it1 = a.begin();
	auto it2 = prev(a.end());
	if (abs(it1->first) > abs(it2->first))
		return *it1;
	else
		return *it2;
}

void pojacaj() {
	while (k--) {
		auto vr = loabsval();
		a.erase(vr);
		if (vr.first < 0)
			vr.first -= w;
		else
			vr.first += w;
		a.insert(vr);
	}
}

void oslabi() {
	while (k--) {
		auto vr = loabsval();
		a.erase(vr);
		if (vr.first > 0)
			vr.first -= w;
		else
			vr.first += w;
		a.insert(vr);
	}
}

void brisi_nule(int k, int sgn) {
	while (k > 1) {
		k--;
		auto vr = *a.lower_bound({0, -1});
		a.erase(vr);
		vr.first += w;
		a.insert(vr);
	}

	auto vr = *a.lower_bound({0, -1});
	a.erase(vr);
	vr.first -= w*sgn;
	a.insert(vr);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> w;

	int sgn = 1, nullity = 0;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		a.insert({x, i});
		if (x == 0)
			nullity++;
		else if (x < 0)
			sgn *= -1;
	}

	if (sgn < 0 && !nullity) {
		// samo pojacaj brojke, pocev od najmanjih po aps. vr.
		pojacaj();
	} else if (nullity > 0) {
		// mogu li da pobrisem sve nule? ako mogu, to uradim na taj nacin
		// da ostane negativan znak (uvek moze) i onda samo pojacam
		if (nullity <= k) {
			brisi_nule(nullity, sgn);
			k -= nullity;
			pojacaj();
		} else {
			// ne moras nista ni da radis
		}
	} else {
		// nadji element sa najmanjom aps. vr.
		auto vr = loabsval();
		// da li mogu da ga flipujem (da ne ostane 0)
		ll movestoflip = abs(vr.first) / w + 1; 
		if (movestoflip <= k) {
			// do it!
			a.erase(vr);
			if (vr.first < 0) {
				vr.first += w * movestoflip;
			} else {
				vr.first -= w * movestoflip;
			}
			a.insert(vr);
			k -= movestoflip;
			pojacaj();
		} else {
			// da li slucajno mogu da ga napravim na nulu?
			if (k * w == abs(vr.first)) {
				k = 0;
				a.erase(vr);
				vr.first = 0;
				a.insert(vr);
			} else {
				// nista ne mogu da uradim, oslabi niz
				oslabi();
			}
		}
	}

	vector<ll> sol(n);
	for (auto [p, i] : a)
		sol[i] = p;
	for (int i=0; i<n; i++)
		cout << sol[i] << ' ';
	cout << '\n';
}
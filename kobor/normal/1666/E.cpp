#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define all(s) s.begin(), s.end()
#define sz(s) (int)s.size()

#define ii pair<int, int>
#define vii vector<ii>
#define vi vector<int>

const int INF = 1e9;

ii wspolna(ii a, ii b){
	return {max(a.f, b.f), min(a.s, b.s)};
}

void solve(){
	int n, l;
	cin >> l >> n;
		
	vi tab(n);
	//vii bob;
	
	for(int i = 0; i < n; i++){
		cin >> tab[i]; 
	}
	
	//for(int i = 0; i < (n - 1); i++){
	//	bob[i] = {tab[i], tab[i + 1]};
	//}
	
	int L = 0, R = l + 1;
	
	while(R - L > 1){
		int mid = (R + L) / 2;
		
		int last = 0;
		bool ok = true;
		
		for(int i = 1; i < n; i++){
			if(tab[i] - last < mid){
				ok = false;
				break;
			}
			last = max(last + mid, tab[i - 1]);
		}
		
		if(l - last < mid)
			ok = false;
			
		(ok ? L : R) = mid;
	}
	
	int x = L;
	
	L = -1, R = l;
	
	while(R - L > 1){
		int mid = (R + L) / 2;
		
		int last = 0;
		bool ok = true;
		
		for(int i = 1; i < n; i++){
			if(tab[i - 1] - last > mid){
				ok = false;
				break;
			}
			last = min(last + mid, tab[i]);
		}
		
		if(l - last > mid)
			ok = false;
			
		(ok ? R : L) = mid;
	}
	
	int y = R;
	
	// teraz odzyskuje odpowiedz
	
	vii gdzie;
	gdzie.pb({0, 0});
	
	for(int i = 1; i < n; i++){
		auto [pocz, kon] = gdzie.back();
		
		ii nowe_gdzie = {max(pocz + x, tab[i - 1]), min(kon + y, tab[i])};
		assert(nowe_gdzie.f <= nowe_gdzie.s);
		gdzie.pb(nowe_gdzie);
	}
	
	gdzie.pb({l, l});
	
	vii ans;
	for(int i = 0; i < n; i++){
		int kon = gdzie.back().f;
		ii para = {kon - y, kon - x};
		
		gdzie.pop_back();
		
		ii siema = wspolna(para, gdzie.back());
		assert(siema.f <= siema.s);
		
		int pkt = siema.f;
		gdzie.pop_back();
		gdzie.push_back({pkt, pkt});
		ans.pb({pkt, kon});
	}
	
	reverse(all(ans));
	
	for(auto & u : ans){
		cout << u.f << ' ' << u.s << '\n';
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int testy = 1;
	//cin >> testy;
	
	while(testy--){
		solve();
	}
	
	return 0;
}
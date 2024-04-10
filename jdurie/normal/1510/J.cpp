#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;

#define G(x) ll x; cin>>x;
#define F(i,l, r) for (ll i=(l); i<(r); ++i)
#define all(x) begin(x), end(x)
#define K first
#define V second

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s1; cin >> s1;
	vector<ll> ans;
	for(ll st = 0; st <= 3; st++){
		bool good = true;
		string s = s1;
		if(st) s += "_#";
		ll n = s.size();
		ans.clear();
		if(st == 0){
			ll c = 0;
			for(ll i = 0; i < n; i++){
				if(s[i] == '#'){
					c++;
				}else{
					if(!c){
						good = false;
						break;
					}	
					ans.push_back(c);
					c = 0;
				}
			}
			if(c) ans.push_back(c);
			else good = false;
		}
		else{
			ll c = 0, w = 1;
			for(ll i = 0; i < n; i++){
				if(s[i] == '#'){
					if(~w){
						if(st == 1){
							if(w % 2){
								good = false;
								break;
							}
							while(w > 2){
								ans.push_back(1);
								w -= 2;
							}
						}
						else if(st == 2){
							if(w <= 2 || w == 4){
								good = false;
								break;
							}
							if(w % 2 == 0){
								w -= 3;
								ans.push_back(2);
							}
							while(w > 3){
								ans.push_back(1);
								w -= 2;	
							}
						}else{
							if(w < 4){
								good = false;
								break;
							}
							if(w % 2 == 1){
								w -= 3;
								ans.push_back(2);
							}
							while(w > 4){
								ans.push_back(1);
								w -= 2;
							}
						}
					}
					w = -1;
					c++;
				}else{
							
					if(w == -1){
						w = 1;
						ans.push_back(c+st);
						c = 0;
					}else w++;
				}
			}
		}
		if(!good){
			continue;
		}
		cout << ans.size() << endl;
		for(ll i : ans) cout << i << " ";
		cout << endl;
		/*
		vector<string> vs;
		ll su = -1;
		for(ll i : ans){
			su += i+1;
		}
		ll leftover = (ll)s1.length()-su;
		vs.push_back("");
		if(leftover >= 1) vs.push_back("_");
		if(leftover >= 2) vs.push_back("__");
		if(leftover >= 3) vs.push_back("___");
		if(leftover >= 4 || leftover < 0) cout << "WRONG" << endl;
		for(ll i : ans){
			for(ll e = 0; e < i; e++){
				for(ll ind = 0; ind < vs.size(); ind++){
					vs[ind] += '#';
				}
			}
			for(ll ind = 0; ind < vs.size(); ind++){
				vs[ind] += '_';
			}
		}
		for(ll ind = 0; ind < vs.size(); ind++){
			while(vs[ind].length() < s1.length()){
					vs[ind] += '_';
			}
			while(vs[ind].length() > s1.length()) vs[ind].pop_back();
		}
		cout << leftover << " " << vs[0] << endl;
		for(ll i = 0; i < s1.length(); i++){
			if(s1[i] == '#'){	
				for(ll ind = 0; ind < vs.size(); ind++){
					if(vs[ind][i] == '_'){
						cerr << "WRONG" << endl;
						cerr << vs[ind] << endl;
						cerr << s1 << endl;
						return 0;
					}
				}
			}else{
				bool good = false;
				for(ll ind = 0; ind < vs.size(); ind++){
					if(vs[ind][i] != '#'){
						good = true;
					}
				}
				if(!good){
					cerr << "WRONG1" << endl;
					cerr << s1 << endl;
					return 0;
				}
			}
		}
		*/
		return 0;
	}
	cout << -1 << endl;
}
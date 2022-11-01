#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t, n, m, k;
vector<pair<int, ll> > v, w; 

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		v.clear(), w.clear();
		for(int i = 1;i <= n;i++){
			int x;
			scanf("%d", &x);
			ll val = 1;
			while(x % m == 0) val *= m, x /= m;
			if(!v.empty() && v.back().first == x) v[v.size() - 1].second += val;
			else v.push_back({x, val});
		}
		scanf("%d", &k);
		swap(v, w);
		for(int i = 1;i <= k;i++){
			int x;
			scanf("%d", &x);
			ll val = 1;
			while(x % m == 0) val *= m, x /= m;
			if(!v.empty() && v.back().first == x) v[v.size() - 1].second += val;
			else v.push_back({x, val});
		}
		if(v.size() != w.size()) puts("No");
		else{
			bool tag = false;
			for(int i = 0;i < v.size();i++) if(v[i] != w[i]) tag = true;
			puts(tag ? "No" : "Yes"); 
		}
	}
}
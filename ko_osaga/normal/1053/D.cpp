#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MAXN = 2000005;
const lint mod = 1e9 + 7;

int n, a[MAXN];
int che[MAXN];
int cnt[MAXN];
int yielder[MAXN];

lint ipow(lint x, lint p){
	lint ret = 1, piv = x;
	while(p){
		if(p & 1) ret = ret * piv % mod;
		piv = piv * piv % mod;
		p >>= 1;
	}
	return ret;
}

vector<int> factor(int v){
	if(v == 1){
		return vector<int>();
	}
	vector<int> ans;
	while(v > 1){
		ans.push_back(che[v]);
		v /= che[v];
	}
	return ans;
}

int main(){
	scanf("%d",&n);
	for(int i=2; i<MAXN; i++){
		for(int j=i; j<MAXN; j+=i){
			if(!che[j]) che[j] = i;
		}
	}
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	sort(a, a+n);
	set<int> s;
	int useless = 0;
	queue<int> que;
	for(int i=0; i<n; ){
		int e = i;
		while(e < n && a[i] == a[e]) e++;
		if(e - i == 1) s.insert(a[i]);
		else{
			if(e - i >= 3) useless = 1;
			que.push(a[i] - 1);
			que.push(a[i]);
		}
		i = e;
	}
	vector<int> will_check;
	while(!que.empty()){
		auto x = que.front();
		will_check.push_back(x);
		que.pop();
		auto v = factor(x);
		for(int i=0; i<v.size(); ){
			int e = i;
			while(e < v.size() && v[i] == v[e]) e++;
			if(cnt[v[i]] < e - i){
				cnt[v[i]] = e - i;
			}
			if(cnt[v[i]] && s.find(v[i]) != s.end()){
				s.erase(v[i]);
				que.push(v[i] - 1);
			}
			i = e;
		}
	}
	for(auto &i : s){
		cnt[i] = 1;
	}
	lint ans = 1;
	for(int i=2; i<MAXN; i++){
		ans *= ipow(i, cnt[i]);
		ans %= mod;
	}
	if(!useless){
		for(int i=0; i<n; ){
			int e = i;
			while(e < n && a[e] == a[i]) e++;
			if(e - i == 2) a[i]--;
			else if(s.find(a[i]) == s.end()) a[i]--;
			i = e;
		}
		for(int i=0; i<n; i++){
			auto x = factor(a[i]);
			for(int j=0; j<x.size(); ){
				int e = j;
				while(e < x.size() && x[e] == x[j]) e++;
				if(cnt[x[j]] == e - j) yielder[x[j]]++;
				j = e;
			}
		}
		for(int i=0; i<n; i++){
			auto x = factor(a[i]);
			bool useful = 0;
			for(int j=0; j<x.size(); ){
				int e = j;
				while(e < x.size() && x[e] == x[j]) e++;
				if(cnt[x[j]] == e - j && yielder[x[j]] == 1) useful = 1;
				j = e;
			}
			if(!useful) useless = 1;
		}
	}
	ans += useless;
	ans %= mod;
	cout << ans << endl;
}
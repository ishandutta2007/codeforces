#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using lint = long long;
const int MAXN = 200005;
const int mod = 1e9 + 7;

int n, m;
char s[MAXN], t[MAXN];
deque<pi> ds, dt;

vector<pi> Special(deque<pi> a, deque<pi> b){
	int l = (b.size() + 1) / 2;
	int cnt = 0;
	for(int i=0; i<l; i++){
		cnt += b[i].second;
	}
	vector<pi> ans = {pi(a[0].second, cnt)};
	auto a0 = a[0];
	auto a1 = a[1];
	a.clear();
	for(int i=0; i<l; i++){
		a.push_back(b[0]);
		b.pop_front();
	}
	b[0].second += a0.second;
	a[a.size()-1].second += a1.second;
	int ptr1 = 0, ptr2 = 0;
	for(int i=0; i+1<max(a.size(), b.size()); i++){
		if(i < a.size()) ptr1 += a[i].second;
		if(i < b.size()) ptr2 += b[i].second;
		ans.push_back(pi(ptr1, ptr2));
		swap(ptr1, ptr2);
	}
	return ans;
}

vector<pi> Do(deque<pi> a, deque<pi> b){
	vector<pi> ans;
	while(a.size() > 2 && b.size() > 2){
		ans.push_back(pi(a[0].second, b[0].second));
		swap(a.front(), b.front());
		a[1].second += a[0].second;
		b[1].second += b[0].second;
		a.pop_front();
		b.pop_front();
	}
	if(a.size() == 2 && (b.size() % 4 == 1 || b.size() % 4 == 2) && b.size() > 4){
		auto k = Special(a, b);
		for(auto &i : k) ans.push_back(i);
		return ans;
	}
	if((a.size() % 4 == 1 || a.size() % 4 == 2) && b.size() == 2 && a.size() > 4){
		auto k = Special(b, a);
		for(auto &i : k) ans.push_back(pi(i.second, i.first));
		return ans;
	}
	while(a.size() > 1 && b.size() > 1){
		ans.push_back(pi(a[0].second, b[0].second));
		swap(a.front(), b.front());
		a[1].second += a[0].second;
		b[1].second += b[0].second;
		a.pop_front();
		b.pop_front();
	}
	if(a.size() == 1 && b.size() == 1) return ans;
	auto SEX = [&](){
		auto fu = b[0];
		int lsz = 0, rsz = b[0].second;
		b.pop_front();
		int half = (a.size() + 1) / 2;
		for(int i=0; i<half; i++){
			lsz += a[0].second;
			b.push_back(a[0]);
			a.pop_front();
		}
		ans.push_back(pi(lsz, rsz));
		if(half % 2 == 1){
			a[0].second += fu.second;
		}
		else{
			a.push_front(fu);
		}
	};
	if(a.size() > b.size()){
		SEX();
	}
	else{
		swap(a, b);
		SEX();
		swap(ans[ans.size()-1].first, ans[ans.size()-1].second);
		swap(a, b);
	}
	int ptr1 = 0, ptr2 = 0;
	for(int i=0; i+1<max(a.size(), b.size()); i++){
		if(i < a.size()) ptr1 += a[i].second;
		if(i < b.size()) ptr2 += b[i].second;
		ans.push_back(pi(ptr1, ptr2));
		swap(ptr1, ptr2);
	}
	return ans;
}

int main(){
	scanf("%s %s",s,t);
	n = strlen(s); m = strlen(t);
	for(int i=0; i<n; ){
		int e = i;
		while(e < n && s[i] == s[e]) e++;
		ds.push_back(pi(s[i], e - i));
		i = e;
	}
	for(int i=0; i<m; ){
		int e = i;
		while(e < m && t[i] == t[e]) e++;
		dt.push_back(pi(t[i], e - i));
		i = e;
	}
	auto nah = [&](int c){
		if(c == 'a') return 'b';
		else return 'a';
	};
	vector<pi> ans;
	if(ds.front().first != dt.front().first){
		ans = Do(ds, dt);
	}
	else{
		int val = nah(ds.front().first);
		ds.push_front(pi(val, 0));
		ans = Do(ds, dt);
		ds.pop_front();
		dt.push_front(pi(val, 0));
		auto nans = Do(ds, dt);
		dt.pop_front();
		if(ans.size() > nans.size()) ans = nans;
	}
	cout << ans.size() << endl;
	if(1ll * (int)ans.size() * (n + m) <= 5000000){
		string as = s, at = t;
		for(int i=0; i<ans.size(); i++){
			auto a = as.substr(0, ans[i].first);
			auto b = as.substr(ans[i].first, as.size() - ans[i].first);
			auto c = at.substr(0, ans[i].second);
			auto d = at.substr(ans[i].second, at.size() - ans[i].second);
			as = c + b;
			at = a + d;
		}
		assert(as.size());
		assert(at.size());
		for(int i=1; i<as.size(); i++) assert(as[i] == as[i-1]);
		for(int i=1; i<at.size(); i++) assert(at[i] == at[i-1]);
	}
	for(auto &i : ans) printf("%d %d\n", i.first, i.second);
}
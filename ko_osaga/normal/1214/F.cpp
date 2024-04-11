#include <bits/stdc++.h>
using namespace std;
using lint = long long;
typedef pair<lint,lint> pi;
const int MAXN = 200005;

vector<pi> v;

struct level_structure{
	vector<lint> v;
	lint fr = 0;
	lint sum_odd = 0, sum_even = 0;
	lint current_odd_gamma = 0;
	lint removed_odd_gamma = 0;
	lint current_even_gamma = 0;
	lint removed_even_gamma = 0;
	priority_queue<pi, vector<pi>, greater<pi> > pqOdd, pqEven; // valid till fr <= i.second
	void push(lint x){
		if(v.size() & 1){
			sum_odd += x;
			if(v.size() >= 2){
				current_odd_gamma += 2 * v[v.size() - 1] - x - v[v.size() - 2];
				pqOdd.emplace(current_odd_gamma, v.size() - 2);
			}
		}
		else{
			sum_even += x;
			if(v.size() >= 2){
				current_even_gamma += 2 * v[v.size()-1] - x - v[v.size() - 2];
				pqEven.emplace(current_even_gamma, v.size() - 2);
			}
		}
		v.push_back(x);
	}
	void pop(){
		if(fr & 1){
			sum_odd -= v[fr];
			if(fr + 2 < v.size()) removed_odd_gamma += 2 * v[fr+1] - v[fr+2] - v[fr]; 
		}
		else{
			sum_even -= v[fr];
			if(fr + 2 < v.size()) removed_even_gamma += 2 * v[fr+1] - v[fr+2] - v[fr]; 
		}
		while(!pqOdd.empty() && pqOdd.top().second < fr) pqOdd.pop();
		while(!pqEven.empty() && pqEven.top().second < fr) pqEven.pop();
		fr++; 
	}
	lint query(){
		if(fr % 2 == v.size() % 2) return abs(sum_even - sum_odd);
		lint ans = 0;
		if(v.size() & 1) ans = sum_even - sum_odd - v[fr];
		else ans = sum_odd - sum_even - v[fr];
		if(fr & 1){
			if(!pqOdd.empty()) ans += min(0ll, pqOdd.top().first - removed_odd_gamma);
		}
		else{
			if(!pqEven.empty()) ans += min(0ll, pqEven.top().first - removed_even_gamma);
		}
		return ans;
	}
}ds[3 * MAXN];

lint prv_ans[3 * MAXN];

struct ev{
	lint pos;
	int from, type;
	bool operator<(const ev &e)const{
		return pos < e.pos;
	}
};

vector<ev> orig;
int nxt[MAXN];

int main(){
	lint n;
	int m;
	scanf("%lld %d",&n,&m);
	for(int i=0; i<m; i++){
		int x;
		scanf("%d",&x);
		v.emplace_back(x%n, +1);
		orig.push_back({x % n, i + 1, +1});
	}
	for(int i=0; i<m; i++){
		int x;
		scanf("%d",&x);
		v.emplace_back(x%n, -1);
		orig.push_back({x % n, i + 1, -1});
	}
	sort(v.begin(), v.end());
	sort(orig.begin(), orig.end());
	v.resize(2 * v.size());
	copy(v.begin(), v.begin() + v.size() / 2, v.begin() + v.size() / 2);
	for(int i=v.size()/2; i<v.size(); i++) v[i].first += n;
	lint f = m;
	for(auto &i : v){
		lint assign_floor = max(f, f + i.second);
		f += i.second;
		i.second = assign_floor;
	}
	lint ans = 1e18;
	int p1 = 0, p2 = 0; lint cur = 0;
	vector<lint> event;
	for(int i=0; i<v.size(); i++){
		event.push_back(v[i].first - n + 1);
		event.push_back(v[i].first + 1);
	}
	event.push_back(0);
	for(auto &i : event){
		i = max(i, 0ll);
		i = min(i, n - 1);
	}
	sort(event.begin(), event.end());
	event.resize(unique(event.begin(), event.end()) - event.begin());
	int why = -1;
	for(auto &i : event){
		while(p2 < v.size() && v[p2].first < i+n){
			cur -= prv_ans[v[p2].second];
			ds[v[p2].second].push(v[p2].first);
			cur += (prv_ans[v[p2].second] = ds[v[p2].second].query());
			p2++;
		}
		while(p1 < v.size() && v[p1].first < i){
			cur -= prv_ans[v[p1].second];
			ds[v[p1].second].pop();
			cur += (prv_ans[v[p1].second] = ds[v[p1].second].query());
			p1++;
		}
		if(ans > cur){
			ans = cur;
			why = i;
		}
	}
	cout << ans << endl;
	for(auto &i : orig){
		if(i.pos < why) i.pos += n;
	}
	sort(orig.begin(), orig.end());
	vector<int> l, r;
	for(int i=0; i<orig.size(); i++){
		if(orig[i].type == +1) l.push_back(orig[i].from);
		else r.push_back(orig[i].from);
	}
	for(int i=0; i<m; i++){
		nxt[l[i]] = r[i];
	}
	for(int i=1; i<=m; i++) printf("%d ", nxt[i]);
}
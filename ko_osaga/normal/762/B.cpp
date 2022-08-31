#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;

int a, b, c, m;

vector<int> u, p, r;
lint ret, ans;

int main(){
	cin >> a >> b >> c >> m;
	for(int i=0; i<m; i++){
		int x;
		string s;
		cin >> x >> s;
		if(s == "USB") u.push_back(x);
		else p.push_back(x);
	}
	sort(u.begin(), u.end());
	sort(p.begin(), p.end());
	int p1 = 0, p2 = 0;
	for(int i=0; i<a; i++){
		if(p1 < u.size()){
			ret++;
			ans += u[p1++];
		}
	}
	for(int i=0; i<b; i++){
		if(p2 < p.size()){
			ret++;
			ans += p[p2++];
		}
	}
	for(int i=p1; i<u.size(); i++) r.push_back(u[i]);
	for(int i=p2; i<p.size(); i++) r.push_back(p[i]);
	sort(r.begin(), r.end());
	for(int i=0; i<c && i<r.size(); i++){
		ret++;
		ans += r[i];
	}
	printf("%lld %lld", ret, ans);
}
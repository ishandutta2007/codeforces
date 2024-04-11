#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

vector<tuple<int, int, int>> jaji;
vector<tuple<int, int, int, int>> boji;
int piv;

void add3cyc(int x, int y, int z){
	jaji.emplace_back(x, y, z);
}

void add4cyc(int x, int y, int z, int w){
	boji.emplace_back(x, y, z, w);
}

vector<int> solve(int x){
	if(x == 2){
		vector<int> v;
		for(int i=0; i<2; i++) v.push_back(++piv);
		return v;
	}
	if(x == 3){
		vector<int> v;
		for(int i=0; i<3; i++){
			v.push_back(++piv);
		}
		for(int i=0; i<2; i++) add3cyc(v[0], v[1], v[2]);
		return v;
	}
	if(x == 4){
		vector<int> v;
		for(int i=0; i<4; i++){
			v.push_back(++piv);
		}
		add3cyc(v[0], v[1], v[2]);
		add3cyc(v[0], v[1], v[3]);
		add3cyc(v[0], v[2], v[3]);
		add3cyc(v[1], v[2], v[3]);
		return v;
	}
	if(x == 5){
		vector<int> v;
		for(int i=0; i<5; i++) v.push_back(++piv);
		add3cyc(v[4], v[3], v[1]);
		add3cyc(v[2], v[0], v[4]);
		add4cyc(v[3], v[4], v[1], v[2]);
		add4cyc(v[3], v[2], v[1], v[0]);
		add3cyc(v[3], v[1], v[0]);
		add3cyc(v[2], v[0], v[4]);
		return v;
	}
	if(x == 6){
		vector<int> a = solve(2);
		vector<int> b = solve(2);
		vector<int> c = solve(2);
		add3cyc(a[0], a[1], b[0]);
		add3cyc(a[0], a[1], b[1]);
		add3cyc(b[0], b[1], c[0]);
		add3cyc(b[0], b[1], c[1]);
		add3cyc(c[0], c[1], a[0]);
		add3cyc(c[0], c[1], a[1]);
		add4cyc(a[0], b[0], a[1], b[1]);
		add4cyc(b[0], c[0], b[1], c[1]);
		add4cyc(c[0], a[0], c[1], a[1]);
		vector<int> r;
		for(auto &v : {a, b, c}){
			for(auto &w : v) r.push_back(w);
		}
		return r;
	}
	vector<int> l, r;
	if(x % 2 == 1){
		if(x % 4 == 3){
			l = solve(x / 2 + 1);
			r = solve(x / 2);
		}
		else{
			l = solve(x / 2);
			r = solve(x / 2 + 1);
		}
		for(int i=0; i<l.size(); i+=2){
			for(int j=0; j<2*r.size(); j+=2){
				add4cyc(l[i], r[j % r.size()], l[i+1], r[(j+1)%r.size()]);
			}
		}
	}
	else{
		if(x % 4 == 2){
			l = solve(x / 2 - 1);
			r = solve(x / 2 + 1);
		}
		else{
			l = solve(x / 2);
			r = solve(x / 2);
		}
		for(int i=0; i<l.size(); i+=2){
			for(int j=0; j<r.size(); j+=2){
				for(int k=0; k<2; k++) add4cyc(l[i], r[j], l[i+1], r[j+1]);
			}
		}
	}
	vector<int> v;
	for(auto &i : l) v.push_back(i);
	for(auto &i : r) v.push_back(i);
	return v;
}

int main(){
	int n;
	cin >> n;
	solve(n);
	cout << jaji.size() + boji.size() << endl;
	for(auto &i : jaji) printf("3 %d %d %d\n", get<0>(i), get<1>(i), get<2>(i));
	for(auto &i : boji) printf("4 %d %d %d %d\n", get<0>(i), get<1>(i), get<2>(i), get<3>(i));
}
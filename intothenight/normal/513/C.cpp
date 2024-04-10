#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace chrono;
#define all(a) a.begin(), a.end()
#define sz(x) (int(x.size()))
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef vector<string> vs;
template<class T1, class T2>
istream &operator>>(istream &in, pair<T1, T2> &P){
	in >> P.first >> P.second;
	return in;
}
template<class T1, class T2>
ostream &operator<<(ostream &out, pair<T1, T2> &P){
	out << "(" << P.first << ", " << P.second << ")";
	return out;
}
template<class T>
istream &operator>>(istream &in, vector<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<class T>
ostream &operator<<(ostream &out, vector<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(15);
	int n;
	cin >> n;
	vector<pii> a(n);
	vector<double> p(n);
	int MIN = 2e9, MAX = 0;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		p[i] = 1.0 / (a[i].second - a[i].first + 1);
		MIN = min(MIN, a[i].first), MAX = max(MAX, a[i].second);
	}
	double res = 0;
	for(int x = MIN; x <= MAX; x ++){
		for(int i = 0; i < n; i ++) if(a[i].first <= x && x <= a[i].second){// Second max (x)
			for(int j = 0; j < n; j ++) if(j != i && a[j].second >= x){ // Maximum
				double temp = a[j].second - max(x + (j > i), a[j].first) + 1;
				for(int k = 0; k < n; k ++){
					if(k != i && k != j){
						if(a[k].first <= x){
							temp *= min(x - (k < i), a[k].second) - a[k].first + 1;
						}
						else{
							temp = 0;
							break;
						}
					}
				}
				res += temp * x;
			}
		}
	}
	cout << res * accumulate(all(p), 1.0, multiplies{}) << "\n";
	return 0;
}
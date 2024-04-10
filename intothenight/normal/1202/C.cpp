#include<bits/stdc++.h>
#include<chrono>
#pragma GCC optimize("Ofast")
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
	int tt;
	cin >> tt;
	vector<pii> dr({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});
	auto conv = [](char c){
		switch(c){
		case 'W':
			return 0;
		case 'S':
			return 1;
		case 'A':
			return 2;
		default:
			return 3;
		}
	};
	auto overlap = [](pii A, pii B){
		return A.second > B.first && A.first < B.second;
	};
	while(tt --){
		string s;
		cin >> s;
		int maxx = 0, maxy = 0, minx = 0, miny = 0;
		pii xmax(0, 0), ymax(0, 0), xmin(0, 0), ymin(0, 0);
		pii cur(0, 0);
		for(int i = 1; i <= sz(s); i ++){
			cur.first += dr[conv(s[i - 1])].first, cur.second += dr[conv(s[i - 1])].second;
			if(cur.first > maxx){
				maxx = cur.first;
				xmax = {i, i};
			}
			else if(cur.first == maxx){
				xmax.second = i;
			}
			if(cur.first < minx){
				minx = cur.first;
				xmin = {i, i};
			}
			else if(cur.first == minx){
				xmin.second = i;
			}
			if(cur.second > maxy){
				maxy = cur.second;
				ymax = {i, i};
			}
			else if(cur.second == maxy){
				ymax.second = i;
			}
			if(cur.second < miny){
				miny = cur.second;
				ymin = {i, i};
			}
			else if(cur.second == miny){
				ymin.second = i;
			}
		}
		ll X1 = maxx - minx + 1, X2 = X1, Y1 = maxy - miny + 1, Y2 = Y1;
		if(!overlap(xmax, xmin) && maxx > minx + 1){
			X2 --;
		}
		if(!overlap(ymax, ymin) && maxy > miny + 1){
			Y2 --;
		}
		cout << min({X1 * Y1, X1 * Y2, X2 * Y1}) << "\n";
	}
	return 0;
}
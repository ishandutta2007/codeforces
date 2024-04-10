#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F first
#define S second

const long long MAX = 4294967295;

long long n, m, k;
string s;
vector< pair<long long, long long> > v;
int main(){
	v.pb({1, 0});
	cin >> n;
	while (n--){
		cin >> s;
		if(s == "for"){
			cin >> m;
			v.pb({m, 0});
		}
		else if(s == "add"){
			v.back().S++;
		}
		else{
			k = v.back().F * v.back().S;
			v.pop_back();
			v.back().S += k;
		}
		if(v.back().S > MAX){
			cout << "OVERFLOW!!!";
			return 0;
		}
	}
	if(v[0].S > MAX){
		cout << "OVERFLOW!!!";
		return 0;
	}
	cout << v[0].S;
	return 0;
}
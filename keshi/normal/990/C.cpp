#include <bits/stdc++.h>
using namespace std;

bool check(string s){
	int p = 0;
	bool k = 0;
	for (int i=0; i<s.size(); i++){
		if (s[i] == '('){
			p++;
		}
		else{
			p--;
		}
		if (p < 0){
			k = 1;
		}
	}
	p = 0;
	for (int i=s.size() - 1; i > -1; i--){
		if (s[i] == ')'){
			p++;
		}
		else{
			p--;
		}
		if (p < 0 && k){
			return 0;
		}
	}
	return 1;
 }

int cal(string s){
	int p = 0;
	for (int i=0; i<s.size(); i++){
		if (s[i] == '('){
			p++;
		}
		else{
			p--;
		}
	}
	return p;
}

map<int, int> a;
map<int, int> b;
vector <int> v;

long long n, l, ans, c;
string t;

int main(){
	
	cin >> n;
	while (n--){
		cin >> t;
		if (check(t)){
			l = cal(t);
			if (l >= 0){
				if (!a[l]){
					v.push_back(l);
				}
				a[l]++;
			}
			if (l <= 0){
				b[-l]++;
			}
		}
	}
	for (int i=0; i<v.size(); i++){
		c = a[v[i]];
		c *= b[v[i]];
		ans += c;
	}
	
	cout << ans;
	return 0;
}
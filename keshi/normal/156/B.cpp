#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;

#define ll long long

ll f(string sa){
	ll aa = 0;
	for(ll i = 1; i < sa.size(); i++){
		aa = aa * 10 + int(sa[i] - '0');
	}
	return aa;
}

ll n, m, p[MAXN], c[MAXN], t, o, l;
bool e[MAXN], tr, li;
string s;

int main(){
	cin >> n >> m;
	
	for(ll i = 0; i < n; i++){
		cin >> s;
		if(s[0] == '+'){
			e[i] = 1;
		}
		p[i] = f(s);
		if(e[i]){
			c[p[i]]++;
		}
		else{
			c[p[i]]--;
			t++;
		}
	}
	
	
	for(ll i = 1; i <= n; i++){
		if(c[i] + t == m){
			o++;
			l = i;
		}
	}
	
	for(ll i = 0; i < n; i++){
		tr = c[p[i]] + t == m;
		li = 0;
		if(o > 1 || (o == 1 && l != p[i])){
			li = 1;
		}
		if(!e[i]){
			swap(tr, li);
		}
		if(tr && !li){
			cout << "Truth";
		}
		else if(!tr && li){
			cout << "Lie";
		}
		else{
			cout << "Not defined";
		}
		cout << endl;
	}
	
	return 0;
}
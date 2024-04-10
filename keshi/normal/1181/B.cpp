#include <bits/stdc++.h>
using namespace std;


int l, r;
string s, t;

bool big(string a, string b){
	if(b.size() > a.size()){
		return 0;
	}
	if(b.size() < a.size()){
		return 1;
	}
	return b < a;
}

string sum(int a){
	int b;
	b = l - a;
	int o, p, u, y, j;
	y = abs(a - b);
	string c, d;
	u = 0;
	for(int i = max(a, b) - 1; i > -1; i--){
		j = i - y;
		p = 0;
		o = 0;
		if(a > b){
			o = s[i] - '0';
			if(j >= 0){
				p = s[j + a] - '0';	
			}
			//cout << i << ' ' << j + a << endl;
		}
		else{
			if(j >= 0){
				o = s[j] - '0';	
			}
			p = s[i + a] - '0';
			//cout << j << ' ' << i + a << endl;
		}
		u += o + p;
		c += '0' + u % 10;
		u /= 10;
	}
	if(u){
		c += '0' + u;	
	}
	for(int i = c.size() - 1; i > -1; i--){
		d += c[i];
	}
	return d;
}
int main(){
	cin >> l >> s;
	r = l / 2;
	while(s[r] == '0'){
		r++;
	}
	t = sum(r);
	r = l / 2;
	while(s[r] == '0'){
		r--;
	}
	if(big(t, sum(r))){
		t = sum(r);
	}
	
	r = (l + 1) / 2;
	while(s[r] == '0'){
		r++;
	}
	if(big(t, sum(r))){
		t = sum(r);
	}
	r = (l + 1) / 2;
	while(s[r] == '0'){
		r--;
	}
	if(big(t, sum(r))){
		t = sum(r);
	}
	cout << t;
	return 0;
}
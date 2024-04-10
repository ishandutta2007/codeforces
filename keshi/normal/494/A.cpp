#include <bits/stdc++.h>
using namespace std;
int o, c, h, j;
string s, d;

bool check(){
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '('){
			c++;
			d += s[i];
		}
		else if(s[i] == ')'){
			c--;
			d += s[i];
		}
		else{
			if(i != j){
				d += ')';
				if(c < 1){
					return 0;
				}
			}
			else{
				for(int e = 0; e < o - h + 1; e++){
					d += ')';
				}
				if(c < o - h + 1 || o - h + 1 <= 0){
					return 0;
				}
			}
		}
	}
	c = 0;
	for(int i = 0; i < d.size(); i++){
		if(d[i] == '('){
			c++;
		}
		else{
			c--;
		}
		if(c < 0){
			return 0;
		}
	}
	if(c != 0){
		return 0;
	}
	return 1;
}

int main(){
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '('){
			o++;
		}
		else if(s[i] == ')'){
			o--;
		}
		else{
			h++;
			j = i;
		}
	}
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '('){
			c++;
		}
		else if(s[i] == ')'){
			c--;
		}
		else{
			if(i != j){
				if(c < 1){
					cout << -1;
					return 0;
				}
			}
			else{
				if(c < o - h + 1 || o - h + 1 <= 0){
					cout << -1;
					return 0;
				}
			}
		}
	}
	if(!check()){
		cout << -1;
		return 0;
	}
	for(int i = 1; i < h; i++){
		cout << 1 << endl;
	}
	cout << o - h + 1;
	return 0;
}
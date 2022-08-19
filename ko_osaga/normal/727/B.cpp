#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int solve(string y){
	int ret = 0;
	if(y.size() >= 3 && y[y.size()-3] == '.'){
		for(auto &i : y){
			if(i <= '9' && i >= '0') ret =ret * 10 + i - '0';
		}
		return ret;
	}
	else{
		for(auto &i : y){
			if(i <= '9' && i >= '0') ret = ret * 10 + i - '0';
		}
		return ret * 100;
	}
}

int main(){
	string s, aux;
	cin >> s;
	lint ret = 0;
	for(auto &i : s){
		if(i <= '9' && i >= '0'){
			aux.push_back(i);
		}
		else if(i == '.') aux.push_back(i);
		else{
			if(aux.size()) ret += solve(aux);
			aux.clear();
		}
	}
	if(aux.size()) ret += solve(aux);
	if(ret % 100 == 0){
		ret /= 100;
		string s;
		for(int i=0; ret; i++){
			s.push_back(ret % 10 + '0');
			if(s.size() % 4 == 3) s.push_back('.');
			ret /= 10;
		}
		if(s.back() == '.') s.pop_back();
		reverse(s.begin(), s.end());
		cout << s;
	}
	else{
		string s;
		s.push_back(ret % 10 + '0');
		ret /= 10;
		s.push_back(ret % 10 + '0');
		ret /= 10;
		s.push_back('.');
		if(ret == 0) s.push_back('0');
		for(int i=0; ret; i++){
			s.push_back(ret % 10 + '0');
			if(s.size() % 4 == 2) s.push_back('.');
			ret /= 10;
		}
		if(s.back() == '.') s.pop_back();
		reverse(s.begin(), s.end());
		cout << s;
	}
}
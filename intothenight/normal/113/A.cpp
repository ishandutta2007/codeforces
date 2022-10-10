#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<string> word({"lios", "liala", "etr", "etra", "initis", "inites"});
	auto valid = [&](string &s){
		return any_of(word.begin(), word.end(), [&](string &t){return s.size() >= t.size() && s.substr(s.size() - t.size(), t.size()) == t;});
	};
	auto mus = [&](string &s){
		for(int i = 0; i < 6; i += 2){
			if(s.size() >= word[i].size() && s.substr(s.size() - word[i].size(), word[i].size()) == word[i]){
				return true;
			}
		}
		return false;
	};
	auto type = [&](string &s){
		for(int i = 0; i < 2; i ++){
			for(int j = 0; j < 2; j ++){
				if(s.size() >= word[2 * i + j].size() && s.substr(s.size() - word[2 * i + j].size()) == word[2 * i + j]){
					return i;
				}
			}
		}
		return 2;
	};
	string s;
	cin >> s;
	if(!valid(s)){
		cout << "NO\n";
		return 0;
	}
	bool gender = mus(s);
	vector<int> types{type(s)};
	while(cin >> s){
		if(!valid(s)){
			cout << "NO\n";
			return 0;
		}
		if(gender != mus(s)){
			cout << "NO\n";
			return 0;
		}
		types.push_back(type(s));
	}
	if(types.size() == 1){
		cout << "YES\n";
		return 0;
	}
	while(!types.empty() && types.back() == 2){
		types.pop_back();
	}
	if(types.empty() || types.back() != 1){
		cout << "NO\n";
		return 0;
	}
	types.pop_back();
	while(!types.empty() && types.back() == 0){
		types.pop_back();
	}
	if(types.empty()){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
	return 0;
}
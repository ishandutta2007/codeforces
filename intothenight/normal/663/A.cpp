#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	string temp;
	getline(cin, temp);
	istringstream in(temp);
	vector<string> s;
	while(in >> temp){
		s.push_back(temp);
	}
	int n = stoi(s.back());
	vector<int> pos{0}, neg;
	for(auto i = 2; i < (int)s.size() - 1; i += 2){
		if(s[i - 1] == "+"){
			pos.push_back(i);
		}
		else{
			neg.push_back(i);
		}
	}
	if(n > 1LL * n * (int)pos.size() - (int)neg.size() || (int)pos.size() - 1LL * n * (int)neg.size() > n){
		cout << "Impossible\n";
		return 0;
	}
	long long cur = (int)pos.size() - 1LL * n * (int)neg.size();
	vector<int> val((int)s.size());
	for(auto i: pos){
		val[i] = 1;
		auto dif = min<long long>(n - 1, n - cur);
		cur += dif;
		val[i] += dif;
	}
	for(auto i: neg){
		val[i] = n;
		auto dif = min<long long>(n - 1, n - cur);
		cur += dif;
		val[i] -= dif;
	}
	cout << "Possible\n";
	for(auto i = 0; i < (int)s.size() - 2; ++ i){
		if(~i & 1){
			cout << val[i] << " ";
		}
		else{
			cout << s[i] << " ";
		}
	}
	cout << "= " << n << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////
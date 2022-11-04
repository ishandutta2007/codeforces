#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
	ll n;
	string str;
	cin >> n >> str;

	ll n_del = 0;

	for (ll i = 'z'; i >= 'a'; --i){
		bool del = false;
		for (ll j = 0; j < (ll)str.size(); ++j){
			if (str[j] == i){
				if ((j && str[j-1] + 1 == str[j]) ||
					(j + 1 < (ll)str.size() && str[j+1] + 1 == str[j])){
					str.erase(str.begin() + j);
					del = true;
					n_del ++;
				}				
			}
		}
		i += del;
	}
	cout << n_del << endl;
}
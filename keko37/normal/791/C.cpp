#include<iostream>
#include<vector>

using namespace std;

int n, k;
string t;
vector <string> v, sol;

bool nalazi (string r, int x, int y) {
	for (int i=x; i<=y; i++) {
		if (r==sol[i]) return 1;
	}
	return 0;
}

int main () {
	for (int i='A'; i<='Z'; i++) {
		string s="";
		s+=i;
		v.push_back(s);
		s+='a';
		v.push_back(s);
	}
	cin >> n >> k;
	for (int i=0; i<k-1; i++) {
		sol.push_back(v[i]);
	}
	for (int i=0; i<n-k+1; i++) {
		cin >> t;
		if (t=="NO") {
			sol.push_back(sol[i]);
		} else {
			for (int j=0; j<k; j++) {
				if (!nalazi(v[j], i, i+k-2)) {
					sol.push_back(v[j]);
					break;
				}
			}
		}
	}
	for (int i=0; i<sol.size(); i++) {
		cout << sol[i] << " ";
	}
	return 0;
}
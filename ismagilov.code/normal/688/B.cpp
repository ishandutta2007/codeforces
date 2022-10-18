#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fs first
#define sc second
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	string n;
	cin >> n;
	for (int i = 0; i < n.size(); i++){
		cout << n[i];
	}
	
	for (int i = n.size()-1; i >= 0; i--){
		cout << n[i];
	}
}
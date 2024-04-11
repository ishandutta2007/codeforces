#include <bits/stdc++.h>
#define sz(v) ((int)((v).size()))
using namespace std;
using lint = long long;

int ask(vector<int> v){
	printf("? ");
	for(auto &i : v) cout << i << " ";
	cout << endl;
	int x; cin >> x;
	 return x;
}

int main(){
	vector<int> v1, v2;
	for(int i=0; sz(v1) < 100; i+=128) v1.push_back(i);
	for(int i=1; sz(v2) < 100; i++) v2.push_back(i);
	int a1 = ask(v1) & 127;
	int a2 = ask(v2) & ~127;
	printf("! %d\n", a1 | a2);
}
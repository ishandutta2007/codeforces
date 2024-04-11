#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long lint;

void print(string a, string b){
	printf("%s %s\n", a.c_str(), b.c_str());
}

int main(){
	string a, b;
	cin >> a >> b;
	print(a, b);
	int q;
	cin >> q;
	while(q--){
		string fi, se;
		cin >> fi >> se;
		if(a == fi) a = se;
		else b = se;
		print(a, b);
	}
}
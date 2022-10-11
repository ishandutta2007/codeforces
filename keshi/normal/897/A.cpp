#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,l,r;
	string s;
	char b,c;
	cin >> n >> m;
	cin >> s;
	while (m--){
		cin >> l >> r >> b >> c;
		for (int i=l-1;i<r;i++){
			if (s[i]==b){
				s[i]=c;
			}
		}
	}
	cout << s;
	return 0;
}
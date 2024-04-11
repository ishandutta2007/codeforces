#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int mod = 1e9 + 7;
const int MAXN = 300005;
const int MAXT = 1050000;

string s;

int main(){
	cin >> s;
	cin >> s;
	for(int i=1; i<s.size(); i++){
		if(s[i] != s[i-1]){
			printf("YES\n%c%c\n", s[i-1], s[i]);
			return 0;
		}
	}
	puts("NO");
}
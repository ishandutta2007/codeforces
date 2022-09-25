#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 360000;
char s[maxn];
vector<int> p, c;
void no(){
	cout << ":(";
	exit(0);
}
int main(){
	ios::sync_with_stdio(false);
	int sum = 0, n, p = 0;
	cin >> n >> s;
	for(int i = 0; i < n; i += 1){
		if(s[i] == '?') p += 1;
		if(s[i] == '(') sum += 1;
		if(s[i] == ')') sum -= 1;
	}
	if((p - sum) % 2) no();
	int x = (p - sum) / 2;
	if(x < 0 or x > p) no();
	for(int i = 0; i < n; i += 1)
		if(s[i] == '?') s[i] = x --> 0 ? '(' : ')';
	sum = 0;
	for(int i = 0; i < n; i += 1){
		if(s[i] == '(') sum += 1;
		else sum -= 1;
		if(sum < 0) no();
		if(sum == 0 and i + 1 < n) no();
	}
	cout << s;
}
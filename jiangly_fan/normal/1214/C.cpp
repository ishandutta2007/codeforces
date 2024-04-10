//Author: HeXun
//Date: 09-04-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 240000;
char s[maxn], t[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n, e = 0;
	cin >> n;
	cin >> (s + 1);
	for(int i = 1; i <= n; i += 1) if(s[i] == '(') e = i;
	if(not e) no();
	t[1] = '(';
	for(int i = 2, j = 1; i <= n; i += 1, j += 1){
		if(j == e) j += 1;
		t[i] = s[j];
	}
	int p = 0;
	for(int i = 1; i <= n; i += 1){
		if(t[i] == '(') p += 1;
		else p -= 1;
		if(p < 0) no();
	}
	if(p) no();
	cout << "YES";
	return 0;
}
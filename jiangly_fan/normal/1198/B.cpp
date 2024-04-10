//Author: HeXun
//Date: 07-30-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 240000;
int t[maxn], val[maxn];
int v[maxn], s[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1) cin >> val[i];
	int q;
	cin >> q;
	for(int i = 1; i <= q; i += 1){
		int o, p, x;
		cin >> o;
		if(o == 1){
			cin >> p >> x;
			t[p] = i;
			val[p] = x;
		}
		else{
			cin >> x;
			v[i] = x;
		}
	}
	for(int i = q; i >= 0; i -= 1) s[i] = max(v[i], s[i + 1]);
	for(int i = 1; i <= n; i += 1)
		cout << max(val[i], s[t[i]]) << " ";
	return 0;
}
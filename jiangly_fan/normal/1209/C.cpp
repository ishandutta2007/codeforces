//Author: HeXun
//Date: 09-14-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 240000;
char s[maxn];
int d[maxn];
char ans[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int t;
	for(cin >> t; t; t -= 1){
		int n;
		cin >> n >> (s + 1);
		for(int i = 1; i <= n + 1; i += 1){
			d[i] = s[i] - '0';
			ans[i] = 0;
		}
		int L = 9, R = 0;
		while(L){
			int mx = 0, ok = true;
			for(int i = 1; i <= n; i += 1) if(d[i] <= L){
				if(d[i] < mx) ok = false;
				mx = d[i];
			}
			if(not ok) L -= 1;
			else break;
		}
		while(R < 9){
			int mx = 0, ok = true;
			for(int i = 1; i <= n; i += 1) if(d[i] >= R){
				if(d[i] < mx) ok = false;
				mx = d[i];
			}
			if(not ok) R += 1;
			else break;
		}
		if(L + 1 >= R){
			for(int i = 1; i <= n; i += 1)
				if(d[i] <= L) ans[i] = '1';
				else ans[i] = '2';
			cout << (ans + 1) << "\n";
			continue;
		}
		if(L + 2 == R){
			int r = 1, l = n;
			for(int i = 1; i <= n; i += 1){
				if(d[i] <= L){
					r = i;
					ans[i] = '1';
				}
				if(d[i] >= R){
					l = min(l, i);
					ans[i] = '2';
				}
			}
			for(int i = 1; i < l; i += 1) if(not ans[i]) ans[i] = '2';
			for(int i = r + 1; i <= n; i += 1) if(not ans[i]) ans[i] = '1';
			bool ok = true;
			for(int i = 1; i <= n; i += 1) ok = ok and ans[i];
			if(ok){
				cout << (ans + 1) << "\n";
				continue;
			}
		}
		cout << "-\n";
	}
	return 0;
}
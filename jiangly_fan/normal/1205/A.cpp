//Author: HeXun
//Date: 08-18-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 240000;
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int N;
	cin >> N;
	if(N & 1){
		cout << "YES\n";
		for(int i = 0, p = 0; i < 2 * N; i += 1){
			a[p] = i + 1;
			if(i & 1) p = p + 1;
			else p = (p + N) % (2 * N);
		}
		for(int i = 0; i < 2 * N; i += 1) cout << a[i] << " ";
	}
	else cout << "NO";
	return 0;
}
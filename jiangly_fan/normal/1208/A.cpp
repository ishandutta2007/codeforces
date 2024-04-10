//Author: HeXun
//Date: 08-25-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	//a, b, a ^ b, a, b, a ^ b;
	int T;
	for(cin >> T; T; T -= 1){
		LL a, b, n;
		cin >> a >> b >> n;
		if(n % 3 == 0) cout << a << "\n";
		else if(n % 3 == 1) cout << b << "\n";
		else cout << (a ^ b) << "\n";
	}
	return 0;
}
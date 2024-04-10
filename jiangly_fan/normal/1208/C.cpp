//Author: HeXun
//Date: 08-25-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 1200;
int a[maxn][maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n;
	cin >> n;
	int b = n / 4;
	for(int i = 1; i <= n; i += 1)	
		for(int j = 1; j <= n; j += 1){
			a[i][j] = (((i + 3) / 4 - 1) * b + (j + 3) / 4 - 1) * 16 + (i % 4 * 4 + j % 4);
		}
	for(int i = 1; i <= n; i += 1)	{
		for(int j = 1; j <= n; j += 1)
			cout << a[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
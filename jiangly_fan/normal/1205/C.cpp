//Author: HeXun
//Date: 08-18-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 60;
int a[maxn][maxn], n;
int ask(int x1, int y1, int x2, int y2){
	cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	int x;
	cin >> x;
	return x ^ 1;
}
void ans(){
	cout << "!" << endl;
	for(int i = 1; i <= n; i += 1){
		for(int j = 1; j <= n; j += 1)
			cout << a[i][j];
		cout << endl;
	}
	exit(0);
}
bool vis[maxn][maxn];
void fuck(){
	for(int i = 1; i <= n; i += 1)
		for(int j = 1; j <= n; j += 1)
			if((i + j) % 2 == 1)
				a[i][j] ^= 1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	cin >> n;
	a[1][1] = 1;
	a[2][3] = ask(1, 2, 2, 3);
	a[2][1] = ask(2, 1, 2, 3) ^ a[2][3];
	vis[1][1] = vis[n][n] = vis[2][3] = vis[1][2] = vis[2][1] = true;
	for(int i = 1; i <= n; i += 1)
		for(int j = 1; j <= n; j += 1) if(not vis[i][j]){
			if(i >= 2 and j >= 2 and vis[i - 1][j - 1]) a[i][j] = a[i - 1][j - 1] ^ ask(i - 1, j - 1, i, j);
			else if(i >= 3 and vis[i - 2][j]) a[i][j] = a[i - 2][j] ^ ask(i - 2, j, i, j);
			else if(j >= 3 and vis[i][j - 2]) a[i][j] = a[i][j - 2] ^ ask(i, j - 2, i, j);
			else assert(0);
			vis[i][j] = true;
		}
	for(int i = 1; i <= n; i += 1)
		for(int j = 1; j <= n; j += 1)
			if(i - 1 >= 1 and j + 1 <= n)
				if(a[i - 1][j + 1] != a[i][j]){
					if(j + 2 <= n){
						if(ask(i - 1, j, i, j + 2) ^ a[i - 1][j] ^ a[i][j + 2]) fuck();
						ans();
					}
					else{
						if(ask(i - 1, j - 1, i, j + 1) ^ a[i - 1][j - 1] ^ a[i][j + 1]) fuck();
						ans();
					}
				}
	for(int i = 1; i + 2 <= n; i += 1) if(a[i][i] != a[i + 2][i + 2]){
		int ans1 = ask(i, i, i + 1, i + 2);
		if(not ans1){
			if(a[i + 1][i + 2] != a[i][i]) fuck();
			ans();
		}
		int ans2 = ask(i, i + 1, i + 2, i + 2);
		if(not ans2){
			if(a[i + 2][i + 2] != a[i][i + 1]) fuck();
			ans();
		}
		//10100 : 
		//11000 :
		//11010 :
		//11100 :
		if(a[i + 1][i + 1] == 0) {
			if(a[i][i + 1] != 1) fuck();
		}
		else{
			if(a[i + 1][i + 2] != 0) fuck();
		}
		ans();		
	}
	return 0;
}
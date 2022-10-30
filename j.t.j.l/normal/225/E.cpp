#include<bits/stdc++.h>

using namespace std;

const int MM = 1e9 + 7;
const int MAXN = 1e6 + 10;
int vis[MAXN];
int Nico[45] = {0,2,3,5,7,13,17,19,31,61,89,107,127,521,607,1279,
 2203,2281,3217,4253,4423,9689,9941,11213,19937,
 21701,23209,44497,86243,110503,132049,216091,
 756839,859433,1257787,1398269,2976221,3021377,
 6972593,13466917,20996011,24036583,25964951,
 30402457,32582657};

int main(){
	int n;
	cin>>n;
	n = Nico[n];n--;
	long long ans = 1, p = 2;
	for(; n; n >>= 1){
		if (n & 1)
			ans = ans * p % MM;
		p = p * p % MM;
	}
	cout<<(ans + MM - 1) % MM << endl;
	return 0;
	for(int i = 1; i < MAXN; i++)
		vis[i] = 0;
	for(int i = 2; i < MAXN; i++){
		int j = (i - 1) / 2 + i;
		while (j < MAXN){
			vis[j] = 1;
			j += i;
		}
	}

	for(int i = 1; i < MAXN / 3; i++)
		if (!vis[i])
			cout<<i<<endl;
	return 0;
}
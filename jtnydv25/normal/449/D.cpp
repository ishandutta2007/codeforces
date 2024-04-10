#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 2e6 + 10, mod = 1e9 + 7;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
int pw2[N];

void getSubsetFrequencies(vector<int> & a, int k){
	int n = (1 << k);
	int halfn = (1 << (k - 1));
	if(k == 0) return;
	vector<int> lft(a.begin(), a.begin() + halfn);
	vector<int> rgt(a.begin() + halfn, a.end());

	getSubsetFrequencies(lft, k - 1);
	getSubsetFrequencies(rgt, k - 1);
	for(int i = 0; i < halfn; i++){
		a[i] = lft[i] + rgt[i];
		a[i + halfn] = rgt[i];
	}
}
const int M = 20;
vector<int> freq(1 << M, 0);
int main(){
	pw2[0] = 1;
	for(int i = 1;i < N; i++) pw2[i] = (pw2[i - 1] << 1) % mod;
	int n, x;	
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		freq[x]++;
	}
	getSubsetFrequencies(freq, M);
	int ans = 0;
	for(int i = 0; i < (1 << M); i++){
		if(__builtin_popcount(i) & 1){
			ans = sub(ans, pw2[freq[i]]);
		}
		else ans = add(ans, pw2[freq[i]]);
	}
	printf("%d\n", ans);
}
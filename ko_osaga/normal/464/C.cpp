#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

char s[100005], buf[100005];
int n, v[100005], len[10], hsh[10]; 
string str[100005];

lint ipow(int x, int p){
	lint ret = 1, piv = x;
	while(p){
		if(p&1) ret *= piv;
		piv *= piv;
		ret %= mod;
		piv %= mod;
		p >>= 1;
	}
	return ret;
}

int main(){
	cin >> str[0] >> n;
	for(int i=1; i<=n; i++){
		scanf("%s", buf);
		v[i] = buf[0] - '0';
		for(int j=3; buf[j]; j++){
			str[i].push_back(buf[j]);
		}
	}
	for(int i=0; i<10; i++){
		len[i] = 1; hsh[i] = i;
	}
	for(int i=n; i>=0; i--){
		lint nl = 0, nh = 0;
		for(auto &j : str[i]){
			int c = j - '0';
			nh *= ipow(10, len[c]);
			nh += hsh[c];
			nh %= mod;
			nl += len[c];
			nl %= mod - 1;
		}
		len[v[i]] = nl;
		hsh[v[i]] = nh;
	}
	printf("%d\n", hsh[0]);
}
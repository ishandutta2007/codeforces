#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int MAXN = 10000005;
const int mod = 1e9 + 7;

int cnt(int x){
	return x * (x-1) / 2;
}
int main(){
	int k;
	cin >> k;
	if(k == 0){
		puts("a");
		return 0;
	}
	char cur = 'a';
	while(k){
		int c = 0;
		while(cnt(c + 1) <= k) c++;
		k -= cnt(c);
		for(int i=0; i<c; i++) putchar(cur);
		cur++;
	}
}
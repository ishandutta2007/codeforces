#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int n;
lint a[100005];

bitset<100000> bs[60];
int ans[60];
int sz = 0;

bool add_row(bitset<100000> ins, int x){
	for(int i=0; i<sz; i++){
		for(int j=n-1; j>=0; j--){
			if(ins[j]){
				if(bs[i][j]){
					ins ^= bs[i];
					x ^= ans[i];
					break;
				}
				else{
					for(int j=sz; j>i; j--){
						bs[j] = bs[j-1];
						ans[j] = ans[j-1];
					}
					bs[i] = ins;
					ans[i] = x;
					sz++;
					return 1;
				}
			}
			if(bs[i][j]) break;
		}
	}
	if(ins.count() == 0){
		if(x == 1) return 0;
		return 1;
	}
	bs[sz] = ins;
	ans[sz] = x;
	sz++;
	return 1;
}

int sol[100005];

int main(){
	scanf("%d",&n);
	lint xsum = 0;
	for(int i=0; i<n; i++){
		scanf("%lld",&a[i]);
		xsum ^= a[i];
	}
	for(int i=59; i>=0; i--){
		if((xsum >> i) & 1) continue;
		bitset<100000> bs;
		for(int j=0; j<n; j++){
			if((a[j] >> i) & 1) bs[j] = 1;
		}
		if(!add_row(bs, 1)) add_row(bs, 0);
	}
	for(int i=59; i>=0; i--){
		if(!((xsum >> i) & 1)) continue;
		bitset<100000> bs;
		for(int j=0; j<n; j++){
			if((a[j] >> i) & 1) bs[j] = 1;
		}
		if(!add_row(bs, 0)) add_row(bs, 1);
	}
	for(int i=sz-1; i>=0; i--){
		int msb = -1;
		for(int j=n-1; j>=0; j--){
			if(bs[i][j]){
				msb = j;
				break;
			}
		}
		sol[msb] = ans[i];
		for(int j=msb-1; j>=0; j--){
			if(bs[i][j] && sol[j]) sol[msb] ^= 1;
		}
	}
	for(int i=0; i<n; i++){
		printf("%d ", 2 - sol[i]);
	}
}
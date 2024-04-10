#include<bits/stdc++.h>
using namespace std;

const int _ = 4e5 + 7;
char str[_] , ban[_]; int pot[_] , tp[_] , sa[_] , rk[_] , h[_] , L , MX;

void sort(int len){
	memset(pot , 0 , sizeof(int) * (MX + 1));
	for(int i = 1 ; i <= L ; ++i) ++pot[rk[i]];
	for(int i = 1 ; i <= MX ; ++i) pot[i] += pot[i - 1];
	for(int i = 1 ; i <= L ; ++i) sa[++pot[rk[tp[i]] - 1]] = tp[i];
	memcpy(tp , rk , sizeof(int) * (L + 1));
	for(int i = 1 ; i <= L ; ++i) rk[sa[i]] = rk[sa[i - 1]] + (tp[sa[i]] != tp[sa[i - 1]] || tp[sa[i] + len] != tp[sa[i - 1] + len]);
	MX = rk[sa[L]];
}

void sort(){
	MX = 26; for(int i = 1 ; i <= L ; ++i){rk[i] = str[i] - 'a' + 1; tp[i] = i;} sort(0);
	for(int i = 1 ; MX != L ; i <<= 1){
		int cnt = 0; for(int j = L - i + 1 ; j <= L ; ++j) tp[++cnt] = j;
		for(int j = 1 ; j <= L ; ++j) if(sa[j] > i) tp[++cnt] = sa[j] - i;
		sort(i);
	}
	for(int i = 1 ; i <= L ; ++i){
		if(rk[i] == 1) continue;
		h[rk[i]] = max(0 , h[rk[i - 1]] - 1);
		while(str[i + h[rk[i]]] == str[sa[rk[i] - 1] + h[rk[i]]]) ++h[rk[i]];
	}
}

int sum[_] , l[_] , r[_] , stk[_] , top;
void calc_bound(){
	for(int i = 2 ; i <= L ; ++i){
		while(top && h[stk[top]] >= h[i]) r[stk[top--]] = i - 1;
		stk[++top] = i;
	}
	while(top) r[stk[top--]] = L;
	for(int i = L ; i > 1 ; --i){
		while(top && h[stk[top]] >= h[i]) l[stk[top--]] = i;
		stk[++top] = i;
	}
	while(top) l[stk[top--]] = 1;
}

int main(){
	scanf("%d %s %s" , &L , str + 1 , ban + 1);
	reverse(str + 1 , str + L + 1); reverse(ban + 1 , ban + L + 1); sort();
	for(int i = 1 ; i <= L ; ++i) sum[i] = sum[i - 1] + !(ban[sa[i]] - '0');
	calc_bound(); long long ans = 0; for(int i = 1 ; i <= L ; ++i) if(ban[i] == '0'){ans = L - i + 1; break;}
	for(int i = 2 ; i <= L ; ++i) ans = max(ans , 1ll * (sum[r[i]] - sum[l[i] - 1]) * h[i]);
	cout << ans; return 0;
}
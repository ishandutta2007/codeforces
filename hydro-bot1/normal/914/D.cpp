// Hydro submission #6183465cf10dbfb750691b48@1635993180936
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
const int M = 4e5 + 10;
int n,m,a[N],cnt = 0;
struct node{
	int l,r,gcd;
}tr[4 * N];
int read(){
	int x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') {
		x = x * 10 +ch - '0';
		ch = getchar();
	}
	return x;
}
int GCD(int x,int y){
	if(y == 0) return x;
	else return GCD(y,x % y);
}
void push_up(int u){
	tr[u].gcd = GCD(tr[u << 1].gcd,tr[u << 1 | 1].gcd);
}
void build(int u,int l,int r){
	tr[u].l = l,tr[u].r = r;
	if(l == r){
		tr[u].gcd = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(u << 1,l,mid),build(u << 1 | 1,mid + 1,r);
	push_up(u);
}
void modify(int u,int x,int d){
	if(tr[u].l == tr[u].r && tr[u].l == x){
		tr[u].gcd = d;
		return;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	if(x <= mid) modify(u << 1,x,d);
	if(x > mid) modify(u << 1 | 1,x,d);
	push_up(u);
}
void query(int u,int l,int r,int d,int L,int R){
	if(cnt > 1)return;
	if(tr[u].gcd %d == 0) {return;}
	if(L == R) {cnt ++;return;}
	int mid = L + R >> 1;
	if(l <= mid) query(u << 1,l,r,d,L,mid);
	if(r > mid)query(u << 1 | 1,l,r,d,mid + 1,R);
}
signed main(){
   n = read();
    for(int i = 1 ; i <= n ; i ++) a[i] = read();
    build(1,1,n);
    m = read();
    for(int i = 1 ; i <= m ; i ++){
    	int k;
    	k = read();
    	if(k == 1){
    		int l,r,x;
    		l = read(),r = read(),x = read();
    		cnt = 0;
    		query(1,l,r,x,1,n);
    		if(cnt > 1) puts("NO");
    		else puts("YES");
		}
		else {
			int x,d;
			x = read(),d = read();
			modify(1,x,d);
		}
	}

     return 0;
}
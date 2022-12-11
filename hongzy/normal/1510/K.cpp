#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define vit vector<int>::iterator
#define sit set<pr>::iterator
#define pb push_back
#define ll long long
using namespace std;
const int N=1e6+6; 
int n,a[N],b[N];
void S(int op){
	if (op==1) rep(i,1,n) swap(b[2*i-1],b[2*i]);
	else rep(i,1,n) swap(b[i],b[n+i]);
}
void check(int v){
	rep(i,2,2*n) if (b[i-1]>b[i]) return;
	printf("%d\n",v); exit(0);
}
int main(){
	scanf("%d",&n);
	rep(i,1,2*n) scanf("%d",&a[i]);
	#define C {rep(i,1,2*n)b[i]=a[i];}
	C; check(0);
	rep(i,1,2*n){
		C;
		rep(j,1,i) S(j&1);
		check(i);
		C;
		rep(j,1,i) S((j&1)^1);
		check(i);
	}
	puts("-1");
	return 0;
}
#include<bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
LL P=998244353;
const int INF=1e9+5;
const int N=110;
int n;
int a[2050];
int tp;
int q[200000];
void init(){
	return;
}
bool fl;
void sol(int m){
	if(m==3){
		///cout<<"?"<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
		if(a[2]!=2){
			fl=0;
			return;
		}
		if(a[1]!=1){
			q[++tp]=3;
			return;
		}
		return;
	}
	int mx=0,mn=0;
	for(int i=1;i<=m;++i){
		if(a[i]==m) mx=i;
		if(a[i]==m-1) mn=i;
	}
	if(mn&1) {
		fl=0;return;
	}
	if(!(mx&1)){
		fl=0;return;
	}
	if(mx==m&&mn==m-1){
		sol(m-2);
		return;
	}
	if(mx!=1){
		q[++tp]=mx;
		for(int l=1,r=mx;l<r;++l,--r) swap(a[l],a[r]);
		for(int i=1;i<=m;++i) if(a[i]==m-1) mn=i;
		mx=1;
	}
	if(mn==2){
		q[++tp]=m;
		for(int l=1,r=m;l<r;++l,--r) swap(a[l],a[r]);
		sol(m-2);
		return;
	}
	q[++tp]=mn-1;
	for(int l=1,r=mn-1;l<r;++l,--r) swap(a[l],a[r]);
	mx=mn-1;
	q[++tp]=mn+1;
	for(int l=1,r=mn+1;l<r;++l,--r) swap(a[l],a[r]);
	mx=3;mn=2;
	q[++tp]=3;
	for(int l=1,r=3;l<r;++l,--r) swap(a[l],a[r]);
	mx=1;mn=2;
	q[++tp]=m;
	for(int l=1,r=m;l<r;++l,--r) swap(a[l],a[r]);
	sol(m-2);
	return;
}
void MAIN(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	tp=0;
	fl=1;
	sol(n);
	if(!fl) puts("-1");
	else {
		printf("%d\n",tp);
		for(int i=1;i<=tp;++i){
			printf("%d ",q[i]);
		}
		puts("");
	}
	return;
} 

int main(){
	init();
	int ttt=1;scanf("%d",&ttt);
	while(ttt--) {
		MAIN();
	}
	return 0;
}
/*

*/
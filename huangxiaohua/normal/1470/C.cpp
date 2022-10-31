#include<bits/stdc++.h>
using namespace std;

#define rd() lim(rng)
int i,j,k,n,m,t,l,r,sb,md;

int ask(int x){
	if(x>n){x-=n;}
	printf("? %d\n",x);fflush(stdout);
	scanf("%d",&x);return x;
}

int main(){
	scanf("%d%d",&n,&m);
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()+1);
	uniform_int_distribution<int>lim(1,n);
	while(!l||!r){
		sb=rd();k=ask(sb);
		if(k<m){l=sb;}
		if(k>m){r=sb;}
	}
	if(r<l){r+=n;}
	while(1){
		md=(l+r)/2;k=ask(md);
		if(k==m){
			printf("! %d",(md>n)?md-n:md);return 0;
		}
		if(k<m){l=md+1;}
		else{r=md-1;}
	}///
}
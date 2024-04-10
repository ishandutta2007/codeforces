#include<stdio.h>
long long int i,j,n,m,l,r,lnum,rnum,ll,rr,rnd,sb[200005];

int main(){
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&m);
		l=1;r=m;ll=rr=lnum=rnum=rnd=0;
		for(j=1;j<=m;j++){
			scanf("%lld",&sb[j]);
		}
		lnum+=sb[1];rr=lnum;l++;rnd++;
		while(r>=l){
			while(rr>=0){
				rnum+=sb[r];
				ll+=sb[r];
				rr-=sb[r];
				r--;
				if(r<l){rnd++;goto aaa;
				}
			}rnd++;rr=0;
			while(ll>=0){
				lnum+=sb[l];
				rr+=sb[l];
				ll-=sb[l];
				l++;
				if(r<l){rnd++;goto aaa;
				}
			}rnd++;ll=0;
		}
		aaa:printf("%lld %lld %lld\n",rnd,lnum,rnum);
	}
}
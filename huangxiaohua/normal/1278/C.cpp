#include<bits/stdc++.h>
using namespace std;
#define N 200100
int l[405000],r[405000],ll[100500],rr[100500],n,i,t,a,ln,rn,k,res;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(l,1,sizeof(l));
		memset(r,1,sizeof(r));
		ln=rn=a=0;res=999999;
		for(i=n;i>=1;i--){
			scanf("%d",&ll[i]);
			if(ll[i]==1){a++;}
			else{ll[i]=-1;a--;}
		}
		for(i=1;i<=n;i++){
			scanf("%d",&rr[i]);
			if(rr[i]==1){a++;}
			else{rr[i]=-1;a--;}
		}
		if(a==0){puts("0");continue;}
		if(a<0){
			for(i=0;i<=n;i++){
				ln+=ll[i];rn+=rr[i];
				if(l[ln+N]==0x01010101){l[ln+N]=i;}
				if(r[rn+N]==0x01010101){r[rn+N]=i;}
			}
			for(i=a;i<=-a;i++){
				
				res=min(res,l[i+N]+r[a-i+N]);
			}
		}
		if(a>0){
			for(i=0;i<=n;i++){
				ln+=ll[i];rn+=rr[i];
				if(l[ln+N]==0x01010101){l[ln+N]=i;}
				if(r[rn+N]==0x01010101){r[rn+N]=i;}
			}
			for(i=-a;i<=a;i++){
				res=min(res,l[i+N]+r[a-i+N]);
			}
		}
		printf("%d\n",res);
	}
}
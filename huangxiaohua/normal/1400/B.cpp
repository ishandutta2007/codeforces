#include<bits/stdc++.h>
using namespace std;

int i,n,t,an,bn,res2,res;
long long a,b,sb1,sb2,tmp;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%d%d%lld%lld",&sb1,&sb2,&an,&bn,&a,&b);res=res2=0;
		if(a>b){
			swap(a,b);
			swap(an,bn);
		}
		//printf("%lld %lld\n",a,b);
		if(sb1<a&&sb2<a){puts("0");continue;}
		if((sb1/a+sb2/a)<=an){printf("%d\n",sb1/a+sb2/a);continue;}
		res+=an;
		tmp=1145141919;
		for(i=0;i<=an;i++){
			//printf("%d %d\n",a*i,a*(an-i));
			if(a*i>sb1){continue;}
			if(a*(an-i)>sb2){continue;}
			tmp=min(tmp,(sb1-a*i)%b+(sb2-a*(an-i))%b);
		}
		res2=(sb1+sb2-tmp-an*a)/b;
		res2=min(res2,bn);
		res+=res2;
		printf("%d\n",res);
	}
	
}
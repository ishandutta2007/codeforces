#include <bits/stdc++.h>
using namespace std;

int n,i,t,j,an,bn;
long long a[100500],b[100500],res=0,tmp,k;

bool cmp(long long x,long long y){
	return x>y;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		res=-2000000000000000000ll;
		if(n==5){
			res=1;
			for(i=1;i<=n;i++){
				scanf("%lld",&k);
				res=res*k;
			}
			printf("%lld\n",res);continue;
		}
		
		an=bn=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&k);
			if(k>=0){an++;a[an]=k;}
			else{bn++;b[bn]=k;}
		}
		sort(a+1,a+an+1,cmp);
		sort(b+1,b+bn+1);
		
		/*for(i=1;i<=an;i++){
			printf("%d ",a[i]);
		}puts("");
		for(i=1;i<=bn;i++){
			printf("%d ",b[i]);
		}puts("");*/
		if(bn==0){
			tmp=1;
			for(i=1;i<=5;i++){
				tmp=tmp*a[i];
			}res=max(res,tmp);
			goto aaa;
		}
		
		if(an==0){
			tmp=1;
			for(i=bn;i>=bn-4;i--){
				tmp=tmp*b[i];
			}res=max(res,tmp);
			goto aaa;
		}
		
		if(an>=5&&bn>=4){
			tmp=1;
			for(i=1;i<=5;i++){
				tmp=tmp*a[i];
			}res=max(res,tmp);
			
			tmp=1;
			for(i=1;i<=3;i++){
				tmp=tmp*a[i];
			}
			for(i=1;i<=2;i++){
				tmp=tmp*b[i];
			}res=max(res,tmp);
			
			tmp=1;
			for(i=1;i<=1;i++){
				tmp=tmp*a[i];
			}
			for(i=1;i<=4;i++){
				tmp=tmp*b[i];
			}res=max(res,tmp);
			goto aaa;
		}
		
		if(an>=5&&bn<4&&bn>=2){
			tmp=1;
			for(i=1;i<=5;i++){
				tmp=tmp*a[i];
			}res=max(res,tmp);
			
			tmp=1;
			for(i=1;i<=3;i++){
				tmp=tmp*a[i];
			}
			for(i=1;i<=2;i++){
				tmp=tmp*b[i];
			}res=max(res,tmp);
			
			goto aaa;
		}
		
		if(an>=5&&bn<2){
			tmp=1;
			for(i=1;i<=5;i++){
				tmp=tmp*a[i];
			}res=max(res,tmp);
			goto aaa;
		}
		
		if(an>=3&&bn>=4){
			tmp=1;
			for(i=1;i<=3;i++){
				tmp=tmp*a[i];
			}
			for(i=1;i<=2;i++){
				tmp=tmp*b[i];
			}res=max(res,tmp);
			
			tmp=1;
			for(i=1;i<=1;i++){
				tmp=tmp*a[i];
			}
			for(i=1;i<=4;i++){
				tmp=tmp*b[i];
			}res=max(res,tmp);
			goto aaa;
		}
		
		if(an>=3&&bn<4&&bn>=2){
			tmp=1;
			for(i=1;i<=3;i++){
				tmp=tmp*a[i];
			}
			for(i=1;i<=2;i++){
				tmp=tmp*b[i];
			}res=max(res,tmp);
			goto aaa;
		}
		
		if(an>=1&&bn>=4){
			tmp=1;
			for(i=1;i<=1;i++){
				tmp=tmp*a[i];
			}
			for(i=1;i<=4;i++){
				tmp=tmp*b[i];
			}res=max(res,tmp);
			goto aaa;
		}
		
		aaa:printf("%lld\n",res);
	}
}
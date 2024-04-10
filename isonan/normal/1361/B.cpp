#include <algorithm>
#include <cstdio>
#include <set>

const int P=1000000007;
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%P;
		a=1ll*a*a%P;
		b>>=1;
	}
	return ans;
}
int t,n,p,k[1000100],tem[1000100];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d",&n,&p);
		for(int i=1;i<=n;i++){
			scanf("%d",k+i);
		}
		std::sort(k+1,k+n+1);
		if(p==1){
			printf("%d\n",(n&1));
			continue;
		}
		while(n){
			if(n>1&&k[n]==k[n-1]){
				n-=2;
			}
			else{
				int j=n-1;
				for(;j;j--){
					++tem[k[n]-k[j]];
					int pos=k[n]-k[j];
					while(tem[pos]>=p&&pos){
						tem[pos-1]+=tem[pos]/p;
						tem[pos]%=p;
						--pos;
					}
					if(tem[0]){
						for(int l=k[n]-k[j];~l;--l)tem[l]=0;
						n=j-1;
						break;
					}
				}
				if(!j){
					for(int j=1;j<n;j++)
						for(int m=0;m<20;m++)
							if(k[n]-k[j]-m>=0)tem[k[n]-k[j]-m]=0;
					break;
				}
			}
		}
		if(!n){
			printf("%d\n",0);
			continue;
		}
		int ans=qsm(p,k[n]);
		for(int i=n-1;i;i--){
			ans=(ans+P-qsm(p,k[i]))%P;
		}
		printf("%d\n",ans);
	}
}
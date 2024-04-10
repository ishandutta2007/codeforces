#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sb,l,r,md,used[300500],tmp,res=11451419;

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		sb+=n/i-1;
	}
	if(sb<m){puts("No");return 0;}
	l=1;r=n;
	while(l<=r){
		md=(l+r)/2;
		sb=0;
		for(i=1;i<=md;i++){
			sb+=md/i-1;
		}
		if(sb==m){
			printf("Yes\n%d\n",md);
			for(i=1;i<=md;i++){
				printf("%d ",i);
			}return 0;
		}
		if(sb<m){
			l=md+1;
		}
		else{
			res=min(res,md);r=md-1;
		}
	}
	
	sb=0;
	for(i=1;i<=res;i++){
		sb+=res/i-1;
	}
	k=res;
	//printf("a%d %d\n",res,sb);
	while(sb>m){
		for(i=1;i<=res;i++){
			tmp=0;
			if(used[i]){continue;}
			for(j=i+i;j<=res;j+=i){
				if(!used[j]){tmp++;}
			}
			for(j=1;j*j<=i;j++){
				if(j*j==i){
					tmp+=1-used[j];break;
				}
				if(j==1){
					tmp+=1-used[1];continue;
				}
				if(!(i%j)){
					tmp+=2-used[j]-used[i/j];continue;
				}
			}
			if(sb-tmp>=m){
				sb-=tmp;
				used[i]=1;
				k--;
				break;
			}
		}
	}
	puts("Yes");
	printf("%d\n",k);
	for(i=1;i<=res;i++){
		if(!used[i]){
			printf("%d ",i);
		}
	}
}
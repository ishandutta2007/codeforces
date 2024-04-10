#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,n,m,t,a[100500],num[100500],sb,tmp,mx,ans[100500]={0,1,2,3,4,5,6,7,8,9};

int ask1(int i,int j,int x){
	printf("? 1 %d %d %d\n",i,j,x);fflush(stdout);
	scanf("%d",&x);
	return x;
}

int ask2(int i,int j,int x){
	printf("? 2 %d %d %d\n",i,j,x);fflush(stdout);
	scanf("%d",&x);
	return x;
}

void answer(){
	if(a[1]==n-1){
		for(int i=2;i<=n;i++){
			if(a[i]==n-1){
				sb=ask1(1,i,n-1);
				if(sb==n){a[i]=n;break;}
				else{a[1]=n;break;}
			}
		}
	}
	
	
	
	printf("! ");
	for(i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	puts("");
	fflush(stdout);
}

int main(){
	srand(time(0));
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			ans[i]=i;
		}
		//random_shuffle(ans+1,ans+1+n);
		memset(num,0,n*4+50);
		memset(a,0,n*4+50);
		mx=0;
		for(i=2;i<=n;i++){
			k=ask2(i,1,1);
			a[i]=k;
			num[k]++;
			mx=max(mx,k);
			if(num[k]>=4){break;}
		}
		k=mx;
		if(k!=2){
			aaa:a[1]=k;
			if(k>=n/2){
				for(i=2;i<=n;i++){
					if(a[i]){
						sb=a[i];
					}
					else{
						sb=ask2(i,1,1);
					}
					if(sb<k){a[i]=sb;}
					else{
						a[i]=ask1(1,i,n-1);
					}
				}
			}
			else{
				for(i=2;i<=n;i++){
					if(a[i]&&a[i]<k){continue;}
					sb=ask1(1,i,n-1);
					if(sb>k){a[i]=sb;}
					else{
						a[i]=ask2(i,1,1);
					}
				}
			}
			answer();
		}
		else{
			int k1,k2;
			k=ask1(2,1,1);
			if(k==1){
				a[1]=1;
				for(i=2;i<=n;i++){
					a[i]=ask1(1,i,n-1);
				}
				answer();
			}
			else{
				if(n==3){goto aaa;}
				a[1]=2;
				for(i=2;i<=n;i++){
					a[i]=ask1(1,i,n-1);
				}
				for(i=2;i<=n;i++){
					if(a[i]==2){
						a[i]=1;break;
					}
				}
				answer();
			}
		}

		/*for(i=1;i<=n;i++){
			if(ans[i]!=a[i]){puts("nmsl");return 0;
			}
		}*/

	}
	
}
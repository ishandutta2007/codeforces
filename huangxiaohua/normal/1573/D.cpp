#include <cstdio>

int i,j,k,n,m,t,a[200500],res,s[200500],it;

void add(int i,int x){s[++it]=i;a[i]=a[i+1]=a[i+2]=x;}

bool chk(int i){
	if(i+2>n)return 0;
	if((a[i]+a[i+1]+a[i+2])==2)add(i,0);
	if(!a[i])return 1;
	if(a[i])
		if(!(a[i+1]+a[i+2]))add(i,1);
		if(chk(i+2)){add(i,0);return 1;}
	return 0;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		k=0;it=0;
		for(i=1;i<=n;i++){scanf("%d",&a[i]);k+=a[i];}
		if(k&1){puts("NO");continue;}
		for(i=1;i<=n-2;i++){if(!chk(i))break;}
		for(i=1;i<=n-2;i++){if(!chk(i)){puts("NO");goto aaa;}}
		printf("YES\n%d\n",it);
		for(i=1;i<=it;i++){printf("%d ",s[i]);}puts("");aaa:;
	}
}
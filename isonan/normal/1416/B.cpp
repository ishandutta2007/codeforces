#include <cstdio>

int t,n,a[10001],con[3][100001],top;
void add(int i,int j,int x){
	if(!x||i==j)return;
	++top;
	con[0][top]=i;
	con[1][top]=j;
	con[2][top]=x;
	a[i]-=x*i;
	a[j]+=x*i;
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		top=0;
		int sum=0;
		for(int i=1;i<=n;i++)scanf("%d",a+i),sum+=a[i];
		if(sum%n){
			puts("-1");
			continue;
		}
		for(int i=n;i>1;i--)
			if(a[i]>=i){
				add(i,1,a[i]/i);
				break;
			}
		int last=1;
		for(int i=2;i<=n;i++){
			if(a[1]+(a[i]/i)*i>=i){
				if(a[1]>=(i-(a[i]%i))%i){
					add(1,i,(i-(a[i]%i))%i);
				}
				add(i,1,a[i]/i);
				for(int j=last+1;j<i;j++){
					add(1,j,(j-(a[j]%j))%j);
					add(j,1,a[j]/j);
				}
				last=i;
			}
		}
		for(int j=last+1;j<=n;j++){
			add(1,j,(j-(a[j]%j))%j);
			add(j,1,a[j]/j);
		}
		bool cando=1;
		for(int i=2;i<=n;i++)
			if(a[i])cando=0;
		if(!cando){
			puts("-1");
			continue;
		}
		for(int i=2;i<=n;i++)add(1,i,sum/n);
		printf("%d\n",top);
		for(int i=1;i<=top;i++)printf("%d %d %d\n",con[0][i],con[1][i],con[2][i]);
	}
}
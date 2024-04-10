#include <cstdio>
#include <algorithm>

int k,a[4096],p[4096],q[4096],b[4096];
int pos[4096];
void fix(int i,int j){
	int t=pos[b[i]^q[i]];
	if(t==j){
		std::swap(p[i],p[j]);
		std::swap(pos[p[i]],pos[p[j]]);
		return;
	}
	else{
		std::swap(p[t],p[i]);
		std::swap(pos[p[t]],pos[p[i]]);
		std::swap(q[t],q[j]);
		fix(t,j);
	}
}
int main(){
	scanf("%d",&k);
	int sum=0;
	for(int i=0;i<(1<<k);i++)scanf("%d",a+i),sum^=a[i];
	for(int i=0;i<(1<<k);i++)p[i]=q[i]=pos[i]=i;
	if(sum){
		puts("Fou");
		return 0;
	}
	for(int i=0;i<(1<<k)-1;i++){
		if(b[i]==a[i])continue;
		b[i+1]^=(b[i]^a[i]);
		b[i]=a[i];
		fix(i,i+1);
	}
	puts("Shi");
	for(int i=0;i<(1<<k);i++)printf("%d ",p[i]);putchar('\n');
	for(int i=0;i<(1<<k);i++)printf("%d ",q[i]);putchar('\n');
}
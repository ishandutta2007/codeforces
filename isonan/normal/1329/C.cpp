#include <cstdio>
#include <vector>

int t,h,g,a[(1<<22)],siz[(1<<22)],nowsiz[(1<<22)];
long long sum;
void f(int i){
	--nowsiz[i];
	if(a[i<<1]==0&&a[i<<1|1]==0)return (void)(a[i]=0);
	if(a[i<<1]>a[i<<1|1])a[i]=a[i<<1],f(i<<1);
	else a[i]=a[i<<1|1],f(i<<1|1);
}
bool check(int i){
	if(siz[i]==nowsiz[i])return 0;
	if(!a[i<<1])return 1;
	if(a[i<<1]>a[i<<1|1])return check(i<<1);
	else return check(i<<1|1);
}
std::vector<int>op;
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d",&h,&g);
		sum=0;
		for(int i=1;i<(1<<h);i++)scanf("%d",a+i),sum+=a[i];
		for(int i=(1<<g)-1;~i;--i)siz[i]=(siz[i<<1]+siz[i<<1|1])+1;
		for(int i=(1<<h)-1;~i;--i)nowsiz[i]=(nowsiz[i<<1]+nowsiz[i<<1|1])+1;
		int now=1;
		for(int i=(1<<g);i<(1<<h);i++){
			while(!check(now)){
				++now;
			}
			sum-=a[now];
			f(now);
			op.push_back(now);
		}
		printf("%lld\n",sum);
		for(int i=0;i<op.size();i++)printf("%d ",op[i]);putchar('\n');
		op.clear();
		for(int i=(1<<g)-1;i;--i)siz[i]=0;
		for(int i=(1<<h)-1;i;--i)nowsiz[i]=a[i]=0;
	}
}
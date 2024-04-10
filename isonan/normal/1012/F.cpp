#include <cstdio>
#include <cstring>
#include <algorithm>

int n,p;
struct trip{
	int s,len,t,ord;
}num[23];
struct info{
	int f,pre;
	info(int a=0x7f7f7f7f,int b=0){f=a;pre=b;}
	void add(info x){if(f>x.f)(*this)=x;}
}f[4194304];
int ans[23][2];
bool cmp(trip a,trip b){return a.s<b.s;}
void getans(int stat,int ind){
	while(stat){
		int u=f[stat].pre;
		ans[num[u].ord][0]=ind;
		ans[num[u].ord][1]=f[stat].f-num[u].t;
		stat^=1<<(u-1);
	}
}
int main(){
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&num[i].s,&num[i].len,&num[i].t),num[i].ord=i;
	std::sort(num+1,num+n+1,cmp);
//	for(int i=1;i<=n;i++)printf("%d %d %d\n",num[i].s,num[i].len,num[i].t);
	memset(f,0x7f7f7f7f,sizeof f);
	f[0].f=1;
	for(int i=0;i<(1<<n);i++){
		if(f[i].f==0x7f7f7f7f)continue;
//		printf("%d %d %d\n",i,f[i].f,f[i].pre);
		for(int j=1;j<=n;j++)
			if(!(i&(1<<(j-1)))){
				int tem=f[i].f;
				for(int k=1;k<=n;k++){
//					printf("%d %d %d %d\n",k,tem,tem+num[j].t,num[k].s);
					if(num[k].s<=tem&&num[k].s+num[k].len-1>=tem)tem=std::max(tem,num[k].s+num[k].len);
					else if(tem<=num[k].s&&tem+num[j].t>=num[k].s&&((i|(1<<(j-1)))&(1<<(k-1))))tem=std::max(tem,num[k].s+num[k].len);
				}
				if(tem+num[j].t>=num[j].s)continue;
				f[i|(1<<(j-1))].add((info){tem+num[j].t,j});
			}
	}
	if(p==1){
		if(f[(1<<n)-1].f!=0x7f7f7f7f){
			puts("YES");
			getans((1<<n)-1,1);
			for(int i=1;i<=n;i++)printf("%d %d\n",ans[i][0],ans[i][1]);
			return 0;
		}
	}
	else{
		for(int i=0;i<(1<<n);i++)
			if(f[i].f!=0x7f7f7f7f&&f[((1<<n)-1)^i].f!=0x7f7f7f7f){
				puts("YES");
				getans(i,1);
				getans(((1<<n)-1)^i,2);
				for(int i=1;i<=n;i++)printf("%d %d\n",ans[i][0],ans[i][1]);
				return 0;
			}
	}
	puts("NO");
}
#include <algorithm>
#include <cstdio>
#include <set>
using std::max;

int f1[1000001],f2[500001],fs1[500001],fs2[500001],n,m,time[500001],mx[500001],mt[500001];
int query[500001][3],cnt;
long long add[500001],val[500001],ans[500001];
struct point{int time,orig,ord;}num[500001];
bool cmp(point a,point b){return a.time<b.time;}
char get(){
	char ch=getchar();
	while(ch<'A'||ch>'Z')ch=getchar();
	return ch;
}
std::set<int>bel1[500001],bel2[500001];
int find(int x,int *f){return f[x]?f[x]=find(f[x],f):x;}
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void write(long long x){
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)bel1[i].insert(i),bel2[i].insert(i),fs1[i]=fs2[i]=1;
	for(int i=1,a,b;i<=m;i++){
		query[i][0]=get();
		query[i][1]=read();
		if(query[i][0]=='U'||query[i][0]=='M')query[i][2]=read();
	}
	for(int i=1,a,b;i<=m;i++){
		if(query[i][0]=='M'){
			a=find(query[i][1],f1),b=find(query[i][2],f1);
			if(a==b)continue;
			if(fs1[a]<fs1[b])a^=b^=a^=b;
			for(std::set<int>::iterator it=bel1[b].begin();it!=bel1[b].end();++it){
				bel1[a].insert(*it);
				time[*it]=(mt[*it]<mx[b])?max(time[*it],mx[b]):time[*it];
				mt[*it]=i;
			}
			bel1[b].clear();
			f1[b]=a;
			fs1[a]+=fs1[b];
		}
		else if(query[i][0]=='Z'){
			a=find(query[i][1],f1);
			mx[a]=i;
		}
		else if(query[i][0]=='Q'){
			a=query[i][1];
			num[++cnt]=(point){0,i,a};
			num[cnt].time=(mt[a]<mx[find(a,f1)])?mx[find(a,f1)]:time[a];
		}
	}
	std::sort(num+1,num+cnt+1,cmp);
	int now=1;
	while(now<=cnt&&num[now].time==0)++now;
	for(int i=1,a,b;i<=m;i++){
		if(query[i][0]=='U'){
			a=find(query[i][1],f2),b=find(query[i][2],f2);
			if(a!=b){
				if(fs2[a]<fs2[b])a^=b^=a^=b;
				for(std::set<int>::iterator it=bel2[b].begin();it!=bel2[b].end();++it)
					bel2[a].insert(*it),val[*it]+=add[b]-add[a];
				bel2[b].clear();
				f2[b]=a;
				fs2[a]+=fs2[b];
			}
		}
		else if(query[i][0]=='A'){
			a=find(query[i][1],f2);
			add[a]+=fs2[a];
		}
		while(now<=cnt&&num[now].time==i){
			ans[num[now].orig]=add[find(num[now].ord,f2)]+val[num[now].ord];
			++now;
		}
		if(query[i][0]=='Q'){
			a=query[i][1];
			write(add[find(a,f2)]+val[a]-ans[i]);
			putchar('\n');
		}
	}
}
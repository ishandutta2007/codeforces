#include <algorithm> 
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>

int n,k,q,a[200010],Xor[200010],oa[200010],ob[200010],p[200010],v[200010],ans[2][200010];
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void write(int x){
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}
int b[100010],pos[100010],Cnt;
short map[701][16384];
struct getval{
	int a[100010],Xor[450],n,bl,tot,ind[450];
	void init(){
//		for(int i=1;i<=n;i++)printf("%d ",a[i]);putchar('\n');
		bl=(int)sqrt(n);
		for(int i=1;i<=n;i++)pos[i]=(i-1)/bl+1,b[i]=b[i-1]^a[i];
		for(int i=1;i<=pos[n];i++)Xor[i]=b[std::min(n,i*bl)];
		tot=pos[n];
		for(int i=1;i<=tot;i++)memset(map[i],0,sizeof map[i]);
		for(int i=1;i<=n;i++)++::map[pos[i]][b[i]^Xor[pos[i]-1]];
	}
	int getans(){
		int cnt=0;
		for(int i=1;i<=tot;i++)cnt+=(int)::map[i][Xor[i-1]];
		cnt=n-cnt;
		return Xor[tot]?-cnt:cnt;
	}
	void upd(int x,int y){
//		printf("upd %d %d %d %d\n",x,y,n,a[x]);
		a[x]^=y;
		int u=(x-1)/bl+1;
		for(int i=u;i<=tot;i++)Xor[i]^=y;
		memset(::map[u],0,sizeof ::map[u]);
		for(int i=(u-1)*bl+1,tem=0;i<=u*bl&&i<=n;i++){
			tem^=a[i];
			++::map[u][tem];
		}
	}
}t;
int getans(int x){
	int cnt=0,tem=0;
	for(int i=x?x:k;i<=n;i+=k){
		tem^=a[i];
		if(tem)++cnt;
	}
	return tem?-cnt:cnt;
}
char get(){
	char ch=getchar();
	while(ch<'a'||ch>'b')ch=getchar();
	return ch;
}
std::vector<int>vec[200010];
int main(){
	scanf("%d%d%d",&n,&k,&q);
	for(int i=1;i<=n;i++)scanf("%d",oa+i);
	for(int i=1;i<=n;i++)scanf("%d",ob+i);
	for(int i=1;i<=n;i++)a[i]=oa[i]^ob[i];
	if(k==1){
		int cnt=0;
		for(int i=1;i<=n;i++)cnt+=(a[i]!=0);
		write(cnt);putchar('\n');
		for(int i=1,p,v;i<=q;i++){
			char ch=get();
			p=read(),v=read();
			if(ch=='a')std::swap(v,oa[p]),v^=oa[p];
			else std::swap(v,ob[p]),v^=ob[p];
			cnt-=(a[p]!=0);
			a[p]^=v;
			cnt+=(a[p]!=0);
			write(cnt);putchar('\n');
		}
	}
	else{ 
		++n;
		for(int i=n;i;i--)a[i]^=a[i-1];
//		for(int i=1;i<=n;i++)printf("%d ",a[i]);putchar('\n');
		for(int i=1,p,v;i<=q;i++){
			char ch=get();
			p=read(),v=read();
			if(ch=='a')std::swap(v,oa[p]),v^=oa[p];
			else std::swap(v,ob[p]),v^=ob[p];
			::p[i]=p,::v[i]=v;
			vec[::p[i]%k].push_back(i);
			vec[(::p[i]+1)%k].push_back(i);
		}
		for(int i=0;i<k;i++){
			t.n=0;
			for(int j=i?i:k;j<=n;j+=k)
				t.a[++t.n]=a[j];
			t.init();
			int u=t.getans();
			if(u>=0)ans[1][0]+=u;
			else ans[1][0]-=u,++ans[0][0];
//			printf("%d %d\n",i,u);
			for(int j=0;j<vec[i].size();j++){
				int ind=vec[i][j];
				if(u>=0)ans[1][ind]-=u;
				else ans[1][ind]+=u,--ans[0][ind];
				t.upd((p[ind]+(p[ind]%k!=i)-1)/k+1,v[ind]);
				u=t.getans();
//				printf("%d %d %d\n",i,ind,u);
				if(u>=0)ans[1][ind]+=u;
				else ans[1][ind]-=u,++ans[0][ind];
			}
		}
		for(int i=0;i<=q;i++){
			if(i)ans[1][i]+=ans[1][i-1],ans[0][i]+=ans[0][i-1];
			if(ans[0][i])puts("-1");
			else printf("%d\n",ans[1][i]);
		}
	}
}
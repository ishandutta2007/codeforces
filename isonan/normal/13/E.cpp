#include <cstdio>
#include <algorithm>

int jump[100001],step[100001],n,m,a[100001];
int len[100001];
bool vis[100001];
int bl=330;
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
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)a[i]=read()+i;
	for(int i=1;i<=n;i++){
		int tem=i;
		while(a[tem]<=std::min(i+bl,n))tem=a[tem],++step[i];
		jump[i]=tem;
//		printf("%d %d\n",step[i],jump[i]);
	}
	for(int i=1,opt,t1,t2;i<=m;i++){
		if(read()==0){
			t1=read(),t2=read();
			a[t1]=t1+t2;
			int l=std::max(t1-bl,1);
			vis[t1]=1;
			len[t1]=0;
			for(int j=t1-1;j>=l;j--){
				vis[j]=(a[j]<=t1&&vis[a[j]]);
				if(a[j]<=t1)len[j]=len[a[j]]+1;
			}
			for(int j=l,s=0,now=t1;j<=t1;j++)
				if(vis[j]){
					while(a[now]<=std::min(j+bl,n))now=a[now],++s;
					jump[j]=now;
					step[j]=len[j]+s;
				}
		}
		else{
			t1=read();
			int ans=0;
			for(;;){
				ans+=step[t1];
				t1=jump[t1];
				if(a[t1]>n)break;
				t1=a[t1],++ans;
			}
			write(t1);putchar(' ');
			write(ans+1);putchar('\n');
		}
	} 
}
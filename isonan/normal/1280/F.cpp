#include <cstdio>
#include <algorithm>

int k,n,T;
int num[2][101],p[101],Tem[101],top;
bool vis[101];
bool check(int a,int b,int c){
	b=(b+n-a)%n;
	c=(c+n-a)%n;
	return (b<=(n>>1))^(c<=(n>>1));
}
void rep(const char *s,int x){
//	if(s=="T")s="llllurrrrrrrrdllll";
//	if(s=="L")s="llllurrrrd";
//	if(s=="R")s="urrrrdllll";
	for(int i=1;i<=x;i++)printf("%s",s);
}
bool inverse(){
	int cnt=0;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			cnt^=(p[i]>p[j]);
	return cnt;
}
void c_shift(int a,int b,int c){
//	printf("cyclic shift %d %d %d\n",a,b,c);
	int p,tl,tr;
	if(check(a,b,c))p=a,tl=(b+n-a)%n,tr=(c+n-a)%n;
	if(check(b,a,c))p=b,tl=(c+n-b)%n,tr=(a+n-b)%n;
	if(check(c,a,b))p=c,tl=(a+n-c)%n,tr=(b+n-c)%n;
	rep("T",p);
	bool Do=0;
	if(tl<tr)std::swap(tl,tr),Do=1;
	tl-=(n>>1);
	if(Do){
		rep("R",tr);
		rep("L",tl);
		rep("R",(n>>1)+1-tr);
		rep("L",(n>>1)+1-tl);
	}
	else{
		rep("L",tl);
		rep("R",tr);
		rep("L",(n>>1)+1-tl);
		rep("R",(n>>1)+1-tr);
	}
	rep("T",n-p);
//	putchar('\n');
}
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='E')return -1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int ind(int x){
//	return x;
	if(x<=k)return x+k*3;
	if(x<=(k<<1)+1)return x-k-1;
	return 5*k+2-x;
}
int main(){
	scanf("%d",&T);
	for(int fd=1;fd<=T;fd++){
		scanf("%d",&k);
		n=(k<<2)+1;
		int nowx,nowy;
		for(int i=0;i<2;i++)
			for(int j=1;j<=(k<<1)+1;j++){
				num[i][j]=read();
				if(num[i][j]==-1)nowx=i,nowy=j;
			}
		int tem=nowy;
		while(tem<(k+1))std::swap(num[nowx][tem],num[nowx][tem+1]),++tem;
		while(tem>(k+1))std::swap(num[nowx][tem],num[nowx][tem-1]),--tem;
		if(!nowx)std::swap(num[0][tem],num[1][tem]);
//		for(int i=0;i<2;i++,putchar('\n'))
//			for(int j=1;j<=(k<<1)+1;j++)
//				printf("%d ",num[i][j]);
		int cnt=0;
		for(int i=k+1;i<=(k<<1)+1;i++)p[cnt++]=ind(num[0][i]);
		for(int i=(k<<1)+1;i;i--)if(~num[1][i])p[cnt++]=ind(num[1][i]);
		for(int i=1;i<=k;i++)p[cnt++]=ind(num[0][i]);
		if(inverse()){
			puts("SURGERY FAILED");
			continue;
		}
		puts("SURGERY COMPLETE");
//		for(int i=0;i<cnt;i++)printf("%d ",p[i]);putchar('\n');
		while(nowy<(k+1))putchar('r'),++nowy;
		while(nowy>(k+1))putchar('l'),--nowy;
		if(!nowx)putchar('d');
//		putchar('\n');
//		return 0;
		for(int i=0;i<cnt;i++)vis[i]=0;
		for(int i=0,last0=-1,last1=-1;i<cnt;i++)
			if(!vis[i]){
				top=0;
				int now=i;
				do{
					Tem[++top]=now;
					vis[now]=1;
					now=p[now];
				}while(now!=i);
				while(top>2){
					c_shift(Tem[top],Tem[top-1],Tem[top-2]);
					top-=2;
				}
				if(top==1)continue;
				if(~last0){
					c_shift(last0,last1,Tem[1]);
					c_shift(last1,Tem[1],Tem[2]);
					last0=last1=-1;
				}
				else last0=Tem[1],last1=Tem[2];
			}
		rep("r",k); 
		putchar('\n');
		printf("T ");
		rep("l",k);putchar('u');
		rep("r",k<<1);putchar('d');
		rep("l",k);
		putchar('\n');
		printf("L ");
		rep("l",k);putchar('u');
		rep("r",k);putchar('d');
		putchar('\n');
		printf("R ");
		putchar('u');rep("r",k);
		putchar('d');rep("l",k);
		putchar('\n');
		puts("DONE");
	}
}
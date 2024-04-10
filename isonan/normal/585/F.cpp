#include <cstdio>
#include <cstring>

const int P=1000000007;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
char s[1001],x[1001],y[1001];
int n,son[25010][10],fail[25010],len[25010],d,cnt=1;
int q[25010],h,t;
int f[25010][51];
int calc(char *s,bool Add){
	int ans=0,now=0;
	for(int i=1;i<=d;++i){
		for(int j=0;j<s[i]-'0';++j){
			ans=add(ans,f[son[now][j]][d-i]);
		}
		now=son[now][s[i]-'0'];
	}
	if(Add)ans=add(ans,now==1);
	return ans;
}
int main(){
	scanf("%s%s%s",s+1,x+1,y+1);
	n=strlen(s+1);
	d=strlen(x+1);
	for(int i=1;i+(d>>1)-1<=n;++i){
		for(int j=0,now=0;j<(d>>1);++j){
			int &p=son[now][s[i+j]-'0'];
			if(!p){
				p=++cnt;
				len[p]=len[now]+1;
				if(len[p]==(d>>1)){
					--cnt;
					p=1;
				}
			}
			now=p;
		}
	}
	for(int i=0;i<10;++i)if(son[0][i])q[++t]=son[0][i];
	while(h<t){
		++h;
		if(q[h]==1)continue;
		for(int i=0;i<10;++i)
			if(son[q[h]][i])fail[son[q[h]][i]]=son[fail[q[h]]][i],q[++t]=son[q[h]][i];
			else son[q[h]][i]=son[fail[q[h]]][i];
	}
	for(int i=0;i<10;++i)son[1][i]=1;
	f[1][0]=1;
	for(int i=1;i<=d;++i){
		for(int j=0;j<=cnt;++j)
			for(int k=0;k<10;++k)
				f[j][i]=add(f[j][i],f[son[j][k]][i-1]);
	}
	printf("%d\n",sub(calc(::y,1),calc(::x,0)));
}
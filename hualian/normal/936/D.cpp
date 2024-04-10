#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
bool ppp;
const int N=3e6+9;
int min(int &x,int &y){return x>y?y:x;}
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
char In[1<<20],*Ss=In,*Tt=In;
#define getchar() (Ss==Tt&&(Tt=(Ss=In)+fread(In,1,1<<20,stdin),Ss==Tt)?EOF:*Ss++)
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,ma,mb,t;
int b[N],lim;
int A[N],B[N];
int dp[N][2];
int last[N][2];
int sta[N],top,len;
pair<int,int> atk[N];
int id[2][N];
int st[100],tp;
void write(int x){
	if(!x){putchar('0');return;}
	while(x)st[++tp]=x%10,x/=10;
	while(tp)putchar(st[tp--]+'0');
}
int re[2][N];
int nt[2];
bool pppp;
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),ma=read(),mb=read(),t=read();
	b[++lim]=0;b[++lim]=n+1;
	A[ma+1]=1e9+1000;B[mb+1]=1e9+1000;
	rep(i,ma){
		A[i]=read();
		b[++lim]=A[i]-1;
		b[++lim]=A[i];
		if(A[i]!=n+1)b[++lim]=A[i]+1;
	}
	rep(i,mb){
		B[i]=read();
		b[++lim]=B[i]-1;
		b[++lim]=B[i];
		if(B[i]!=n+1)b[++lim]=B[i]+1;
	}sort(b+1,b+1+lim);
	memset(dp,0xc0,sizeof dp);
	dp[1][1]=dp[1][0]=0;last[1][1]=1;
	lim=unique(b+1,b+1+lim)-b-1;
	int t0=1,t1=1;
	For(i,2,lim){
		int mx0=dp[i-1][0]+b[i]-b[i-1]-1;
		int mx1=dp[i-1][1]+b[i]-b[i-1]-1;
		if(b[i]==A[t0]){if(mx0>=t)chmx(dp[i][0],mx0+1-t);}
		else chmx(dp[i][0],mx0+1);
		if(b[i]==B[t1]){if(mx1>=t)chmx(dp[i][1],mx1+1-t);}
		else chmx(dp[i][1],mx1+1);
		if(b[i]!=A[t0]&&min(t,dp[i][1])>dp[i][0])last[i][0]=1,dp[i][0]=min(t,dp[i][1]);
		if(b[i]!=B[t1]&&min(t,dp[i][0])>dp[i][1])last[i][1]=1,dp[i][1]=min(t,dp[i][0]);
		if(b[i]==A[t0])re[0][i]=t0,t0++;
		if(b[i]==B[t1])re[1][i]=t1,t1++;
	}
	if(dp[lim][0]>0||dp[lim][1]>0)puts("Yes");
	else {puts("No");return 0;}
	int op=((dp[lim][0]>0&&!last[lim][0])?0:1);
	Rof(i,lim,1){
		if(last[i][op])op^=1,sta[++top]=i;
		id[op][re[op][i]]=-1;
		
	}cout<<top<<endl;
	Rof(i,top,1)write(b[sta[i]]),putchar(' ');puts("");
	int j=top,res=0;op=0;
	nt[0]=nt[1]=1;
	For(i,1,lim){
		int now=b[i]-b[i-1],pos=b[i-1];
		while(res+now>=t){
			if(res<=t)now-=(t-res),pos+=(t-res),res+=(t-res);
			if(op==0){while(A[nt[0]]<=pos)nt[0]++;}
			else{while(B[nt[1]]<=pos)nt[1]++;}
			if(id[op][nt[op]]==-1){
				atk[++len]=make_pair(pos,op);
				nt[op]++;res-=t;
			}else{break;}
		}res+=now;
		if(i==sta[j]){res=min(res,t);op^=1;j--;continue;}
	}cout<<len<<endl;
	rep(i,len)write(atk[i].first),putchar(' '),write(atk[i].second+1),puts("");puts("");
	return 0;
}
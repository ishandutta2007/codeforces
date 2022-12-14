#include<bits/stdc++.h>
using namespace std;
#define N 500005
char buf[100000],*p1=buf,*p2=buf,ch;
int result;
#define getc() p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
inline int read(){
    ch=getc();result=0;
    while (ch<'0'||ch>'9') ch=getc();
    while (ch>='0'&&ch<='9') result=result*10+(ch^48),ch=getc();
    return result;
}
char s[3][N];
int T,n,c[3],i,j,las,pos1[N],pos2[N],f1,f2,fl;
void solve(int x,int y,int v){
	if(fl)return ;
	if(v==0){
		if(c[x]>=n&&c[y]>=n){
			fl=1;
			las=0;
			for(i=0;i<n;++i){
				while(s[x][las]!='0')++las;
				pos1[i]=las++;
			}
			las=0;
			for(i=0;i<n;++i){
				while(s[y][las]!='0')++las;
				pos2[i]=las++;
			}
			pos1[n]=pos2[n]=n<<1;
			f1=f2=0;
			for(i=0;i<n;++i){
				for(j=f1;j<pos1[i];++j)cout<<s[x][j];
				for(j=f2;j<pos2[i];++j)cout<<s[y][j];
				cout<<0;
				f1=pos1[i]+1;
				f2=pos2[i]+1;
			}
			for(j=f1;j<pos1[n];++j)cout<<s[x][j];
			for(j=f2;j<pos2[n];++j)cout<<s[y][j];
						cout<<"\n";
		}
	}
	else if(c[x]<=n&&c[y]<=n){
			fl=1;
			las=0;
			for(i=0;i<n;++i){
				while(s[x][las]!='1')++las;
				pos1[i]=las++;
			}
			las=0;
			for(i=0;i<n;++i){
				while(s[y][las]!='1')++las;
				pos2[i]=las++;
			}
			pos1[n]=pos2[n]=n<<1;
			f1=f2=0;
			for(i=0;i<n;++i){
				for(j=f1;j<pos1[i];++j)cout<<s[x][j];
				for(j=f2;j<pos2[i];++j)cout<<s[y][j];
				cout<<1;
				f1=pos1[i]+1;
				f2=pos2[i]+1;
			}
			for(j=f1;j<pos1[n];++j)cout<<s[x][j];
			for(j=f2;j<pos2[n];++j)cout<<s[y][j];
			cout<<"\n";
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s%s%s",&n,s[0],s[1],s[2]);
		c[0]=c[1]=c[2]=0;
		for(i=0;i<(n<<1);++i)for(j=0;j<3;++j)c[j]+=(s[j][i]=='0');
		fl=0;
		solve(0,1,0);
		solve(0,2,0);
		solve(2,1,0);
		solve(0,1,1);
		solve(2,1,1);
		solve(0,2,1);
	}
}
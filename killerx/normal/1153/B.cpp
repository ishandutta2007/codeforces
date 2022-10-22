#include<bits/stdc++.h>
#define ll long long
#define MP make_pair
#define PB push_back
using namespace std;
namespace io{
	const int Sz=1<<13;
	char ibuf[Sz],*ed=ibuf+Sz,*ips=ed-1;
	int getchar(){
		if(++ips==ed)ed=ibuf+fread(ips=ibuf,1,Sz,stdin);
		if(ips<ed)return*ips;else return EOF;
	}
}
#define getchar io::getchar
int read(){
	int x=0,f=1,c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f^=1;
	for(; isdigit(c);c=getchar())x=x*10+c-48;
	return f?x:-x;
}
int n,m,h,a[105],b[105],t[105][105];
int ans[105][105];
int main(){
	n=read(),m=read(),h=read();
	for(int j=0;j<m;++j)b[j]=read();
	for(int i=0;i<n;++i)a[i]=read();
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			t[i][j]=read();
			if(t[i][j]){
				ans[i][j]=min(a[i],b[j]);
			}
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			printf("%d",ans[i][j]);
			if(j+1==m)putchar('\n');
			else putchar(' ');
		}
	}
	return 0;
}
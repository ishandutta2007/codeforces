#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=520,maxm=140000;
int n,m;
int head[maxn],rdc[maxm<<1],nxt[maxm<<1],in[maxn],tnt;
int col[maxn],size[4];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void add(int u,int v){
	nxt[++tnt]=head[u];
	head[u]=tnt;
	rdc[tnt]=v;
	in[u]++;
}
bool putcolor(int u,int c){
	col[u]=c;size[c]++;
	int cnt=0;
	for(register int i=head[u];i;i=nxt[i]){
		if(!col[rdc[i]])
			if(!putcolor(rdc[i],c))return false;
		cnt+=(col[rdc[i]]==c);
	}
	return cnt==size[c]-1;
}
int main(){
	n=read();m=read();
	for(register int i=0,x,y;i<m;++i){
		x=read();y=read();
		add(x,y);add(y,x);
	}
	for(register int i=1;i<=n;++i)
		if(in[i]==n-1)
			col[i]=2;
	int cnt=1;
	for(register int i=1;i<=n;++i)
		if(!col[i]){
			if(cnt>3||!putcolor(i,cnt)){
				printf("No");return 0;
			}
			cnt+=2;
		}
	printf("Yes\n");
	for(register int i=1;i<=n;++i)
		putchar('a'+col[i]-1);
	return 0;
}
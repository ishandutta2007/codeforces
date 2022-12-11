#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=301100;
int n;
int nxt[maxn],val[maxn];
bool del[maxn];
int ans[maxn],tnt;
queue <int> q;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
void process(){
	tnt=0;
	n=read();
	for(int i=0;i<n;++i){
		nxt[i]=(i+1)%n;
		del[i]=false;
		val[i]=read();
	}
	for(int i=0;i<n;++i)
		if(gcd(val[i],val[nxt[i]])==1)
			q.push(i);
	while(q.size()){
		int p=q.front();
		q.pop();
		if(del[p])continue;
		ans[++tnt]=nxt[p];
		del[nxt[p]]=true;
		nxt[p]=nxt[nxt[p]];
		if(del[p])break;
		if(gcd(val[p],val[nxt[p]])==1)
			q.push(p);
	}
	printf("%d",tnt);
	for(int i=1;i<=tnt;++i)
		printf(" %d",ans[i]+1);
	putchar('\n');
}
int main(){
	int T=read();
	while(T--)process();
	return 0;
}
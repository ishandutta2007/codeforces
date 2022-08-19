// hope don't UKE
#include<bits/stdc++.h>
const int MAXN=31;// something
namespace FastIO{
	const int BUF_SIZE=1<<22;
	char buf[BUF_SIZE],*p1,*p2;
	char gc(){
		return p1==p2?p2=(p1=buf)+fread(buf,1,BUF_SIZE,stdin):0,p1==p2?-1:*p1++;
	}
	int read_int(){
		int ans=0;
		char c=gc();
		for(;(~c)&&!isdigit(c);c=gc());
		for(;isdigit(c);c=gc())
			ans=(ans<<3)+(ans<<1)+(c^'0');
		return ans;
	}
	char read_char(){
		char c=gc();
		for(;isspace(c);)
			c=gc();
		return c;
	}
	int read_string(char*p){
		char*q=p;
		char c=gc();
		for(;isspace(c);c=gc());
		for(;(~c)&&!isspace(c);c=gc())
			*q++=c;
		*q=0;
		return q-p;
	}
}
using namespace FastIO;
int cnt;
int len[6],p[6],w[720],h[720];
char s[6][MAXN],a[720][MAXN<<1][MAXN<<1];
void check(){
	if(len[p[0]]+len[p[2]]!=len[p[1]]+1)
		return;
	if(len[p[3]]+len[p[5]]!=len[p[4]]+1)
		return;
	if(s[p[0]][0]!=s[p[3]][0])
		return;
	if(s[p[0]][len[p[0]]-1]!=s[p[4]][0])
		return;
	if(s[p[3]][len[p[3]]-1]!=s[p[1]][0])
		return;
	if(s[p[4]][len[p[3]]-1]!=s[p[1]][len[p[0]]-1])
		return;
	if(s[p[1]][len[p[1]]-1]!=s[p[5]][0])
		return;
	if(s[p[4]][len[p[4]]-1]!=s[p[2]][0])
		return;
	if(s[p[5]][len[p[5]]-1]!=s[p[2]][len[p[2]]-1])
		return;
	w[cnt]=len[p[1]],h[cnt]=len[p[4]];
	for(int i=0;i!=h[cnt];++i)
		for(int j=0;j!=w[cnt];++j)
			a[cnt][i][j]='.';
	for(int i=0;i!=len[p[0]];++i)
		a[cnt][0][i]=s[p[0]][i];
	for(int i=0;i!=w[cnt];++i)
		a[cnt][len[p[3]]-1][i]=s[p[1]][i];
	for(int i=0;i!=len[p[2]];++i)
		a[cnt][h[cnt]-1][len[p[0]]+i-1]=s[p[2]][i];
	for(int i=0;i!=len[p[3]];++i)
		a[cnt][i][0]=s[p[3]][i];
	for(int i=0;i!=h[cnt];++i)
		a[cnt][i][len[p[0]]-1]=s[p[4]][i];
	for(int i=0;i!=len[p[5]];++i)
		a[cnt][len[p[3]]+i-1][w[cnt]-1]=s[p[5]][i];
}
int cmp(int u,int v){
	if(w[u]!=w[v])
		return strcmp(a[u][0],a[v][0]);
	for(int i=0;i!=h[u];++i){
		int t=strcmp(a[u][i],a[v][i]);
		if(t)
			return t;
	}
	return 0;
}
void solve(){
	for(int i=0;i!=6;++i)
		len[i]=read_string(s[i]);
	for(int i=0;i!=6;++i)
		p[i]=i;
	do{
		check();
		++cnt;
	}while(std::next_permutation(p,p+6));
	int ans=-1;
	for(int i=0;i!=720;++i)
		if(w[i]&&(!~ans||cmp(i,ans)<0))
			ans=i;
	if(!~ans)
		puts("Impossible");
	else
		for(int i=0;i!=h[ans];++i)
			puts(a[ans][i]);
}
int main(){
	solve();
	return 0;
}
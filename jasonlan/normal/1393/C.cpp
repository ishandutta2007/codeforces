#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=101000;
int n;
int ord[maxn],cnt[maxn],tnt;
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
void process(){
	while(tnt){
		cnt[ord[tnt]]=0;
		--tnt;
	}
	n=read();
	for(register int i=0,x;i<n;++i){
		x=read();
		if(!cnt[x])
			ord[++tnt]=x;
		++cnt[x];
	}
	int d=1,ce=0;
	for(register int i=1;i<=tnt;++i)
		if(cnt[ord[i]]>d){
			d=cnt[ord[i]];ce=1;
		}
		else if(cnt[ord[i]]==d)
			++ce;
	if(d==1)printf("%d\n",n);
	else printf("%d\n",(n-ce*d)/(d-1)+(ce-1));
}
int main(){
	int T=read();
	while(T--)process();
	return 0;
}
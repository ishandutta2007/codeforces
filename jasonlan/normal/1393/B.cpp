#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=101000;
int n,m;
int cnt[maxn],t2,t4;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
inline char getop(){
	char ch=getchar();
	while(ch!='+'&&ch!='-')ch=getchar();
	return ch;
}
void ins(int p){
	++cnt[p];
	if(cnt[p]%4==0)--t2,++t4;
	else if(cnt[p]%2==0)++t2;
	else;
}
void del(int p){
	if(cnt[p]%4==0)--t4,++t2;
	else if(cnt[p]%2==0)--t2;
	--cnt[p];
}
int main(){
	n=read();
	for(register int i=0;i<n;++i)
		ins(read());
	m=read();
	for(register int i=0;i<m;++i){
		if(getop()=='+')
			ins(read());
		else del(read());
		if(t4>=2||(t4==1&&t2>=2))
			puts("YES");
		else puts("NO");
	}
	return 0;
}
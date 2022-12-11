#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;
const int maxn=101000;
string s,d;
int n,m,a[maxn];
bitset<maxn> g[26],ans;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
inline int readch(){
	char ch=getchar();
	while(ch<'a'||ch>'z')ch=getchar();
	return ch-'a';
}
int main(){
	cin>>s;
	n=s.length();
	for(register int i=1;i<=n;++i){
		a[i]=s[i-1]-'a';
		g[a[i]].set(i);
	}
	m=read();
	for(register int i=1,op,l,r;i<=m;++i){
		op=read();
		if(op&1){
			l=read();r=readch();
			g[a[l]].reset(l);
			g[r].set(l);
			a[l]=r;
		}
		else{
			l=read();r=read();
			cin>>d;
			n=d.length();
			ans.set();
			for(register int i=0;i<n;++i)
				ans&=(g[d[i]-'a']>>i);
			int ansl=(ans>>l).count(),ansr=(ans>>(r-n+2)).count();
			printf("%d\n",ansl>ansr?ansl-ansr:0);
		}
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxm=26;
int T,n,cnt[maxm];
string s;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void process(){
	for(register int i=0;i<maxm;++i)
		cnt[i]=0;
	n=read();
	for(register int i=0,len;i<n;++i){	
		cin>>s;
		len=s.length();
		for(register int i=0;i<len;++i)
			++cnt[s[i]-'a'];
	}
	for(register int i=0;i<maxm;++i)
		if(cnt[i]%n){
			puts("NO");return;
		}
	puts("YES");
}
int main(){
	scanf("%d",&T);
	while(T--)process();
	return 0;
}
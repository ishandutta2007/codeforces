#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=2010,mod=1e9+7;
int m,d,len;
int dig[maxn];
int f[maxn][maxn];
inline int read(){
    int res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
int qmod(int x){
	return x>=mod?x-mod:x;
}
int dfs(int sum,int dep,bool mi){
	if(dep==len)return !sum;
	if(!mi&&~f[sum][dep])return f[sum][dep];
	int ret=0;
	if(dep&1){
		if(mi&&d>dig[dep]);
		else ret=dfs((sum*10+d)%m,dep+1,mi&(d==dig[dep]));
	}
	else{
		for(register int i=0,j=mi?dig[dep]:9;i<=j;++i)
			if(i!=d)
				ret=qmod(ret+dfs((sum*10+i)%m,dep+1,mi&(i==dig[dep])));
	}
	if(!mi)f[sum][dep]=ret;
	return ret;
}
int pro(string s){
	for(register int i=0;i<len;++i)
		dig[i]=s[i]-'0';
	return dfs(0,0,1);
}
bool check(string s){
	int res=0;
	for(register int i=0;i<len;++i)
		res=(res*10+dig[i])%m;
	if(res)return false;
	for(register int i=0;i<len;++i)
		if((dig[i]==d)^(i&1))return false;
	return true;
}
int main()
{
	memset(f,-1,sizeof(f));
	m=read();d=read();
	string s1,s2;
	cin>>s1>>s2;
	len=s1.length();
	printf("%d",qmod(pro(s2)-pro(s1)+check(s1)+mod));
	return 0;
}
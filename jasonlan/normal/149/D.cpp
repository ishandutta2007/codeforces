#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=710,mod=1e9+7;
string s;
int n;
int st[maxn],tp,gr[maxn];
int f[3][3][maxn][maxn];
bool v[3][3][maxn][maxn];
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
int dfs(int l,int r,int lc,int rc){
	if(l>r)return 1;
	if(v[lc][rc][l][r])return f[lc][rc][l][r];
	v[lc][rc][l][r]=true;
	if(l+1==r)
		f[lc][rc][l][r]+=2+(!lc)+(!rc);
	else if(gr[l]==r){
		for(register int i=1;i<=2;++i){
			if(lc!=i)
				f[lc][rc][l][r]=qmod(f[lc][rc][l][r]+dfs(l+1,r-1,i,0));
			if(rc!=i)
				f[lc][rc][l][r]=qmod(f[lc][rc][l][r]+dfs(l+1,r-1,0,i));
		}
	}
	else{
		for(register int i=1;i<=2;++i){
			if(lc!=i)
				f[lc][rc][l][r]=qmod(f[lc][rc][l][r]+1ll*dfs(l+1,gr[l]-1,i,0)*dfs(gr[l]+1,r,0,rc)%mod);
			f[lc][rc][l][r]=qmod(f[lc][rc][l][r]+1ll*dfs(l+1,gr[l]-1,0,i)*dfs(gr[l]+1,r,i,rc)%mod);
		}
	}
	return f[lc][rc][l][r];
}
int main()
{
	cin>>s;
	n=s.length();
	for(register int i=0;i<n;++i){
		if(s[i]=='(')st[++tp]=i;
		else gr[st[tp--]]=i;
	}
	printf("%d",dfs(0,n-1,0,0));
	return 0;
}
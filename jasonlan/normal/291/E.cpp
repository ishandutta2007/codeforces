#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=400010,mod=998244353;
int n;
string s[maxn],os;
int has[maxn],hasop,hasmi,L;
int ans;
vector<int> v[maxn];
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
int gethash(int l,int r){
	return (has[r]-has[l]*1ll*hasmi%mod+mod)%mod;
}
void check(int p){
	if(p<L)return;
	if(gethash(p-L,p)==hasop)++ans;
}
void dfs(int p,int kp){
	for(register int i=0;i<s[p].length();++i){
		has[kp+1]=(has[kp]*26ll+s[p][i]-'a')%mod;
		check(++kp);
	}
	for(register int i:v[p])
		dfs(i,kp);
}
int main(){
	n=read();
	s[1]="";
	for(register int i=2;i<=n;++i){
		v[read()].push_back(i);
		cin>>s[i];
	}
	cin>>os;
	L=os.length();
	hasmi=1;
	for(register int i=0;i<L;++i)
		hasop=(hasop*26ll+os[i]-'a')%mod,hasmi=hasmi*26ll%mod;
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,m,a[2009];
char s[2009],t[2009];
void solve(){
	for(int i=1;i<=n;++i)t[i]=s[i];
	for(int i=1;i<=n;++i){
		if(s[i]=='0'&&((s[i+1]=='1')+(s[i-1]=='1'))==1)t[i]='1';
	}
	
}
void work(){
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=m;++i){
		solve();
		bool bol=0;
		for(int j=1;j<=n;++j)if(t[j]!=s[j])bol=1;
		if(!bol)break;
		for(int j=1;j<=n;++j)s[j]=t[j];
	}
	printf("%s\n",s+1);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
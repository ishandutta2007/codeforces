#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
using namespace std;
const int N=2e5+5;
int n,T,x,id;
char c[N];
int pre[N],ri[N],pos;
int ct[N*448];
ll ans;
int main(){
	scanf("%s",c+1);n=strlen(c+1);c[0]='0';
	id=1;
	fo(i,0,n){
		id+=c[i]=='1';
		pre[i]=id;
		ri[pre[i]]=i;
	}
	ri[0]=-1;
	T=sqrt(n);
	fo(k,1,n/T){
		fo(i,1,pre[n]-T-1){
			fo(j,ri[i-1]+1,ri[i])++ct[j+(n-i)*k+1];
			fo(j,ri[i+T]+1,ri[i+T+1])ans+=ct[j-(i+T+1)*k+n*k+1];
		}
		if(pre[n]>=T+1)
			fo(i,0,ri[pre[n]-T-1])ct[i+(n-pre[i])*k+1]=0;
	}
	fo(i,0,n){
		for(int j=1;pre[i]+j<=pre[n]&&j<=T;++j){
			int l=ri[pre[i]+j-1]-i,r=ri[pre[i]+j]-i;
			ans+=r/j-l/j;
		}
	}
	cout<<ans;
}
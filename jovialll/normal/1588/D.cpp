#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define N 105
int i,n,T,j,k,pos,ans,fl;
string s[N];
struct node{
	int qwq[11];
	bool operator < (node aa)const{
		for(int i=1;i<=n;++i){
			if(qwq[i]!=aa.qwq[i])return qwq[i]<aa.qwq[i];
		}
		return 0;
	}
}tmp;
map<node,int>p;
int Nxt[15][105][55];
int dp(node x){
	struct node nxt; 
	if(p[x])return p[x];
	int i,j,fl,res=0,qwq;
	for(i=0;i<52;++i){
		fl=0;
		for(j=1;j<=n;++j){
			nxt.qwq[j]=Nxt[j][x.qwq[j]+1][i];
			fl|=nxt.qwq[j]==-1;
		}
//		cout<<"\n";
		if(!fl){
			res=max(res,dp(nxt));
		}
	}
	return p[x]=++res;
}
void find(node x){
	int u=s[1][x.qwq[1]];
	if(u<26)cout<<char(u+'a');
	else cout<<char(u-26+'A');
	struct node nxt; int i,j,fl; 
	for(i=0;i<52;++i){
		fl=0;
		for(j=1;j<=n;++j){
			nxt.qwq[j]=Nxt[j][x.qwq[j]+1][i];
			fl|=nxt.qwq[j]==-1;
		}
		if(!fl){
			if(p[x]==p[nxt]+1){
				find(nxt);return ;
			}
		}
	}
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;++i)for(j=0,cin>>s[i];j<s[i].length();++j){
			if(s[i][j]>='a')s[i][j]-='a';
			else s[i][j]-='A'-26;
		}
		for(i=1;i<=n;++i){
			for(j=0;j<52;++j)Nxt[i][s[i].length()][j]=-1;
			for(j=s[i].length()-1;~j;--j){
				for(k=0;k<52;++k)Nxt[i][j][k]=Nxt[i][j+1][k];
				Nxt[i][j][s[i][j]]=j;
			}
		}
		pos=-1;ans=0;
		for(i=0;i<52;++i){
			fl=0;
			for(j=1;j<=n;++j)tmp.qwq[j]=Nxt[j][0][i],fl|=tmp.qwq[j]==-1;
			if(!fl&&dp(tmp)>ans)ans=dp(tmp),pos=i;
		}
		cout<<ans<<"\n";
		if(ans){
			for(j=1;j<=n;++j)tmp.qwq[j]=Nxt[j][0][pos];
			find(tmp);cout<<"\n";
		}
		else cout<<"\n";
		p.clear();
	}
}
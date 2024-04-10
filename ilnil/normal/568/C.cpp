#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define pb push_back
using namespace std;
const int N=405;
struct two_sat{
	int tt,m;
	int be[N],df[N],lo[N],z[N],ds,bs,zs;
	vector<int>b[N],b2[N],hv[N];
	bool ex[N],zz[N];
	void link(int x,int y){b[x].pb(y);}
	void tar(int x){
		df[x]=lo[x]=++ds;z[++zs]=x;zz[x]=1;
		for(int i:b[x])if(df[i]){
			if(zz[i])lo[x]=min(lo[x],df[i]);
		}else{
			tar(i);lo[x]=min(lo[x],lo[i]);
		}
		if(lo[x]==df[x])
			for(++bs;zz[x];zz[z[zs--]]=0)be[z[zs]]=bs,hv[bs].pb(z[zs]);
	}
	void dfs(int x){
		ex[x]=1;
		for(int i:b2[x])if(!ex[i])dfs(i);
	}
	bool init(){
		fo(i,1,tt)if(!df[i])tar(i);
		fo(i,1,m)if(be[i]==be[i+m])return 1;
		fo(i,1,tt)for(int j:b[i])
			if(be[i]!=be[j])b2[be[i]].pb(be[j]);
		return 0;
	}
	void reset(){
		fo(i,1,bs)ex[i]=0;
	}
	void set2(int x){
		ex[x]=1;
		for(int i:b2[x])if(!ex[i])set2(i);
	}
	void set(int x){
		if(!ex[be[x]])set2(be[x]);
	}
	bool ck(){
		fo(i,1,m)if(ex[be[i]]&&ex[be[i+m]])return 0;
		return 1;
	}
}A;
int sz,s[30][2];
int n,m,p1,p2;
char c[30],ch[N],c1,c2;
int main(){
	scanf("%s",c+1);sz=strlen(c+1);
	fo(i,1,sz)c[i]=c[i]=='V';
	s[sz+1][0]=s[sz+1][1]=sz+1;c[sz+1]=0;
	fd(i,0,sz){
		s[i][c[i+1]]=i+1;
		s[i][!c[i+1]]=s[i+1][!c[i+1]];
	}
	fo(i,0,sz)sort(s[i],s[i]+2);
	scanf("%d%d",&n,&m);
	A.tt=n*2;A.m=n;
	fo(i,1,m){
		scanf("%d %c %d %c\n",&p1,&c1,&p2,&c2);
		c1=c1=='V';c2=c2=='V';
		A.link(p1+c1*n,p2+c2*n);
		A.link(p2+!c2*n,p1+!c1*n);
	}
	if(A.init()){
		printf("-1\n");
		return 0;
	}
	scanf("%s",ch+1);
	fo(i,1,n)ch[i]-='a'-1;
	A.reset();
	fo(i,1,n)A.set(i+n*c[ch[i]]);
	if(A.ck()){
		fo(i,1,n)putchar(ch[i]+'a'-1);
		return 0;
	}
	fd(i,1,n){
		bool is=0;
		if(s[ch[i]][0]<=sz){
			A.reset();
			fo(j,1,i-1)A.set(j+n*c[ch[j]]);
			A.set(i+n*c[s[ch[i]][0]]);
			if(A.ck())is=1,ch[i]=s[ch[i]][0];
		}
		if(!is&&s[ch[i]][1]<=sz){
			A.reset();
			fo(j,1,i-1)A.set(j+n*c[ch[j]]);
			A.set(i+n*c[s[ch[i]][1]]);
			if(A.ck())is=1,ch[i]=s[ch[i]][1];
		}
		if(is){
			fo(j,i+1,n){
				A.reset();
				fo(k,1,j-1)A.set(k+n*c[ch[k]]);
				A.set(j+n*c[s[0][0]]);
				if(A.ck())ch[j]=s[0][0];
				else{
					ch[j]=s[0][1];
					if(s[0][1]>sz){
						printf("-1");
						return 0;
					}
				}
			}
			fo(j,1,n)putchar(ch[j]+'a'-1);
			return 0;
		}
	}
	printf("-1");
}
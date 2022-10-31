#include <bits/stdc++.h>
using namespace std;
int i,j,k,n,m,t;
char s[500500];
struct jz{
	int f[4][4];
	jz(){memset(f,1,sizeof(f));}
	jz operator + (const jz b)const{
		jz ans;
		int i,j,k;
		for(i=1;i<=3;i++)for(j=1;j<=3;j++)for(k=1;k<=3;k++)ans.f[i][j]=min(ans.f[i][j],f[i][k]+b.f[k][j]);
		return ans;
	}
	int get(){
		int i,j,res=1e9;
		for(i=1;i<=3;i++)for(j=1;j<=3;j++)res=min(res,f[i][j]);
		return res;
	}
};
struct SB{
	#define md ((l+r)>>1)
	#define ls (id<<1)
	#define rs (ls+1)
	jz f[500500];
	void chk(int id,int l){
		memset(f[id].f,0,sizeof(f[id].f));
		f[id].f[2][1]=f[id].f[3][1]=f[id].f[3][2]=1e8;
		if(s[l]=='a')f[id].f[1][1]=f[id].f[1][2]=f[id].f[1][3]=1;
		if(s[l]=='b')f[id].f[2][2]=f[id].f[2][3]=1;
		if(s[l]=='c')f[id].f[3][3]=1;
	}
	void work(int id,int l,int r,int x,int y){
		if(l==r){chk(id,l);return;}
		if(x<=md)work(ls,l,md,x,y);
		if(y>md)work(rs,md+1,r,x,y);
		f[id]=f[ls]+f[rs];
	}
}st;
string ss;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	cin>>s+1;
	st.work(1,1,n,1,n);
	while(m--){
		cin>>k>>ss;
		s[k]=ss[0];
		st.work(1,1,n,k,k);
		cout<<st.f[1].get()<<'\n';
	}
}
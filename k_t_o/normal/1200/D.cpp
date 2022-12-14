#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
#define ls (p<<1)
#define rs ((p<<1)|1)
#define N 2005
struct node {
#define M 4201  //
	int s[M],h[M];
	
	node(){
		memset(s,0,sizeof(s));memset(h,0,sizeof h);
	}
	
	void add(int p,int l,int r,int x, int y)  // X Y
	{
		if(x>r||y<l)return;
		if(x<=l&&r<=y){
			++h[p];
			++s[p];
			return;
		}
		if(h[p]){  // 
			h[ls]+=h[p]; h[rs]+=h[p]; s[ls]+=h[p]; s[rs]+=h[p];
			h[p]=0;
		}
		int mi=l+r>>1;
		add(ls,l,mi,x,y);
		add(rs,mi+1,r,x,y);
		s[p]=max(s[ls],s[rs]);
	}
	
}tr[N];

int n,k,a[N][N],nn,l_r[N],l_l[N],c_l[N],c_r[N],ans,_ans;//_

//  nn*nn    a-bc-d +1        //     //     
inline void wo(int a, int b, int c, int d)
{
	for(int i=a;i<=b;++i){
		tr[i].add(1,1,nn,c,d);
	}
}

int main()
{
	n=read(); k=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)a[i][j]=getchar()=='B';
		getchar();
	} 
	nn=n-k+1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)if(a[i][j]){
			l_r[i]=j;
			if(!l_l[i])l_l[i]=j;
			c_r[j]=i;
			if(!c_l[j])c_l[j]=i;
		}
	}
	
	for(int i=1;i<=n;++i)if(!l_l[i])++ans;
	for(int i=1;i<=n;++i)if(!c_l[i])++ans;  //asm
	
	for(int i=1;i<=n;++i){
		if(l_r[i]-l_l[i]>=k)continue;
		if(!l_l[i])continue;
		wo(max(1,i-k+1),i,max(1,l_r[i]-k+1),l_l[i]);
	}
	for(int i=1;i<=n;++i){
		if(c_r[i]-c_l[i]>=k)continue;
		if(!c_l[i])continue;
		wo(max(1,c_r[i]-k+1),c_l[i],max(1,i-k+1),i);
	}
	
	//chmax  //node& //friend
	for(int i=1;i<=nn;++i)_ans=max(_ans,tr[i].s[1]);
	cout<<ans+_ans;
}
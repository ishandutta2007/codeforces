#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=2e5+10;
int n,k,ans;map<int,int> mp;
struct Tree{
	#define ls (k<<1)
	#define rs (k<<1|1)
	struct node{
		int sum,len;
	}t[N<<2];
	void init(){For(i,1,4*n)t[i]=(node){0,0};}
	void add(int k,int l,int r,int x,int v){
		if(l==r){t[k].sum+=v*l;t[k].len+=v;return;}
		int m=l+r>>1;x<=m?add(ls,l,m,x,v):add(rs,m+1,r,x,v);
		t[k].sum=t[ls].sum+t[rs].sum,t[k].len=t[ls].len+t[rs].len;
	}
	int qry(int k,int l,int r,int now){
		if(now>=t[k].sum)return t[k].len;
		if(l==r)return min(now/l,t[k].len);
		int m=l+r>>1;
		if(now>t[ls].sum)return t[ls].len+qry(rs,m+1,r,now-t[ls].sum);
		else return qry(ls,l,m,now);
	}
}T;
signed main(){
	int TTT=read();while(TTT--){
		mp.clear();
		n=read(),k=read(),ans=1e18;For(i,1,n)mp[read()]++;T.init();
		int df=0,nd=0;for(auto v:mp)T.add(1,1,n,v.second,1),df++;
//		cout<<df<<endl;
		For(i,0,n){
			if(i){
				if(mp[i-1])T.add(1,1,n,mp[i-1],-1);
				else nd++;
			}
			if(nd>k)break;
//			printf("MEX = %lld, OK\n",i);
//			cout<<"!!"<<T.qry(1,1,n,nd)<<endl;
			ans=min(ans,df-i+nd-T.qry(1,1,n,k));
		}cout<<ans<<endl;
	}
	return 0;
}
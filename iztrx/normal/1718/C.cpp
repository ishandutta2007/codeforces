#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define IOS ios::sync_with_stdio(0)
#define py cout<<"YES"
#define pn cout<<"NO"
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
int T,n,q,i,j,tot,u[20],k,x,a[N],s[N],dp[N],c[N],fl,is[N];
ll v[15][N],v_[15][N],ans;
void build(int x,int k,int l,int r){
	if(l==r){
		v_[x][k]=v[x][l];
		return ;
	}
	build(x,ls,l,mid);build(x,rs,mid+1,r);
	v_[x][k]=max(v_[x][ls],v_[x][rs]);
}
void modify(int x,int k,int l,int r,int a,int b){
	if(l==r){
		v_[x][k]+=b;
		return ;
	}
	if(a<=mid)modify(x,ls,l,mid,a,b);
	else modify(x,rs,mid+1,r,a,b);
	v_[x][k]=max(v_[x][ls],v_[x][rs]);
}
int main(){
	IOS;
	cin>>T;
	for(i=2;i<=200000;++i){
		if(!is[i]){
			for(j=i+i;j<=200000;j+=i){
				is[j]=1;
			}
		}
	}
	while(T--){
		cin>>n>>q;tot=0;
		for(i=1;i<n;++i){
			if(n%i==0&&(!is[n/i]||i==1))u[++tot]=i;
		}
		for(i=1;i<=n;++i)cin>>a[i];
		for(i=1;i<=tot;++i){
			for(j=0;j<u[i];++j){
				v[i][j]=0;
			}
		}
		for(i=1;i<=tot;++i){
			for(j=1;j<=n;++j){
				v[i][j%u[i]]+=a[j];
			}
		}
		for(i=1;i<=tot;++i)build(i,1,0,u[i]-1);
		ans=0;
			for(i=1;i<=tot;++i){
				ans=max(ans,u[i]*v_[i][1]);
			}
			cout<<ans<<"\n";
		while(q--){
			int x,y;
			cin>>x>>y;ans=0;
			for(i=1;i<=tot;++i){
				modify(i,1,0,u[i]-1,x%u[i],y-a[x]);
				ans=max(ans,u[i]*v_[i][1]);
			}
			a[x]=y;
			cout<<ans<<"\n";
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define N 2000005
#define ll long long
ll T,n,i,j,ans,m,k,a[N],ac[N],b[N],bc[N],c[N],cc[N],d[N],dc[N];
void add(ll*a,ll*ac,ll*c,ll*cc,int len){
	int cnt=0,fl=0;
	for(i=1;i<=len;++i){
		if(a[i]%m==0){
			if(c[cnt]==a[i]/m){
				cc[cnt]+=ac[i]*m;fl=1;
			}
			else{
				cc[++cnt]=ac[i]*m;
				c[cnt]=a[i]/m;fl=1;
			}
		}
		else{
			if(c[cnt]==a[i]){
				cc[cnt]+=ac[i];fl=1;
			}
			else c[++cnt]=a[i],cc[cnt]=ac[i];
		}
	}
	if(!fl){
		c[++cnt]=-1;
		return ;
	}
	else{
		for(i=1;i<=cnt;++i){
			a[i]=c[i];
			ac[i]=cc[i];
		}
		add(a,ac,c,cc,cnt);
	}
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(i=1;i<=n;++i)cin>>a[i],ac[i]=1;
		cin>>k;
		for(i=1;i<=k;++i)cin>>b[i],bc[i]=1;
		add(a,ac,c,cc,n);
		add(b,bc,d,dc,k);
//		for(i=1;i<=10;++i)cout<<c[i]<<" "<<d[i]<<" "<<cc[i]<<" "<<dc[i]<<"\n";
		//return 0;
		int l1,l2;
		for(i=1;;++i){
			if(c[i]==-1){l1=i;break;}
		}
		for(i=1;;++i){
			if(d[i]==-1){l2=i;break;}
		}
		if(l1!=l2){
			cout<<"NO\n";
		}
		else{
			int fl=0;
			for(i=1;i<l1;++i)if(c[i]!=d[i]||cc[i]!=dc[i])fl=1;
			if(fl)cout<<"NO\n";
			else cout<<"YES\n";
		}
	}
}
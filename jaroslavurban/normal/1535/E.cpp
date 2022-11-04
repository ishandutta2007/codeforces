#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=300100,logN=log2(N);
int a[N],c[N],emp[N],d[N];
int table[N][logN];
int q;

int jump(int u,int k){
	for(int i=logN-1;i>=0;--i)
		if(1<<i&k)
			u=table[u][i];
	return u;
}

void ProGamerMove(){
	cin>>q>>a[0]>>c[0];
	int i=1;
	while(q--){
		int t;cin>>t;
		if(t==1){
			int p;cin>>p>>a[i]>>c[i];
			d[i]=d[p]+1;
			table[i][0]=p;
			for(int k=0;table[table[i][k]][k];++k)table[i][k+1]=table[table[i][k]][k];
		}else{
			int u,w;cin>>u>>w;
			int l=0,r=d[u]+1;
			while(l<r){
				int m=(l+r)/2;
				int mj=jump(u,m);
				if(emp[mj])r=m;
				else l=m+1;
			}
			ll bought=0,payed=0;
//			cerr<<"solving "<<u<<" "<<w<<endl;
			while(--l>=0){
				int v=jump(u,l);
				ll buy=min(w-bought,ll(a[v]));
//				cerr<<v<<" "<<a[v]<<" "<<buy<<endl;
				a[v]-=buy;
				bought+=buy;
				payed+=buy*c[v];
				if(!a[v])emp[v]=true;
				if(bought==w)break;
			}
			cout<<bought<<" "<<payed<<endl;
		}
		++i;
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}
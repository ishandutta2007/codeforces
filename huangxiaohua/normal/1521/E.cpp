#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define fi first
#define se second

int i,j,k,n,m,t,mx,mxn,a[1050][1050],l,r,md,it,res;
vector<pair<int,int> >v;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		mx=mxn=res=0;
		v.clear();
		for(i=1;i<=m;i++){
			scanf("%d",&j);
			if(j>mx){mx=j;mxn=i;}
			v.push_back({-j,i});
		}
		v.push_back({0,0});
		sort(v.begin(),v.end());
		l=1;r=res=1000;
		while(l<=r){
			int t1,t2;
			md=(l+r)/2;
			t2=(md+1)/2*md;
			t1=t2+((md+1)/2)*(md/2);
			if(t1>=n&&t2>=mx){r=md-1;res=min(res,md);}
			else{l=md+1;}
		}
		for(i=1;i<=res;i++){
			for(j=1;j<=res;j++){
				a[i][j]=0;
			}
		}
		it=0;
		for(i=1;i<=res;i+=2){
			for(j=2;j<=res;j+=2){
				while(v[it].se&&!v[it].fi){it++;}if(!v[it].se){break;}
				a[i][j]=v[it].se;v[it].fi++;
			}
		}
		it++;
		for(i=2;i<=res;i+=2){
			for(j=1;j<=res;j+=2){
				while(v[it].se&&!v[it].fi){it++;}if(!v[it].se){break;}
				a[i][j]=v[it].se;v[it].fi++;
			}
		}
		it=0;
		for(i=1;i<=res;i+=2){
			for(j=1;j<=res;j+=2){
				while(v[it].se&&!v[it].fi){it++;}if(!v[it].se){break;}
				a[i][j]=v[it].se;v[it].fi++;
			}
		}
		printf("%d\n",res);
		for(i=1;i<=res;i++){
			for(j=1;j<=res;j++){
				printf("%d ",a[i][j]);
			}puts("");
		}
	}
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,l,vis[1005000],it1,it2,cnt,no,res[1005000];
vector<vector<int> >v,lmn,lmx,rmn,rmx;
vector<int> vl[1005000],vr[1005000];

struct sb{
	int lmx,lmn,rmx,rmn,id;
	bool operator <(const sb x)const{return lmn<x.lmn;}
};

vector<sb> v1;

void work(){
	int i,j,k;
	for(i=1;i<m;i++){
		v1.clear();v1.push_back({-1145141919,0});
		for(j=1;j<=n;j++){
			v1.push_back({lmn[j][i],lmx[j][i],rmn[j][i+1],rmx[j][i+1],j});
		}
		sort(v1.begin(),v1.end());
		for(j=n-1;j>=1;j--){
			v1[j].lmx=min(v1[j].lmx,v1[j+1].lmx);
			v1[j].rmn=max(v1[j].rmn,v1[j+1].rmn);
		}
		for(j=2;j<=n;j++){
			v1[j].rmx=min(v1[j].rmx,v1[j-1].rmx);
		}
		for(j=1;j<n;j++){
			res[v1[j].id]=1;
			if(v1[j].lmn<v1[j+1].lmx&&v1[j].rmx>v1[j+1].rmn){
				cout<<"YES\n";
				for(int i=1;i<=n;i++){
					cout<<(!res[i]?'R':'B');
				}
				cout<<' '<<i<<'\n';
				return;
			}
		}
		memset(res,0,n*4+50);
	}
	cout<<"NO\n";
}

int main(){
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		v.clear();
		vector<int> v0(m+1);
		for(i=0;i<=n+1;i++){
			v.push_back(v0);
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				cin>>v[i][j];
			}
		}
		lmn=lmx=rmn=rmx=v;
		for(i=1;i<=n;i++){
			for(j=2;j<=m;j++){
				lmn[i][j]=min(lmn[i][j-1],v[i][j]);
				lmx[i][j]=max(lmx[i][j-1],v[i][j]);
			}
			for(j=m-1;j>=1;j--){
				rmn[i][j]=min(rmn[i][j+1],v[i][j]);
				rmx[i][j]=max(rmx[i][j+1],v[i][j]);
			}
		}
		work();
		for(i=1;i<=n;i++)vis[i]=res[i]=0;
		for(i=1;i<=m;i++)vis[i]=res[i]=0;
	}
}
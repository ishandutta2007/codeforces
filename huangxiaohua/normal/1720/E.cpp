#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[505][505],l1[300500],r1[300500],l2[300500],r2[300500],tot,mx[300500],w[300500],f[505];
vector<int> v1[505];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cin>>k;a[i][j]=k;
			if(!l1[k]){
				l1[k]=r1[k]=j;
				l2[k]=r2[k]=i;
				tot++;
			}
			else{
				l1[k]=min(l1[k],j); r1[k]=max(r1[k],j);
				l2[k]=min(l2[k],i); r2[k]=max(r2[k],i);
			}
		}
	}
	if(m>=tot){
		cout<<m-tot;return 0;
	}
	for(i=1;i<=n*n;i++)mx[i]=max(r1[i]-l1[i]+1,r2[i]-l2[i]+1);
	for(t=1;t<=n;t++){
		memset(f,0,sizeof(f));
		for(i=1;i<=n;i++)v1[i].clear();
		memset(w,0,sizeof(w));
		for(i=1;i<=n*n;i++){
			if(!l1[i])continue;
			if(mx[i]<=t){
				v1[r1[i]].push_back(i);
				if(l1[i]+t<=n)v1[l1[i]+t].push_back(-i);
			}
		}
		for(i=1;i<=n;i++){
			for(auto j:v1[i]){
				k=1;
				if(j<0)j=-j,k=-k;
				f[r2[j]]+=k;
				if(l2[j]+t<=n)f[l2[j]+t]-=k;
			}
			k=0;
			for(j=1;j<=n;j++){
				k+=f[j];
				if(i<t||j<t)continue;
				if((tot-k)==m||(tot-k+1)==m){
					cout<<1;return 0;
				}
			}
		}
	}
	cout<<2;
}
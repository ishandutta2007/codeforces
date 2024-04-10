#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500005
int iq[N],n,j,k,res,del[13],bbad,cc[N],ans,m,d[4][2]={1,0,0,1,-1,0,0,-1},T,i,mx,q,tt,a[N],sum;
int pd(int x,int y){
	if(x<=0||y<=0||x>n||y>m)return 1e9;
	return a[x*m-m+y];
}
int ppd(int x){
	int y=(x-1)%m+1;
	x=(x-1)/m+1;
	if(x<=0||y<=0||x>n||y>m)return 0;
	for(int k=0;k<4;++k){
		if(pd(x+d[k][0],y+d[k][1])<a[x*m-m+y])return 0;
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;int bad=0;
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)cin>>a[i*m-m+j];
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			if(a[i*m-m+j]==1)continue;
			int fl=0;
			for(k=0;k<4;++k){
				if(pd(i+d[k][0],j+d[k][1])<a[i*m-m+j]){
					fl=1;
				}
			}
			if(!fl)iq[++bad]=i*m-m+j;
		}
	}
	bbad=bad;
	if(bad>=4){
		return cout<<"2",0;
	}
	if(bad==0){
		cout<<0;return 0;
	}
	int z=bad;
	for(i=1;i<=bad;++i){
		if(iq[i]<=m*n-m)iq[++z]=iq[i]+m;
		if(iq[i]>m)iq[++z]=iq[i]-m;
		if(iq[i]%m)iq[++z]=iq[i]+1;
		if(iq[i]%m!=1&&m!=1)iq[++z]=iq[i]-1;
	}
	bad=z;
	sort(iq+1,iq+bad+1);
	for(i=1;i<bad;++i){ 
		if(iq[i]==iq[i+1]){
			for(j=i+1;j<bad;++j)iq[j]=iq[j+1];
			--i,--bad;
		}
	}
	for(i=1;i<=bad;++i)cc[iq[i]]=1;
	for(i=1;i<=bad;++i){
		for(j=1;j<=n*m;++j){
			if(cc[j]&&j>=iq[i])continue;
			del[0]=iq[i];
			del[1]=iq[i]+m;
			del[2]=iq[i]-m;
			del[3]=iq[i]+1;
			del[4]=iq[i]-1;
			del[5]=j;
			del[6]=j+1;
			del[7]=j-1;
			del[8]=j+m;
			del[9]=j-m;
			sort(del,del+10);
			res=bbad;
			for(k=0;k<10;++k)if(k==0||del[k]!=del[k-1])res-=ppd(del[k]);
			swap(a[iq[i]],a[j]);
			for(k=0;k<10;++k)if(k==0||del[k]!=del[k-1])res+=ppd(del[k]);
			if(res==0)++ans;//,cout<<iq[i]<<" "<<j<<"\n";
			swap(a[iq[i]],a[j]);
		}
	}
	if(ans)cout<<"1 "<<ans<<"\n";
	else cout<<2;
}
#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int M=2e5+9;
int n,m,q;
int a[M],f[M][21];
int ask(int l,int r){
	int k=log2(r-l+1);
	return max(f[l][k],f[r-(1<<k)+1][k]);
}
void work(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)scanf("%d",&a[i]);
	for(int i=1;i<=m;++i)f[i][0]=a[i];
	for(int j=1;j<=20;++j){
		for(int i=1;i+(1<<j)-1<=m;++i)f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
	}
	cin>>q;
	for(int i=1;i<=q;++i){
		int ax,ay,bx,by,k;
		scanf("%d%d%d%d%d",&ax,&ay,&bx,&by,&k);
		if(ay>by)swap(ax,bx),swap(ay,by);
		if((by-ay)%k==0&&abs(bx-ax)%k==0){
			int r=(n-ax)/k;
			ax+=k*r;
			if(ask(ay,by)<ax)puts("YES");
			else puts("NO");
		}
		else puts("NO");
	}
}
int main(){
	work();
	// int T;
	// cin>>T;
	// while(T--)work();
	return 0;
}
/*
1
??????
*/
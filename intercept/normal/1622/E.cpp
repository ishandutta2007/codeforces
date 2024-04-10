#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define ll long long
#define eb emplace_back
using namespace std;
const int mod=998244353;
const int M=5009;
int n,m;
int a[19],b[19][10009],c[10009],d[10009],id[10009];
void work(){
	int tt=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)scanf("%d",&a[i]);
	for(int i=0;i<n;++i){
		for(int j=1;j<=m;++j)scanf("%1d",&b[i][j]);
	}
	ll ans=-1;
	for(int i=1;i<=m;++i)id[i]=i;
	for(int i=0;i<1<<n;++i){
		ll sum=0;
		for(int j=0;j<n;++j){
			if(i>>j&1)sum+=a[j];
			else sum-=a[j];
		}
		for(int k=1;k<=m;++k)c[k]=0;
		for(int j=0;j<n;++j){
			for(int k=1;k<=m;++k){
				if(b[j][k]){
					if(i>>j&1)c[k]--;
					else c[k]++;
				}
			}
		}
		sort(id+1,id+m+1,[&](const int&l,const int&r){return c[l]<c[r];});
		for(int k=1;k<=m;++k){
			sum+=1ll*k*c[id[k]];
		}
		if(ans<sum){
			tt=i;
			ans=sum;
			for(int k=1;k<=m;++k){
				d[id[k]]=k;
			}
			
		}
	}
	for(int j=0;j<n;++j){
		int t=0;
		for(int k=1;k<=m;++k){
			if(b[j][k]){
				if(tt>>j&1)t-=d[k];
				else t+=d[k];
			}
		}
		if(tt>>j&1)assert(a[j]>=t);
		else assert(a[j]<=t);
	}
	for(int i=1;i<=m;++i)printf("%d%c",d[i]," \n"[i==m]);
}
int main(){
	//freopen("1.in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
1
9 9
30 20 50 30 70 20 20 20 20
010101001
110010010
001001100
110011100
111111110
100111111
001100100
000001000
101010101
*/
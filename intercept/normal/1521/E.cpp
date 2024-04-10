#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int M=100009;
int n,m;
int a[M],id[M],c[M],b[1009][1009];
int get0(int k){
	return (k+1)/2*k;
}
int get1(int k){
	return get0(k)+(k+1)/2*(k/2);
}
void work(){
	int num=0;
	cin>>m>>n;
	for(int i=1;i<=n;++i)cin>>a[i],id[i]=i;
	sort(id+1,id+n+1,[&](const int&l,const int&r){return a[l]>a[r];});
	for(int i=1;i<=n;++i){
		for(int j=1;j<=a[id[i]];++j)c[++num]=id[i];
	}
	for(int k=1;k<=m;++k){
		if(a[id[1]]<=get0(k)&&get1(k)>=m){
			cout<<k<<"\n";
			num=0;
			for(int i=1;i<=k;++i){
				for(int j=1;j<=k;++j)b[i][j]=0;
			}
			for(int i=1;i<=k;i+=2){
				for(int j=2;j<=k;j+=2){
					if(num<m)b[i][j]=c[++num];
				} 
			}
			for(int i=1;i<=k;i+=2){
				for(int j=1;j<=k;j+=2){
					if(num<m)b[i][j]=c[++num];
				}
			}
			for(int i=2;i<=k;i+=2){
				for(int j=1;j<=k;j+=2){
					if(num<m)b[i][j]=c[++num];
				}
			}
			for(int i=1;i<=k;++i){
				for(int j=1;j<=k;++j){
					cout<<b[i][j]<<" \n"[j==k];
				}
			}
			return;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
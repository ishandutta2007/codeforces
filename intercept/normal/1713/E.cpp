#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int M=1e3+9;
int a[M][M];
int f[M];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int x,int y){
	f[find(x)]=find(y);
}
void work(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		f[i]=i;
		f[i+n]=i+n;
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(a[i][j]>a[j][i]){
				if(find(i)!=find(j)){
					merge(i,j+n);
					merge(i+n,j);
					swap(a[i][j],a[j][i]);
				}
			}
			else if(a[i][j]<a[j][i]){
				if(find(i)!=find(j+n)){
					merge(i,j);
					merge(i+n,j+n);
				}
				else swap(a[i][j],a[j][i]);
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)cout<<a[i][j]<<" \n"[j==n];
	}
}
int main(){
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
3
2 1 2
2 1 2
1 1 2
*/
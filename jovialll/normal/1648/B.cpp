#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
int T,n,c,i,fl,j,a[N],C[N<<1];
vector<int>v[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>T;
	for(i=1;i<N;++i){
		for(j=i;j<N;j+=i){
			v[j].push_back(i);
		}
	}
	while(T--){
		cin>>n>>c;
		for(i=1;i<=n;++i){
			cin>>a[i];++C[a[i]];
		}
		for(i=1;i<=c;++i)C[i]+=C[i-1];
		fl=0;
		for(i=1;i<=c;++i){
			for(j=0;j<v[i].size();++j){
				if(C[v[i][j]]-C[v[i][j]-1]&&C[i/v[i][j]]-C[i/v[i][j]-1]==0&&C[min(c,i+v[i][j]-1)]-C[i-1])fl=1;
			}
		}
		if(fl)cout<<"No\n";
		else cout<<"Yes\n";
		for(i=1;i<=c;++i)C[i]=0;
	}
}
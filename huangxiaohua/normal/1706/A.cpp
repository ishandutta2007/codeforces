#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[100500];

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=1;i<=m;i++){
			a[i]=0;
		}
		for(i=1;i<=n;i++){
			int x,y;
			cin>>x;y=m+1-x;
			if(x>y)swap(x,y);
			if(!a[x])a[x]=1;
			else a[y]=1;
		}
		for(i=1;i<=m;i++)cout<<"BA"[a[i]];
		cout<<'\n';
	}
}
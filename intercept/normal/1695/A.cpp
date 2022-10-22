#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
void work(){
	int n,m;
	cin>>n>>m;
	int ma=-2e9,ans;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			int x;
			cin>>x;
			if(ma<x){
				ma=x;
				ans=max({i*j,(n-i+1)*j,i*(m-j+1),(n-i+1)*(m-j+1)});
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
4 4

2 12 6 10

3 15 0 4

1 13 8 11

14 7 9 5

*/
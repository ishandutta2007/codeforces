#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define mod 998244353
#define pb push_back
int T,n,m,i,j,k,x,y,a[N];
int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n>>m;
		if((n+m)&1)cout<<-1;
		else if(n==0&&m==0)cout<<0;
		else if(n==m)cout<<1;
		else cout<<2;
		cout<<"\n";
	}
	return 0;
}
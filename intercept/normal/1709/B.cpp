#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int M=1e5+9;
int n,m;
int a[M];
ll p[M],s[M];
void work(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		int x=a[i]-a[i-1];
		p[i]=p[i-1];
		s[i]=s[i-1];
		if(x>0)p[i]+=x;
		else s[i]-=x;
	}
	for(int i=1;i<=m;++i){
		int l,r;
		cin>>l>>r;
		if(l<r){
			cout<<s[r]-s[l]<<endl;
		}
		else{
			cout<<p[l]-p[r]<<endl;
		}
	}
}
int main(){
	work();
	// int T;
	// cin>>T;
	// while(T--)work();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[20050000];

void fuck(int x){
	if(a[x]||x>n)return;
	a[x]=1;cout<<x<<' ';fuck(x+x);
}

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,n*4+50);
		cout<<2<<'\n';
		for(i=1;i<=n;i++){
			fuck(i);
		}
		cout<<'\n';
	}
}
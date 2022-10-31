#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
bool sb[666][666];

void work(int a,int b,int c,int d,int w){
	if(a==b&&c==d){
		sb[a][c]=w;return;
	}
	int e=(a+b)/2,f=(c+d)/2;
	work(a,e,c,f,w);
	work(e+1,b,c,f,w);
	work(a,e,f+1,d,w);
	work(e+1,b,f+1,d,w^1);
}

int main(){
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()+1);
	ios::sync_with_stdio(0);
	cin>>n;
	n=(1<<n);
	work(1,n,1,n,1);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)cout<<"*+"[sb[i][j]];
		cout<<'\n';
	}
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
char s[100500];
ll a[100500],it=1,vis[100500];

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>s+1;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	while(1){
		if(vis[it]){cout<<"INFINITE";return 0;}
		vis[it]=1;
		if(s[it]=='<'){it-=a[it];}
		else{it+=a[it];}
		if(it<=0||it>n){cout<<"FINITE";return 0;}
	}
}
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define INF 1000000000
typedef long long ll;

int l;
int v[4];
int resp;
int m[4123][4];

int dfs(int tam,int pos){
	if(tam==0){
		return 0;
	}
	if(tam<0 || pos==3){
		return -5000000;
	}
	if(m[tam][pos]==-5000000){
		m[tam][pos]=max(dfs(tam-v[pos],pos)+1,dfs(tam,pos+1));
	}
	return m[tam][pos];
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>l>>v[0]>>v[1]>>v[2];

	for(int i=0;i<=l;i++){
		for(int j=0;j<3;j++){
			m[i][j]=-5000000;
		}
	}

	cout<<dfs(l,0)<<"\n";

	return 0;
}
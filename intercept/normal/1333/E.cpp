#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int M=509;
int n;
int a[M][M];
int main(){
	cin>>n;
	if(n<3){
		puts("-1");
		return 0;
	}
	int t=0;
	for(int i=n;i>=1;--i){
		for(int j=1;j<=n;++j){
			if(i<=3&&j<=3)continue;
			a[i][j]=++t;
		}
	}
	a[1][1]=1+t;
	a[1][2]=7+t;
	a[1][3]=9+t;
	a[2][1]=3+t;
	a[2][2]=2+t;
	a[2][3]=5+t;
	a[3][1]=4+t;
	a[3][2]=8+t;
	a[3][3]=6+t;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)cout<<a[i][j]<<" \n"[j==n];
	}
	return 0;
}
/*
1 2 2 4 3 6
*/
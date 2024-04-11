#include<bits/stdc++.h>
using namespace std;
int g[10][10];
int main (){
	int n, m, a, b,t,mn=10000; cin>> n >> m;
	if(n<=6){cout<<m<<endl;return 0;}
	for (int i=0;i<m;i++)
		cin>>a>>b,g[a][b]=g[b][a]=1;
	for(int i=1;i<=6;i++){
		for(int j=i+1;j<=7;j++){
			t=0;
			for(int i1=1;i1<=7;i1++){
				if(g[i][i1]==1 && g[j][i1]==1)
					t++;}
			mn=min(mn,t);}}
	cout<<m-mn;
}
#include<bits/stdc++.h>
using namespace std;
int n,q;
int b;
int a[3][100010];
int blo[100010];
bool judge(int x){
	return (a[1][x]&&a[2][x])||(a[1][x]&&a[2][x+1])||(a[2][x]&&a[1][x+1]);
}
int main(){
	cin>>n>>q;
	while(q--){
		int u,v;
		cin>>u>>v;
		if(a[u][v]){
			a[u][v]=0;
			if(!judge(v)&&blo[v]){
				blo[v]=0;
				b--;
			}
			if(!judge(v-1)&&blo[v-1]){
				blo[v-1]=0;
				b--;
			}
			if(!b){
				cout<<"Yes"<<'\n';
			}
			else cout<<"No"<<'\n';
		}
		else{
			a[u][v]=1;
			if(judge(v)&&!blo[v]){
				blo[v]=1;
				b++;
			}
			if(judge(v-1)&&!blo[v-1]){
				blo[v-1]=1;
				b++;
			}
			if(!b){
				cout<<"Yes"<<'\n';
			}
			else cout<<"No"<<'\n';
		}
	}
	return 0;
}
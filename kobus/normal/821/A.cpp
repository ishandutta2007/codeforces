#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define INF 1000000000
typedef long long ll;

int m[100][100];
int vx[112];
int vy[112];
int n;

int bb(int x){
	int com=0,fim=n-2,meio;
	while(com<=fim){
		meio=(com+fim)/2;
		if(vy[meio]==x){
			return 1;
		}
		else if(vy[meio]<x){
			com=meio+1;
		}
		else{
			fim=meio-1;
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	bool resp=true;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>m[i][j];
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(m[i][j]!=1){
				int mark=0;
				for(int k=0;k<n;k++){
					if(k!=j){
						vx[mark]=m[i][k];
						mark++;
					}
				}
				mark=0;
				for(int k=0;k<n;k++){
					if(k!=i){
						vy[mark]=m[k][j];
						mark++;
					}
				}
				sort(vx,vx+n-1);
				sort(vy,vy+n-1);
				bool respar=false;
				for(int k=0;k<n-1;k++){
					if(bb(m[i][j]-vx[k])){
						respar=true;
					}
				}
				if(respar==false){
					resp=false;
				}
			}
		}
	}

	if(resp==true){
		cout<<"Yes\n";
	}
	else{
		cout<<"No\n";
	}

	
	return 0;
}
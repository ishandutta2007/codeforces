#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;

int m[112][112];
int rm[112];
int cm[112];


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int r,c;
	cin>>r>>c;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>m[i][j];
		}
	}
	if(r<=c){
		for(int i=0;i<r;i++){
			rm[i]=512;
			for(int j=0;j<c;j++){
				if(m[i][j]<rm[i]){
					rm[i]=m[i][j];
				}
			}
		}
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				m[i][j]-=rm[i];
			}
		}
		for(int i=0;i<c;i++){
			cm[i]=512;
			for(int j=0;j<r;j++){
				if(m[j][i]<cm[i]){
					cm[i]=m[j][i];
				}
			}
		}
		for(int i=0;i<c;i++){
			for(int j=0;j<r;j++){
				m[j][i]-=cm[i];
			}
		}
	}else{
		for(int i=0;i<c;i++){
			cm[i]=512;
			for(int j=0;j<r;j++){
				if(m[j][i]<cm[i]){
					cm[i]=m[j][i];
				}
			}
		}
		for(int i=0;i<c;i++){
			for(int j=0;j<r;j++){
				m[j][i]-=cm[i];
			}
		}
		for(int i=0;i<r;i++){
			rm[i]=512;
			for(int j=0;j<c;j++){
				if(m[i][j]<rm[i]){
					rm[i]=m[i][j];
				}
			}
		}
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				m[i][j]-=rm[i];
			}
		}
	}

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(m[i][j]!=0){
				cout<<"-1\n";
				return 0;
			}
		}
	}

	int resp=0;

	for(int i=0;i<c;i++){
		resp+=cm[i];
	}
	for(int i=0;i<r;i++){
		resp+=rm[i];
	}
	cout<<resp<<"\n";


	for(int i=0;i<c;i++){
		for(int j=0;j<cm[i];j++){
			cout<<"col "<<i+1<<"\n";
		}
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<rm[i];j++){
			cout<<"row "<<i+1<<"\n";
		}
	}

	return 0;
}
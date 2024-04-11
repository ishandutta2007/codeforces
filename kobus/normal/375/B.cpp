#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAXN 5123
#define INF INT_MAX
#define MOD 1000000007
#define pii pair<int,int>
#define double long double 

char m[MAXN][MAXN];

int uf[MAXN][MAXN];

bool rev(int a,int b){
	return a>b;
}

int lin,col;

int aux[MAXN];

void sorte(vector<int> &coisa){
	for(auto x:coisa)aux[x]++;
	int at=0;
	for(int i=col;i>=0;i--){
		while(aux[i]>0){
			coisa[at]=i;
			at++;
			aux[i]--;
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>lin>>col;

	for(int i=0;i<lin;i++)for(int j=0;j<col;j++)cin>>m[i][j];

	for(int i=0;i<lin;i++){
		int con=0;
		for(int j=col-1;j>=0;j--){
			if(m[i][j]=='1')con++;
			else con=0;
			uf[i][j]=con;
		}
	}

	for(int i=0;i<lin;i++){
		//for(int j=0;j<col;j++)cout<<uf[i][j]<<" ";
		//cout<<endl;
	}

	int resp=0;
	vector<int> coisa(lin);
	for(int j=0;j<col;j++){
		for(int i=0;i<lin;i++){
			coisa[i]=uf[i][j];
		}
		sorte(coisa);
		for(int i=0;i<lin;i++){
			resp=max(resp,(i+1)*coisa[i]);
			//cout<<"lin "<<i<<" col "<<j<<" "<<uf[i][j]<<" "<<(i+1)*uf[i][j]<<endl;
		}
	}

	cout<<resp<<endl;


	return 0;
}
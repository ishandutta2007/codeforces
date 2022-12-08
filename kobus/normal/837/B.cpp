#include <bits/stdc++.h>

using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int,int>pii;

#define MAXN 1000000007
#define INF INT_MAX

int n,m;

char ma[112][112];
char ma2[112][112];

bool isflag(){
	int mark=1;
	if(n%3!=0){
		//cout<<"A";
		mark=0;
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<m;j++){
			if(ma[j][i]!=ma[j-1][i]){
				//cout<<"B";
				mark=0;
			}
		}
	}
	int b=0,r=0,g=0;
	for(int i=0;i<3;i++){
		char agr=ma[0][i*(n/3)];
		//cout<<agr;
		if(agr=='B'){
			b++;
		}
		else if(agr=='R'){
			r++;
		}
		else{
			g++;
		}
		for(int j=i*(n/3);j<(i+1)*(n/3);j++){
			if(ma[0][j]!=agr){
				//cout<<"C";
				mark=false;
			}
		}
	}
	if(b!=1 || r!=1 || g!=1){
		//cout<<"D";
		mark=false;
	}
	return mark;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>m>>n;

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>ma[i][j];
		}
	}

	bool teste1=isflag();


	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			ma2[j][i]=ma[i][j];
		}
	}
	swap(m,n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			ma[i][j]=ma2[i][j];
		}
	}

	bool teste2=isflag();

	if(teste1 || teste2){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}




	return 0;
}
#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 1123456
#define INF INT_MAX;
#define MOD 1000000007

int m[30][2][2];
int resp[2][2];

void make(int a){
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				m[a][i][j]+=m[a-1][i][k]*m[a-1][k][j];
				m[a][i][j]%=MOD;
			}
		}
	}
}

void sum(int a){
	int respar[2][2];
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			respar[i][j]=resp[i][j];
			resp[i][j]=0;
		}
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				resp[i][j]+=m[a][i][k]*respar[k][j];
				resp[i][j]%=MOD;
			}
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	m[0][0][0]=0;m[0][0][1]=3;
	m[0][1][0]=1;m[0][1][1]=2;

	resp[0][0]=1;resp[1][1]=1;

	for(int i=1;i<30;i++)make(i);

	int n;
	cin>>n;

	for(int i=0;i<30;i++){
		if((n>>i)%2==1){
			sum(i);
		}
	}

	cout<<resp[0][0]<<endl;
	
	return 0;
}
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
#define INF LLONG_MAX;
#define MOD 1000000

int vc[3][3]={
	{0,0,0},
	{1,0,0},
	{1,1,0}
};
int vs[3][3]={
	{0,0,0},
	{0,0,1},
	{0,1,1}	
};

int v[3];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>v[0]>>v[1]>>v[2];

	int resp=INF;

	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			int vh[3];
			int maxi=0;
			for(int k=0;k<3;k++){
				vh[k]=v[k]+vc[i][k]+vs[j][k];
				maxi=max(maxi,vh[k]);
			}
			int respar=0;
			for(int k=0;k<3;k++){
				respar+=maxi-vh[k];
			}
			resp=min(resp,respar);

		}
	}

	cout<<resp<<endl;
	

	return 0;
}
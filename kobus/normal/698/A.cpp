#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
//#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 1123456
#define INF INT_MAX;
#define MOD 1000000

int memo[112][2][2];

int n;

int v[112];

int pd(int cara,bool gym,bool con){
	if(cara==n)return 0;
	if(memo[cara][gym][con]==-1){
		int respar=INF;
		if((v[cara]==3||v[cara]==2)&&gym==false){
			respar=min(respar,pd(cara+1,1,0));
		}
		if((v[cara]==3||v[cara]==1)&&con==false){
			respar=min(respar,pd(cara+1,0,1));
		}
		respar=min(respar,1+pd(cara+1,0,0));
		memo[cara][gym][con]=respar;
	}
	return memo[cara][gym][con];
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	for(int i=0;i<n;i++){
		memo[i][0][0]=-1;
		memo[i][0][1]=-1;
		memo[i][1][0]=-1;
		memo[i][1][1]=-1;
	}
	cout<<pd(0,0,0)<<endl;


	return 0;
}
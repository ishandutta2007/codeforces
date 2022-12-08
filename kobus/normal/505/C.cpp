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
#define int long long

//last pos, last jump size
int memo[31234][500];

int n,d;

int gems[31234];

int pd(int i,int s){
	if(i>30000)return 0;
	int &resp=memo[i][s];
	if(resp==-1){
		int offset=s-250;
		int jumpsize=offset+d;
		//if(i<=30)cout<<i<<" "<<jumpsize<<endl;
		resp=gems[i]+pd(i+jumpsize,s+1);
		resp=max(resp,gems[i]+pd(i+jumpsize,s));
		if(jumpsize!=1)resp=max(resp,gems[i]+pd(i+jumpsize,s-1));
	}
	return resp;
}



int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>d;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		gems[x]++;
	}
	for(int i=0;i<31234;i++){
		for(int j=0;j<500;j++)memo[i][j]=-1;
	}
	cout<<pd(0,250)<<endl;

	return 0;
}
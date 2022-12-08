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
#define INF LLONG_MAX/4
#define MOD 1000000007


int n;

long double calc(int i,int m){
	long double cara=1.*i/m;
	long double v[18];
	v[0]=cara;
	for(int i=1;i<18;i++){
		v[i]=v[i-1]*v[i-1];
	}
	long double resp=1;
	for(int i=0;i<18;i++){
		if((n>>i)%2==1)resp*=v[i];
	}
	return resp;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout<<setprecision(9);

	int m;
	cin>>m>>n;

	long double resp=0;
	long double lc=0;
	for(int i=1;i<=m;i++){
		long double prob=calc(i,m);
		//cout<<prob<<endl;
		prob-=lc;
		resp+=1.*i*prob;
		lc+=prob;
	}
	cout<<resp<<endl;


	return 0;
}
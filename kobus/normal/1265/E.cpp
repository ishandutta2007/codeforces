#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAXN 1123
#define INF LLONG_MAX
#define MOD 998244353 
#define pii pair<int,int> 
#define int long long

int tothe(int a,int b){
	if(b==0)return 1;
	if(b%2)return (a*tothe((a*a)%MOD,b/2))%MOD;
	else return tothe((a*a)%MOD,b/2);
}

int inv(int x){
	return tothe(x,MOD-2);
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	int prob=1;
	int cima=0;
	int baixo=1;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		int inver=(x*inv(100))%MOD;
		cima+=baixo;
		cima%=MOD;
		baixo*=inver;
		baixo%=MOD;
		//cout<<cima<<" "<<4*baixo<<endl;
	}
	cout<<(cima*inv(baixo))%MOD<<endl;


	return 0;
}
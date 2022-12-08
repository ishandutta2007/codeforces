#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAXN 5123
#define INF INT_MAX
#define MOD (1ll<<(32)) 
#define pii pair<int,int>
#define double long double 

bool lucky(int x){
	x=abs(x);
	while(x!=0){
		if(x%10==8)return 1;
		x=x/10;
	}
	return 0;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout<<setprecision(11)<<fixed;

	int resp=1;
	int n;
	cin>>n;
	n++;
	while(!lucky(n)){
		n++;
		resp++;
	}
	cout<<resp<<endl;



	return 0;
}
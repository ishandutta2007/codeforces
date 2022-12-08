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

int n,k;


//numero de 1 a k+1 menos o x
pii ask(int x){
	cout<<"? ";
	for(int i=1;i<=k+1;i++){
		if(i!=x)cout<<i<<" ";
	}
	cout<<endl;
	fflush(stdout);
	int a,b;
	cin>>a;
	assert(a!=-1);
	cin>>b;
	return mp(a,b);
}

int32_t main(){

	cin>>n>>k;
	map<int,int> m;
	int maior=0;
	for(int i=1;i<=k+1;i++){
		pii resp=ask(i);
		m[resp.s]++;
		maior=max(maior,resp.s);
	}
	cout<<"! "<<m[maior]<<endl;
	fflush(stdout);


	return 0;
}
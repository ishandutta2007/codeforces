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



int v[1123];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	int a,b,c;
	cin>>a>>b;
	int resp=INF;
	v[0]=a;v[1]=b;
	for(int i=2;i<n;i++){
		cin>>v[i];
		c=v[i];
		resp=min(resp,c-a);
		a=b;
		b=c;
	}
	for(int i=1;i<n;i++)resp=max(resp,v[i]-v[i-1]);
	cout<<resp<<endl;

	return 0;
}
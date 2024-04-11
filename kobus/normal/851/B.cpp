#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;
typedef pair<int,int>pii;
 
#define MAXN 11234567
#define INF INT_MAX/2
#define MOD 1000000007
#define int long long

int vx[3];
int vy[3];


int dis(int a,int b){
	return (vx[a]-vx[b])*(vx[a]-vx[b])+(vy[a]-vy[b])*(vy[a]-vy[b]);
}


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	for(int i=0;i<3;i++){
		cin>>vx[i]>>vy[i];
	}
	if(vx[1]-vx[0]==vx[2]-vx[1] && vy[1]-vy[0]==vy[2]-vy[1]){
		cout<<"No\n";
	}
	else if(dis(0,1)==dis(1,2))cout<<"Yes\n";
	else cout<<"No\n";


	
	return 0;
}
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
#define INF INT_MAX/2
#define MOD 1000000

int v[100];


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,x;
	cin>>n>>x;
	int resp=0;
	for(int i=0;i<n;i++){
		int y;cin>>y;
		v[y]++;
	}
	for(int i=0;i<x;i++){
		if(v[i]==0)resp++;
	}
	resp+=v[x];
	cout<<resp<<endl;

	return 0;
}
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

pii v[112345];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		cin>>v[i].f>>v[i].s;
	}
	int lo=v[0].f;
	int resp=1;
	for(int i=1;i<n;i++){
		if((v[i].f-v[i].s)>lo){
			resp++;
			lo=v[i].f;
		}
		else if(i==n-1||(v[i].f+v[i].s)<v[i+1].f){
			resp++;
			lo=v[i].f+v[i].s;
		}
		else lo=v[i].f;
	}

	cout<<resp<<endl;

	return 0;
}
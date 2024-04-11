#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
 
#define MAXN 11234567890123
#define INF INT_MAX/2
#define MOD 1000000

int v[112];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	int nmax=0;

	for(int i=0;i<n;i++){
		cin>>v[i];
		if(v[i]==0)nmax++;
	}

	for(int i=0;i<n;i++){
		int nat=0;
		if(v[i]==1){
			for(int j=0;j<n;j++){
				if(v[j]==0 && j<i)nat++;
				if(v[j]==1 && j>=i)nat++;
			}
		}
		nmax=max(nmax,nat);
	}

	cout<<nmax<<endl;

	
	return 0;
}
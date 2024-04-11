#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 512345
#define INF INT_MAX/2
#define MOD 1000000007

int v[112345];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	int last=-INF;
	int mini=INF;
	int resp=INF;

	for(int i=0;i<n;i++){
		cin>>v[i];
		mini=min(mini,v[i]);
	}

	for(int i=0;i<n;i++){
		if(v[i]==mini){
			resp=min(resp,i-last);
			last=i;
		}
	}

	cout<<resp<<endl;



	return 0;
}
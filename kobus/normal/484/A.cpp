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
#define INF INT_MAX;
#define MOD 1000000

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		ll l,r;
		cin>>l>>r;
		ll resp;
		int mark=-1;
		while(l<=r){
			resp=l;
			mark++;
			if((l>>mark)%2==0){
				l+=(1ll<<mark);
			}
			//cout<<l<<endl;
		}
		cout<<resp<<endl;
	}
	
	return 0;
}
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

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int last=-1;
		bool foi=0;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			if(!foi && last!=-1 && abs(x-last)>=2){
				cout<<"YES "<<endl<<i<<" "<<i+1<<endl;
				foi=1;
			}
			last=x;
		}
		if(!foi)cout<<"NO"<<endl;
	}

	return 0;
}
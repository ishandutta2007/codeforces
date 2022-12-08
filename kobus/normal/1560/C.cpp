#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 312345;
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
#define pb push_back
#define MOD 1000000007


int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		int x;
		cin>>x;
		int at=1;
		int nxt=2;
		int cam=1;
		while(nxt<=x){
			at=nxt;
			nxt+=2*cam+1;
			cam++;
		}
		if(x<at+cam){
			cout<<x-at+1<<" "<<cam<<"\n";
		}
		else cout<<cam<<" "<<nxt-x<<"\n";
	}
	
}
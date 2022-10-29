#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,k1,k2,a[1003],b[1003];
void solve(){
	cin>>n>>k1>>k2;
	rep(i,0,n){
		cin>>a[i];
	}    
	rep(i,0,n){
		cin>>b[i];
	}
	priority_queue<int> pq; 
	rep(i,0,n){
		pq.push(abs(a[i]-b[i]));
	}
	int h=k1+k2;
	rep(i,0,k1+k2){
		int d=pq.top();
		if(d==0) break;
		h--;
		pq.pop();
		pq.push(d-1);
	}
	if(h){
		cout<<h%2<<endl;
		return;
	}
	int ans=0;
	while(!pq.empty()){
		int d=pq.top();
		pq.pop();
		ans+=d*d;
	}
	cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
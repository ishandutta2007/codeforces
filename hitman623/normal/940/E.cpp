#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii 		vector<pii>
#define mi 			map<int,int>
#define mii			map<int,pii>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        100000000000000007LL
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
int n,c,a[100005],dp[100005];
void solve(){
    cin>>n>>c;
    rep(i,1,n+1){
        cin>>a[i];
    }
    if(c==1) {cout<<0;return;}
    dp[0]=0;
    multiset<int> s;
    int sum=0;
    rep(i,1,n+1){
        dp[i]=hell;
        if(i-c>0)
        s.erase(s.find(a[i-c])),sum-=a[i-c];
        s.insert(a[i]),sum+=a[i];
        if(i>=c) dp[i]=dp[i-c]+sum-*s.begin();
        dp[i]=min(dp[i],dp[i-1]+a[i]);
    }
    cout<<dp[n]<<endl;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
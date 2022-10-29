#include <bits/stdc++.h>

#define ll          long long
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
ll k,d;
double t;
void solve(){
    cin>>k>>d>>t;
    d=((k+d-1)/d)*d;
    ll cur=t/(k+(1.0l*(d-k)/2));
    t-=1.0l*cur*(k+(1.0l*(d-k)/2));
    cur*=d;
    cout<<fixed<<setprecision(10);
    if(k<t){
        cout<<cur+k+2*(t-k);
    }
    else{
        cout<<cur+t;
    }
    return;
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
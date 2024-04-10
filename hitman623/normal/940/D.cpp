#include <bits/stdc++.h>

#define int          long long
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
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
int n,a[100005],b[100005],l=-hell,r=hell;
string s;
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
    }
    cin>>s;
    rep(i,0,n){
        b[i]=s[i]-'0';
    }
    rep(i,4,n){
        if(b[i]==0){
            if(b[i-1] && b[i-2] && b[i-3] && b[i-4]){
                r=min(r,min({a[i],a[i-1],a[i-2],a[i-3],a[i-4]})-1);
            }
        }
        if(b[i]==1){
            if(!b[i-1] && !b[i-2] && !b[i-3] && !b[i-4]){
                l=max(l,max({a[i],a[i-1],a[i-2],a[i-3],a[i-4]})+1);
            }
        }
    }
    if(l==-hell) l=-hell+7;
    if(r==hell) r=hell-7;
    cout<<l<<" "<<r;
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
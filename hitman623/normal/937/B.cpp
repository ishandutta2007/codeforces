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
#define hell        1000000007LL
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
void solve(){
    int p,y;
    cin>>p>>y;
    for(int i=y;i>=max(1,y-2000);i--){
        int f=1;
        for(int j=2;j*j<=i;++j){
            if(i%j==0){
                if(j<=p) {f=0;break;}
            }
        }
        if(f && i>p) {cout<<i;return;}
    }
    cout<<-1;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
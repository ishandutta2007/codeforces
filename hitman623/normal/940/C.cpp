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

void solve(){
    set<char> st;
    int n,k;
    string s;
    cin>>n>>k>>s;
    for(auto i:s){
        st.insert(i);
    }
    char l=*st.begin(),r=*st.rbegin();
    if(k>n){
        cout<<s;
        rep(i,0,k-n){
            cout<<l;
        }
        return;
    }
    int i;
    for(i=k-1;i>=0;i--){
        if(s[i]!=r) break;
    }
    rep(j,0,i){
        cout<<s[j];
    }
    for(auto j:st){
        if(j>s[i]) {cout<<j;break;}
    }
    rep(j,i+1,k){
        cout<<l;
    }
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
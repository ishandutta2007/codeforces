#include <bits/stdc++.h>

#define ll          long long
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

void solve(){
	int a=0,b=0,c=0;
    string s;
    cin>>s;
    string r=s;
    sort(all(r));
    rep(i,0,sz(s)){
    	if(r[i]!=s[i]) {cout<<"NO";return;}
    }
    if(sz(s)<3) {cout<<"NO";return;} 
    rep(i,0,sz(s)){
    	if(s[i]=='a') a++;
    	if(s[i]=='b') b++;
    	if(s[i]=='c') c++;
    }
    if(a and b and (c==a || c==b)) cout<<"YES";
    else cout<<"NO";
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
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
#define hell        10000007
#define hell2       15000000
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
int n;
string s,t;
vi ans;
void shift(int x){
    ans.pb(n);
    ans.pb(x);
    ans.pb(1);
    reverse(s.begin()+x+1,s.end());
    char ch=s[x];
    for(int i=x;i>0;i--){
        s[i]=s[i-1];
    }
    s[0]=ch;
}
void solve(){
    cin>>n>>s>>t;
    if(!is_permutation(all(s),t.begin())) {cout<<-1;return;}
    for(int i=n-1;i>=0;i--){
        for(int j=n-i-1;j<n;j++){
            if(t[i]==s[j]){
                shift(j);
                break;
            }
        }
    }
    cout<<sz(ans)<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }
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
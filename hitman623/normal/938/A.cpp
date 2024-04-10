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
#define hell        1000000000
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
bool is(char ch){
	return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='y');  
}
void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=n-1;i>=1;i--){
		if(is(s[i-1]) && is(s[i])) s[i]='#';
	}
	rep(i,0,n){
		if(s[i]!='#') cout<<s[i];
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	return 0;
}
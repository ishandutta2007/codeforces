#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define endl "\n"
map<char,int> myp;
int inv[4] = {1,0,3,2};
int  main()
{
	myp['L'] = 0,myp['R']=1, myp['U']=2, myp['D'] = 3;
	int n;
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string s;
	cin>>n>>s;
	int cnt = 1;
	bool done[4] = {0};
	for(int i = 0;i<n;i++){
		int x = myp[s[i]];
		if(done[inv[x]])
		{
			memset(done,0,sizeof done);
			cnt++;
		}
		done[x] = 1;
	}
	cout<<cnt;
}
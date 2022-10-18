//Krzysztof Boryczka
#pragma GCC optimize "O3"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)x.size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'
//END OF TEMPLATE

const int N=2010;

int n, k, l, r, mid;
int t[N], dp[N];

int comp(int a, int b){
	return (abs(t[a]-t[b])+b-a-1)/(b-a);
}

bool check(int a){
	memset(dp, inf*2, sizeof(dp));
	dp[0]=0;
	FOR(i, 1, n+1){
		FOR(j, 0, i-1){
			if(j==0) t[j]=t[i];
			if(i==n+1) t[i]=t[j];
			if(comp(j, i)<=a) dp[i]=min(dp[i], dp[j]+i-j-1);
		}
	}
	return dp[n+1]<=k;
}

void solve(){
	cin>>n>>k;
	FOR(i, 1, n) cin>>t[i];
	l=-1; r=inf*2;
	while(l+1<r){
		mid=l+(r-l)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	cout<<r<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
//Krzysztof Boryczka
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

const int N=4e5+5;

ll a, b, ans;
int dist[N];
int k, x, pp, lck=1;
queue<int> q;

int path(int s, int d){
	memset(dist, 0, sizeof(dist));
	dist[s]=1;
	q.push(s);
	while(!dist[d]){
		x=q.front();
		q.pop();
		if(x==0) continue;
		FOR(i, 1, k){
			if(i==1) pp=1;
			else pp=x%i;
			if(!dist[x-pp]){
				dist[x-pp]=dist[x]+1;
				q.push(x-pp);
			}
		}
	}
	while(!q.empty()) q.pop();
	return dist[d]-1;
}

void solve(){
	cin>>a>>b>>k;
	FOR(i, 2, k) lck*=i/__gcd(lck, i);
	if(a-a%lck<b){
		cout<<path(a%lck+lck*(a%lck==0), b%lck)<<ent;
		return;
	}
	ans+=path(a%lck, 0);
	a-=a%lck;
	ans+=(a-b)/lck*path(lck, 0);
	if(b%lck) ans+=path(lck, b%lck);
	cout<<ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
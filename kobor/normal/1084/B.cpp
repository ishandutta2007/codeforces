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
#define SIZE(x) ((int)(x).size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'
#define WATCH(x) cout<<(#x)<<" is "<<(x)<<ent

//END OF TEMPLATE

ll t[1010];
int n;

ll ile(ll v){
	ll odp=0;
	FOR(i, 1, n){
		odp+=max(0ll, t[i]-v);
	}
	return odp;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll s, sum=0, l, r=INF, sr;
	cin>>n>>s;
	FOR(i, 1, n){
		cin>>t[i];
		sum+=t[i];
		r=min(r, t[i]);
	}
	if(sum<s){
		cout<<-1<<ent;
		return 0;
	}
	l=0;
	r++;
	while(l+1<r){
		sr=(l+r)/2;
		if(ile(sr)>=s){
			l=sr;
		}
		else{
			r=sr;
		}
	}
	cout<<l<<ent;
	return 0;
}
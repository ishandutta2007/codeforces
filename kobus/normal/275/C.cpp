#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int,int>pii;
 
#define MAXN 11234567890123
#define INF INT_MAX - 5000

set<ll> s;
ll v[2];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n,k;
	cin>>n>>k;

	for(int i=0;i<n;i++){
		ll y;
		cin>>y;
		s.insert(y);
	}
	ll resp=0;
	while(!s.empty()){
		ll el=*s.begin();
		v[0]=0;v[1]=0;
		int mark=0;
		while(s.find(el)!=s.end()){
			s.erase(el);
			v[mark]++;
			mark++;
			mark=mark%2;
			el*=k;
		}
		resp+=max(v[0],v[1]);
	}
	cout<<resp<<endl;
	return 0;
}
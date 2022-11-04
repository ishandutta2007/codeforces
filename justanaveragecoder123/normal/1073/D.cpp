#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define xx first
#define yy second
#define sz(x) (int)(x).size()
#define gc getchar
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;

int main() {
	IO;
	ll n, T;
	cin>>n>>T;
	vector<ll> a(n);
	ll sum=0;
	priority_queue<ll> pq;
	for(int i=0;i<n;++i) {
		cin>>a[i];
		sum+=a[i];
		pq.push(a[i]);
	}
	ll ans=0;
	while(!pq.empty()) {
		//cerr<<sum<<" "<<T<<"\n";
		while(!pq.empty() && pq.top()>T) {
			sum-=pq.top();
			pq.pop();
		}
		
		if(pq.empty()) break; 
		
		if(sum<=T) {
			ll curr=T/sum;
			T-=curr*sum;
			ans+=ll(pq.size())*curr;
		}else {
			for(int i=0;i<n;++i) {
				if(a[i]<=T) {
					T-=a[i];
					ans++;
				}
			}
		}
		
	}
	
	cout<<ans<<"\n";
	
	return 0;
}
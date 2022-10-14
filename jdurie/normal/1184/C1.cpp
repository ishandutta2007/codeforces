#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

#define x first
#define y second

pair<ll, ll> points[100];

int main() {
				  ios_base::sync_with_stdio(false);
					  cin.tie(NULL);

	ll n;
	cin>>n;
	for (ll i=0;i<4*n+1; ++i) {
		ll x, y;
		cin>>x>>y;
		points[i] = {x,y};
	}

	for (ll x=0; x<50; x++) {
		for (ll y=0; y<50; y++) {
			for (ll s=1; s<=50-max(x, y); ++s) {
				pair<ll,ll> fail={-1,-1};
				bool bs1=false;
				for (ll i=0; i<4*n+1; ++i) {
					pair<ll, ll> p=points[i];
					if (!(((p.x==x || p.x == x+s) && (p.y>=y && p.y<=y+s)) || ((p.y==y || p.y == y+s) && (p.x>=x && p.x<=x+s)))) {
						if (fail.x==-1) {
							fail = p;
						} else {
							bs1=true;
							break;
						}
					}
				}
				if (bs1==false && fail.x!=-1) {
					cout<<fail.x<<" "<<fail.y<<endl;
					return 0;
				}
			}
		}
	}
}
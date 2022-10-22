#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define si short int
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pill pair<ll,ll>
#define f first
#define s second
#define pilc pair<ll,char>
#define all(a) (a).begin(),(a).end()
#define rep(s,e,step) for(int i = (s); i < (e) ; i += step)
#define vrep(s,e,step) for(int j = (s); j < (e) ; j += step)
#define ex exit(0)
#define sz(a) (a).size()


using namespace std;

const ll N = 1e5 + 10;
const ll big = 1e18;
const ll block = 800;
const ll mod = 2;

ll q;

ll ans[26] = {1,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};

ll bitrev(ll n) {
	ll r = 0;
	bool was = 0;
	for(int i = 31; i >= 0 ; i--){
		if(n & (1 << i))
			was = 1;
		else if(was)
			r += 1 << i;
	}
	return r;
}

int main() {
	speed;
	cin >> q;
	while(q--) {
		ll a;
		cin >> a;
		ll b = bitrev(a);
		if(b == 0) {
			ll x = log2(a + 1);
			cout << ans[x - 1] << '\n';
		} else {
			cout << (a ^ b) << '\n';
		}
	}
}

/*
	Code written by
	Codeforces : I_Love_Trott
	mail : dzhon.snoudin@mail.ru
*/
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

ll b, k;

ll a[N];

ll c[N];

ll bin_pow(ll a,ll c){
	if(c == 0)
		return 1;
	if(c % 2)
		return (a * bin_pow(a, c - 1)) % mod;
	ll m = bin_pow(a, c / 2);
	return (m * m) % mod;
}

int main() {
    speed;
	cin >> b >> k;
	ll n = 0;
	for(int i = 0 ; i < k ; i++) {
		cin >> a[i];
		n += (a[i] * bin_pow(b, (k - i - 1))) % mod;
	}
	cout << (n % 2 ? "odd" : "even");
}

/*
	Code written by
	Codeforces : I_Love_Trott
	mail : dzhon.snoudin@mail.ru
*/
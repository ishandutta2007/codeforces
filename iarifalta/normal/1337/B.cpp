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

const ll N = 1;
const ll big = 1e18;
const ll block = 100;
const ll mod = 1e6;

ll t;

int main() {
    speed;
	cin >> t;
	while(t--) {
		ll x, y, z;
		cin >> x >> y >> z;
		ll s = x;
		while(s / 2 + 10 < s && y--)
			s = s / 2 + 10;
		while(z--)
			s -= 10;
		if(s <= 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}

/*
	Code written by
	Codeforces : I_Love_Trott
	mail : dzhon.snoudin@mail.ru
*/
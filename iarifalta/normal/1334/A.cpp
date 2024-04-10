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
//#define rep(s,e,s tep) for(int i = (s); i < (e) ; i += step)
#define vrep(s,e,step) for(int j = (s); j < (e) ; j += step)
#define ex exit(0)
#define sz(a) (a).size()


using namespace std;

const ll N = 1;
const ll big = 1e18;
const ll block = 800;
const ll mod = 1e6;

ll t;

int main() {
    speed;
	cin >> t;
	while( t-- ) { 
		ll n;
		cin >> n;
		ll x[n + 1][2];
		x[0][0] = x[0][1] = 0;
		bool ans = 1;
		for(int i = 1 ; i <= n ; i++) {
			cin >> x[i][0] >> x[i][1];
			if(x[i - 1][0] > x[i][0] || x[i - 1][1] > x[i][1] || x[i][1] - x[i - 1][1] > x[i][0] - x[i - 1][0])
				ans = 0;
		}
		cout << (ans ? "YES\n" : "NO\n");
	}
}

/*
	Code written by
	Codeforces : I_Love_Trott
	mail : dzhon.snoudin@mail.ru
*/
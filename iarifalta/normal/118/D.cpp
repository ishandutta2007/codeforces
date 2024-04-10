#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define si short int
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pill pair<ll,ll>
#define f first
#define s second

using namespace std;

const ll N = 101;
const ll big = 1e18;
const ll b = 11;
const ll mod = 1e8;

ll n , m;
ll k1 , k2;

ll dp[N][N][b][b];

bool was[N][N][b][b];

ll rec(ll a,ll b,ll c,ll d){
	if(a < 0 || b < 0 || c > k1 || d > k2)
		return 0;
	if(a == 0 && b == 0)
		return 1;
	if(was[a][b][c][d])
		return dp[a][b][c][d];	
	dp[a][b][c][d] = (rec(a - 1 , b,c + 1, 0) + rec(a , b - 1, 0 ,d + 1)) % mod;
	was[a][b][c][d] = 1;
	return dp[a][b][c][d];
}	

int main() {
    speed;
	cin >> n >> m;
	cin >> k1 >> k2;
	cout << rec(n , m , 0 , 0);
}

/*
	Code written by
	Codeforces : I_Love_Trott
	mail : dzhon.snoudin@mail.ru
*/
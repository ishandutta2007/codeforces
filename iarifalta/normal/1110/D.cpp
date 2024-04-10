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

const ll N = 1e6 + 10;
const ll big = 1e18;
const ll block = 800;
const ll mod = 1e6;

ll n, m;

ll per[N];

ll dp[N][4][4];


int main() {
    speed;
	cin >> n >> m;
	for(int i = 0, x ; i < n ; i++)
		cin >> x, per[x]++;
	for(int i = 1; i <= m; i++) {
		for(int t1 = 0, t2 = 0, t3 = 0; t3 != 3;( t1++,t1 > 2 ? t2++ : 0, t2 > 2 ? t3++ : 0, t1 %= 3, t2 %= 3)){
			if(t1 + t2 + t3 > per[i])
				continue;
			dp[i + 1][t2][t3] =  max(dp[i + 1][t2][t3], dp[i][t1][t2] + (per[i] - t1 - t2 - t3) / 3 + t3);
		}
	}
	cout << dp[m + 1][0][0];
}

/*
	i, i + 1 , i + 2
	i - 1, i , i + 1
	Code written by
	Codeforces : I_Love_Trott
	mail : dzhon.snoudin@mail.ru
*/
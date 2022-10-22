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
const ll mod = 2;

ll n;

ll a[N], d[N];

ll b[N], d1[N];

int main() {
	speed;
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	for(int j = 1 ; j <= n ; j++)
		d[j] = a[j] - a[j - 1];
	for(int i = 1 ; i <= n ; i++)
		cin >> b[i];
	for(int j = 1 ; j <= n ; j++)
		d1[j] = b[j] - b[j - 1];
	if(a[1] != b[1])
		cout << "No\n",ex;
	sort(d1, d1 + n + 1);
	sort(d, d + n + 1);
	for(int i = 1 ; i <= n ; i++)
		if(d[i] != d1[i])
			cout << "No\n",ex;
	cout << "Yes\n";
}

/*
	8
	1 2 4 8 16 32 64 128 256 

	Code written by
	Codeforces : I_Love_Trott
	mail : dzhon.snoudin@mail.ru
*/
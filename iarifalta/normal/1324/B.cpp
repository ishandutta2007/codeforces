#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define si short int
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pill pair<ll,ll>
#define f first
#define s second

using namespace std;

const ll N = 1e5;
const ll big = 1e18;
const ll block = 100;
const ll mod = 1e6;

ll t;
ll n;
ll a[N];


int main() {
    speed;
	cin >> t;
	while(t--){
		cin >> n;
		bool ans = 0;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i];
			for(int j = i - 2 ; j >= 0 ; j--){
				if(a[i] == a[j])
					ans = 1;
			}
		}
		cout << (ans ? "YES\n" : "NO\n");
	}
}

/*
	Code written by
	Codeforces : I_Love_Trott
	mail : dzhon.snoudin@mail.ru
*/
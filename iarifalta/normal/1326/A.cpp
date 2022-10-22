#include <bits/stdc++.h>
#define pb push_back
#define ll unsigned int
#define si short int
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pill pair<ll,ll>
#define f first
#define s second

using namespace std;

const ll N = 250002;
const ll big = 1e9;
const ll block = 100;
const ll mod = 1e6;

ll t;

int main() {
    speed;
    cin >> t;
    while(t--){
    	ll s;
    	cin >> s;
    	if(s == 1){
    		cout << -1 << '\n';
    		continue;
		}
    	cout << 2;
    	s--;
    	while(s--)
    		cout << 3;
    	cout << '\n';
	}
}

/*
	Code written by
	Codeforces : I_Love_Trott
	mail : dzhon.snoudin@mail.ru
*/
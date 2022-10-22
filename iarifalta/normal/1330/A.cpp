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
#define ex exit(0)

using namespace std;

const ll N = 281;
const ll big = 1e18;
const ll block = 800;
const ll mod = 1e6;

ll t;

bool b[N];

int main() {
    speed;
    cin >> t;
    while(t--){
    	ll n, x;
    	cin >> n >> x;
    	ll a[n + 1];
    	for(int i = 0 ; i < n ; i++)
    		cin >> a[i],b[a[i]] = 1;
    		
		for(int i = 1 ; i <= 201 ; i++){
			if(!b[i] && !x){
				cout << i - 1 << '\n';
				break;
			}
			if(!b[i])
				x--;
			b[i] = 0;
		}
    	for(int j = 1 ; j <= 201 ; j++)
			b[j] = 0;	
	}
}
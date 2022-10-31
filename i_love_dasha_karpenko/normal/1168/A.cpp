
#include <bits/stdc++.h>

using namespace std;
#define DIM  300007
#define DIM2 107
#define INF 10E16
#define MAXN 2750137
#define LG 18
#define MODULO 1000000007
#define MODULO2 MODULO*2
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef ll arr[DIM];
typedef vector<ll> vec;
typedef vector<ll> graph[DIM];
typedef pll parr[DIM];
typedef ll table[DIM][DIM2];
typedef ll arr2[DIM2];
typedef pair<string, string> ps;
struct pp {
	ll a, b;
	bool operator <(const pp& V)const {
		if (a == V.a)return b < V.b;
		return a < V.a;
	}
	bool operator ==(const pp& V)const {
		if (a == V.a && b == V.b)return 1;
		return 0;
	}
};

ll n,m,res = INF;
arr A,P,D;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)cin >> A[i];
    ll L = 0, R = m;
    A[0] = 0;
    while (R - L > 1) {
        ll tm = (L + R) / 2;
        ll prev = 0,y = 0;
        for (int i = 1; i <= n; i++) {
            ll r = A[i]+tm;
            if (A[i]>prev){
                if (tm<m-A[i]+prev)prev = A[i];
            }
            else if(r<prev){
                y = 1;
                break;
            }
        }
        if (y==0){
            R = tm;
        }
        else{
            L= tm;
        }
    }
    ll tm  = L;
    ll prev = 0,y = 0;
    for (int i = 1; i <= n; i++) {
        ll r = A[i]+tm;
        if (A[i]>prev){
            if (tm<m-A[i]+prev)prev = A[i];
        }
        else if(r<prev){
            y = 1;
            break;
        }
    }
    if (y==0){
        cout<<L<<endl;
    }
    else{
        cout<<R<<endl;
    }
}
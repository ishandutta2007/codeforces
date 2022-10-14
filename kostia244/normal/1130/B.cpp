#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<ll>
#define pi pair<int, int>
using namespace std;
//1 + 1 + 2 + 3 + 4 + 5 + 6 + 8
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n,i,j,a,v[100005][2];

int main() {
    ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
    cin >> n;
    for(int i=1;i<=2*n; i++)
       cin >> a, v[a][v[a][0] != 0] = i;
    i = j = 1, a = 0;
    for(int k = 1; k <= n;k++) {
        a += min(abs(v[k][0]-i)+abs(v[k][1]-j), abs(v[k][0]-j)+abs(v[k][1]-i));
        i=v[k][0], j = v[k][1];
    }
    printf("%I64d", a);
}
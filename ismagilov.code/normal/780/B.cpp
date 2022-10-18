#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endl "\n"
#define endd ; exit(0)
#define double long double

using namespace std;

const int MAXN = 1e3;
const int INF = 1e9;
const int MOD = 1e9 + 7;

vector<double> rast;
vector<double> ttime;

double prov(double g){
    double ans = 0;
    for (int i = 0; i < len(rast); i++){
        ans = max(ans, abs(rast[i] - g) / ttime[i]);
    }
    return ans;
}

main() {
	//freopen("kek.in", "r", stdin);
	//freopen("kek.out", "w", stdout);
	ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        rast.pb(a);
    }
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        ttime.pb(a);
    }
    double l = 0;
    double r = INF + 1;
    for (int i = 0; i < 1000; i++){
        double mid = (l + l + r) / 3.0;
        double mid1 = (r + l + r) / 3.0;
        if (prov(mid) < prov(mid1)){
            r = mid1;
        }
        else{
            l = mid;
        }
    }
    cout.fixed;
    cout << setprecision(10);
    cout << prov(l);
}
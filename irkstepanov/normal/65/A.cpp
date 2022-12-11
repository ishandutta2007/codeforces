#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

void LOSE() {
	cout << "Hermione\n";
	exit(0);
}

void WIN() {
	cout << "Ron\n";
	exit(0);
}

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    ll a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    if (b == 0) {
    	if (c == 0 && d != 0) {
    		WIN();
    	} else {
    		LOSE();
    	}
    }
    if (a == 0) {
    	if (d != 0) {
    		WIN();
    	} else {
    		LOSE();
    	}
    }

    if (d == 0) {
    	LOSE();
    }
    if (c == 0) {
    	WIN();
    }

    if (f == 0) {
    	LOSE();
    }
    if (e == 0) {
    	WIN();
    }

    if (b * d * f > a * c * e) {
    	WIN();
    } else {
    	LOSE();
    }

}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(15);
	double H, L;
	cin >> H >> L;
	cout << (L * L - H * H) / H / 2;
	return 0;
}
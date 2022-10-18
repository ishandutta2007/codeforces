#include <bits/stdc++.h> 
#define vc vector
#define pr pair<int, int>
#define ll long long
#define pb push_back
#define fs first
#define sc second
#define mp make_pair

using namespace std;

#define int long long

main(){
	int n, b, d;
	cin >> n >> b >> d;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int tek = 0;
	int ans = 0;
	for (int i = 0; i < n; i++){
		if (a[i] <= b){
			tek += a[i];
			ans += (tek > d);
			tek = (tek <= d) * tek;
		}
	}
	cout << ans;
}
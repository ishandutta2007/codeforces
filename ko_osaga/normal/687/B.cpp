#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

int n, k;

int gcd(int x, int y){
	return y ? gcd(y, x%y) : x;
}

int main(){
	cin >> n >> k;
	int gob = 1;
	for(int i=0; i<n; i++){
		int t;
		scanf("%d",&t);
		t = gcd(t, k);
		gob *= t / gcd(t, gob);
	}
	printf(k == gob ? "Yes" : "No");
}
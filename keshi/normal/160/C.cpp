#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;

#define ll long long

ll n, k, a[MAXN];
map<ll, ll> m;

int main(){
 cin >> n >> k;
 
 for(ll i = 0; i < n; i++){
  cin >> a[i];
  m[a[i]]++;
 }
 sort(a, a + n);
 	for(ll i = 0; i < n; i++){
	  if(i == 0 || a[i] != a[i - 1]){
	   if(k <= n * m[a[i]]){
	   	cout << a[i] << " " << a[(k - 1) / m[a[i]]] << endl;
	   	return 0;
	   }
	   k -= n * m[a[i]];
	  }
	}
 
 return 0;
}
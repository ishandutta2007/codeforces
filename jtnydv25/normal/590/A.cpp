#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define vll vector<ll >
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define endl "\n"
const int N = 5e5 +10;
int a[N];
int b[N];
// 101010101010101010101
int main(){
	int t = 1, n;
	sd(n);
	for(int i = 1; i <= n; i++) sd(a[i]);
	int i = 2, ans = 0;
	while(i <= n){
		int j = i;
		while(j <= n && a[j] != a[j - 1]) j++;
		if(i > j - 2){i = j + 1; continue;}
		// i to j - 2
		int mid = (i + j - 2) >> 1;
		ans = max(ans, max(mid - i + 1, j - 2 - (mid + 1) + 1));
		for(int k = i; k <= mid; k++) a[k] = a[i - 1];
		for(int k = mid + 1; k <= j - 2; k++) a[k] = a[j - 1];
		i = j + 1;
	}
	pd(ans);
	for(int i = 1; i <= n; i++)
		printf("%d ", a[i]);
}
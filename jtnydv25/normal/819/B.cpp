#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define sd(x) scanf("%d", &(x))
#define pd(n) printf("%d\n", n)
#define vi vector<int>
#define pb push_back
#define ll long long
#define F first
#define S second

const int N = 1e6 + 20;
int p[N];
int decr = 0, inc = 0;
vector<int> shift_to_inc[N], shift_to_decr[N];
bool INCR[N], DECR[N];
int main(){
	int n, id = 0;
	sd(n);
	ll ans = 0;
	for(int i = 1;i <= n; i++){
		sd(p[i]), ans += abs(p[i] - i);
		if(p[i] > i){
			decr++;
			DECR[p[i]] = 1;
			shift_to_inc[p[i] - i].pb(p[i]);
			shift_to_decr[(n - i + 1) % n].pb(p[i]);
		}
		else{
			inc++;
			INCR[p[i]] = 1;
			shift_to_decr[(n - i + 1) % n].pb(p[i]);
			shift_to_inc[(p[i] - i + n) % n].pb(p[i]);
		}
	}
	ll ANS = ans;
	for(int k = 1; k < n; k++){
		// find change
		int change = inc - decr;
		int x = p[(-k + n) % n + 1];
		if(INCR[x]){
			change --;
		}
		else{
			change ++;
		}
		change += abs(x - 1) - abs(x - n);
		ANS += change;
		if(ANS < ans){
			ans = ANS; id = k;
		}
		for(int v : shift_to_decr[k]){
			DECR[v] = 1; INCR[v] = 0;
			inc--; decr++;
		}
		for(int v : shift_to_inc[k]){
			INCR[v] = 1; DECR[v] = 0;
			inc++; decr--;
		}
		// cerr << ANS << " " << brute(n, k) << endl;
	}
	printf("%lld %d", ans, id);
}
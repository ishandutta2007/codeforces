#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;
int a[MAXN];

void read(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
}

set<int> mp1, mp2, mp;
int b[MAXN];
//1 Yes
//2 No

int check(ll lim){
	int flag = 1;
	mp.clear();
	for(int i = 1; i <= n; i++){
		int x = a[i];
		while(x && (x > lim || mp.find(x) != mp.end()))
			x /= 2;
		if (x == 0){
			return 0;
		}
		b[i] = x;
		mp.insert(x);
	}
	return 1;
}

void solve(){
	sort(a + 1, a + n + 1);
	ll high = a[n], low = n - 1, mid;
	while(low + 1 < high){
		mid = (high + low ) / 2;
		if (check(mid)){
			high = mid;
		}
		else{
			low = mid;
		}
	} 
	check(high);
	for(int i = 1; i <= n; i++)
		printf("%d%c", b[i], " \n"[i == n]);
}

void printans(){

}
	

int main(){
	int T = 1;
//	cin>>T;
	while(T--){
		read();
		solve();
		printans();
	}
	return 0;
}
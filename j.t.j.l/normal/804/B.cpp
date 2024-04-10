#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){

}

char s[MAXN];

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	ll ans = 0, now = 0;
	for(int i = n; i >= 1; i--){
		if (s[i] == 'b')
			now++;
		else{
			ans = (ans + now) % MM;
			now = now * 2 % MM;
		}
	}
	printf("%lld\n", ans);
}

void printans(){

}


int main(){
//	std::ios::sync_with_stdio(false);
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n;
char s[MAXN];
int h, m;

void read(){
	scanf("%d", &n);
	scanf("%d:%d", &h, &m);
}

int l, r;

int calc(int p, int q){
	return (p / 10 != q / 10) + (p % 10 != q % 10);
}

void solve(){
	
	if (n == 24){
		l = 0, r = 23;
	}
	else{
		l = 1, r = 12;
	}
	
	int _h, mh = 1000000;
	int _m, mm = 1000000;
	for(int i = l; i <= r; i++){
		if (calc(h, i) < mh)
			mh = calc(h, i), _h = i;
	}
	for(int i = 0; i <= 59; i++){
		if (calc(m, i) < mm)
			mm = calc(m, i), _m = i;
	}
	printf("%02d:%02d\n", _h, _m);
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
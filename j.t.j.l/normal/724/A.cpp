#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;
string s, t;

int work(string s){
	if (s[0] == 'm') return 1;
	if (s[0] == 'w') return 3;
	if (s[0] == 'f') return 5;
	if (s[2] == 'e') return 2;
	if (s[2] == 'u') return 4;
	if (s[2] == 't') return 6;
	if (s[2] == 'n') return 7;
}

int f[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void read(){
	cin>>s>>t;
	int n = work(s), m = work(t);
	for(int i = 0; i < 11; i++){
		if ((m-n+7)%7 == f[i]%7){
			puts("YES");return;
		}
	}
	puts("NO");return;
}

void solve(){

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
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;
int x;
char s[1000];

void read(){

}

int solve(){
	cin>>n;
	int now = 20000;
	for(int i = 1; i <= n; i++){
		scanf("%d%s", &x, s);
		if (s[0] == 'E' || s[0] == 'W'){
			if(now == 0 || now == 20000)
				return 0;
		}
		else if (s[0] == 'S'){
			now -= x;
			if (now < 0) return 0;
		} else if (s[0] == 'N'){
			now += x;
			if (now > 20000) return 0;
		}
	}
	return now == 20000;
}

void printans(){

}


int main(){
	int T = 1;
//	cin>>T;
	while(T--){
		read();
		if (solve())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
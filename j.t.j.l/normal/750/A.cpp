#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void read(){
	
}

void solve(){
	cin>>n>>m;
	m = 240 - m;
	int p = 0, now = 0;
	for(int i = 1; i <= n; i++){
		if (now + 5 * i <= m){
			p = i;
			now += 5 * i;
		}
	} 
	cout<<p<<endl;
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
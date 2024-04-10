#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

int a[MAXN];

string s;

void read(){
	cin>>n;
	for(int i = 1; i <= n; i++)
		cin>>a[i];
}

void solve(){
	getline(cin, s);
	int flag = 1;
	for(int i = 1; i <= n; i++){
		getline(cin, s);
		int l = s.length();
		for(int j = 0; j < l; j++)
			if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'y')
				a[i]--;
		if (a[i] != 0)
			flag = 0;
	}
	puts(flag ? "YES" : "NO");
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
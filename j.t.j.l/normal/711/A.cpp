#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e3 + 10;
const int MAXM = 2e6 + 10;

int n, m;
string s[MAXN];
int a[MAXM];
int f[MAXN][MAXN];
int flag;

void read(){
	cin>>n;
	 flag = 0;
	for(int i = 1; i <= n; i++){
		cin>>s[i];
		if (!flag && s[i][0] == 'O' && s[i][1] == 'O')
			s[i][0] = s[i][1] = '+', flag = 1;
		
		if (!flag && s[i][3] == 'O' && s[i][4] == 'O')
			s[i][3] = s[i][4] = '+', flag = 1;
		
	}
}

void solve(){
	if (flag){
		puts("YES");
		for(int i = 1; i <= n; i++)
			cout<<s[i]<<endl;
	}
	else
		puts("NO");
}

void printans(){

}
	

int main(){
	int T = 1;
//	cin >> T;
	while(T--){
		read();
		solve();
		printans();
	}
	return 0;
}
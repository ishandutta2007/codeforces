#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;
char s[MAXN];

void read(){
	scanf("%s", s); 
}

void solve(){
	n = strlen(s);
	int k = n - 1;
	for(int i = 0; i < n; i++)
		if (s[i] != 'a'){
			k = i;
			break;	
		}
	if (s[k] == 'a') s[k] = 'z';
	else s[k]--;
	for(int i = k + 1; i < n; i++)
		if (s[i] == 'a')
			break;
		else
			s[i]--;
	printf("%s\n", s);
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
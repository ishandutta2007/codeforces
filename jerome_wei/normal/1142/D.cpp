#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n;
char s[N];
int t[12][12];
typedef long long ll;
ll f[N][12];
ll ans = 0;
int main()
{
	scanf("%s",s+1);
	n = strlen(s+1);
	for(int i=0;i<=10;i++){
		int pre = i-1;pre = pre < 0 ? pre+11:pre;
		for(int digit=0;digit<i;digit++){
			// if(i==4) cout << pre*(pre+1)/2 << endl;
			t[i][digit] = 9 + pre*(pre+1)/2 + digit + 1;
			t[i][digit] %= 11;
		}
	}
	// cout << t[4][0] << endl;
	// puts("-------");
	for(int i=1;i<=n;i++){
		int c = s[i]-'0';
		for(int j=c+1;j<=10;j++){
			f[i][t[j][c]] += f[i-1][j];
		}
		if(c!=0)f[i][c]++;
		for(int j=0;j<=10;j++){
			ans+=f[i][j];
		}
		// cout << ans <<endl;
	}
	cout << ans << endl;
	
}
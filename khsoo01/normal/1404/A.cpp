#include<bits/stdc++.h>
using namespace std;

const int N = 300005;

int n, k;
bool chk[N][2];
char a[N];

void solve () {
	scanf("%d%d%s",&n,&k,a);
	for(int i=0;i<k;i++) {
		chk[i][0] = chk[i][1] = false;
	}
	for(int i=0;i<n;i++) {
		if(a[i] == '?') continue;
		chk[i%k][a[i]-'0'] = true;
	}
	int C[2] = {0, 0};
	bool F = false;
	for(int i=0;i<k;i++) {
		if(chk[i][0] && chk[i][1]) {
			F = true;
			break;
		}
		else if(chk[i][0]) C[0]++;
		else if(chk[i][1]) C[1]++;
	}
	if(!F && C[0] <= k/2 && C[1] <= k/2) {
		puts("YES");
	}
	else {
		puts("NO");
	}
}

int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--) solve();
}
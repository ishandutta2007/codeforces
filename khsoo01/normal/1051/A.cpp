#include<bits/stdc++.h>
using namespace std;

char a[105];
bool chk[4];

int stat (char C) {
	if('0' <= C && C <= '9') return 1;
	if('a' <= C && C <= 'z') return 2;
	return 3;
}

char get (int C) {
	if(C == 1) return '1';
	if(C == 2) return 'a';
	return 'A';
}

void solve () {
	int n;
	scanf("%s",a+1);
	n = strlen(a+1);
	chk[1] = chk[2] = chk[3] = false;
	for(int i=1;i<=n;i++) {
		chk[stat(a[i])] = true;
	}
	if(chk[1] && chk[2] && chk[3]) {
		printf("%s\n",a+1);
		return;
	}
	if(stat(a[1]) != stat(a[2])) {
		a[3] = get(6-stat(a[1])-stat(a[2]));
	}
	else if(stat(a[2]) != stat(a[3])) {
		a[1] = get(6-stat(a[2])-stat(a[3]));
	}
	else {
		int T = 1;
		for(int i=1;i<=3;i++) {
			if(!chk[i]) a[T++] = get(i);
		}
	}
	printf("%s\n",a+1);
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--) {
		solve();
	}
}
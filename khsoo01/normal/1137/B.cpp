#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int N = 500005;

int n, m, ff[N], c[2], ini[2], con[2];

char a[N], b[N];

void do_all () {
	for(int i=0;i<c[0];i++) putchar('0');
	for(int i=0;i<c[1];i++) putchar('1');
}

int main()
{
	scanf("%s%s",a+1,b+1);
	n = strlen(a+1);
	m = strlen(b+1);
	for(int i=1;i<=n;i++) {
		c[a[i]-'0']++;
	}
	for(int i=2,j=0;i<=m;i++) {
		while(j && b[j+1] != b[i]) j = ff[j];
		if(b[j+1] == b[i]) j++;
		ff[i] = j;
	}
	for(int i=1;i<=m;i++) {
		ini[b[i]-'0']++;
	}
	for(int i=ff[m]+1;i<=m;i++) {
		con[b[i]-'0']++;
	}
	if(ini[0] > c[0] || ini[1] > c[1]) {
		do_all();
		return 0;
	}
	for(int i=1;i<=m;i++) {
		putchar(b[i]);
	}
	c[0] -= ini[0];
	c[1] -= ini[1];
	while(true) {
		if(con[0] > c[0] || con[1] > c[1]) {
			do_all();
			return 0;
		}
		for(int i=ff[m]+1;i<=m;i++) {
			putchar(b[i]);
		}
		c[0] -= con[0];
		c[1] -= con[1];
	}
}
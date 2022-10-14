#include<iostream>

using namespace std;

typedef long long llint;

const llint INF = 1000000000000000005;
const int MAXN = 100005;

llint q, alen, blen;
llint l[MAXN];
string f0="What are you doing at the end of the world? Are you busy? Will you save us?";
string a="What are you doing while sending ";
string b="? Are you busy? Will you send ";
string c="?";

void precompute () {
	a+=(char) 34;
	b=((char) 34)+b+((char) 34);
	c=((char) 34)+c;
	alen=a.size(); blen=b.size();
	l[0]=f0.size();
	for (int i=1; i<MAXN; i++) {
		if (l[i-1]>INF) {
			l[i]=l[i-1];
			continue;
		}
		l[i]=l[i-1]*2+alen+blen+2;
	}
}

char solve (int n, llint k) {
	if (n==0) if (k>l[0]) return '.'; else return f0[k-1];
	if (k<=alen) {
		return a[k-1];
	} else if (k<=alen+l[n-1]) {
		return solve(n-1, k-alen);
	} else if (k<=alen+l[n-1]+blen) {
		return b[k-alen-l[n-1]-1];
	} else if (k<=alen+l[n-1]+blen+l[n-1]) {
		return solve(n-1, k-alen-l[n-1]-blen);
	} else if (k<=l[n]) {
		return c[k-alen-l[n-1]-blen-l[n-1]-1];
	} else {
		return '.';
	}
}

int main () {
	precompute();
	cin >> q;
	for (int i=0; i<q; i++) {
		llint n, k;
		cin >> n >> k;
		cout << solve(n, k);
	}
	return 0;
}
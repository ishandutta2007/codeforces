#include<iostream>

using namespace std;

typedef long long llint;

const int MAXN = 105;

int k, x, n, m, naso;
llint a, b, lima, limb, d1, d2, sola, solb;
char poc1, kraj1, poc2, kraj2;
llint fib[MAXN], dp[MAXN];
char s1[MAXN], s2[MAXN];

bool f () {
	dp[1]=dp[2]=0;
	dp[3]=0;
	if (kraj1=='A' && poc2=='C') dp[3]++;
	for (int i=4; i<MAXN; i++) {
		dp[i]=dp[i-1]+dp[i-2];
		if (i&1) {
			if (kraj2=='A' && poc2=='C') dp[i]++;
		} else {
			if (kraj2=='A' && poc1=='C') dp[i]++;
		}
	}
	if (n==1) {
		lima=0; d1=0;
	} else if (n==2) {
		if (poc1=='A' && kraj1=='C') lima=d1=1; else lima=d1=0;
	} else if (n==3) {
		if (poc1=='A' || kraj1=='C') lima=1; else lima=0; d1=0;
	} else {
		lima=(poc1=='A')+(kraj1=='C')+(n-(poc1=='A')-1-(kraj1=='C')-1)/2; d1=0;
	}
	if (m==1) {
		limb=0; d2=0;
	} else if (m==2) {
		if (poc2=='A' && kraj2=='C') limb=d2=1; else limb=d2=0;
	} else if (m==3) {
		if (poc2=='A' || kraj2=='C') limb=1; else limb=0; d2=0;
	} else {
		limb=(poc2=='A')+(kraj2=='C')+(m-(poc2=='A')-1-(kraj2=='C')-1)/2; d2=0;
	}
	for (llint i=d1; i<=lima; i++) {
		for (llint j=d2; j<=limb; j++) {
			if (i*a+j*b+dp[k]==x) {
				sola=i; solb=j;
				return 1;
			}
		}
	}
	return 0;
}

void construct () {
	for (int i=0; i<n; i++) {
		s1[i]='D';
	}
	for (int i=0; i<m; i++) {
		s2[i]='D';
	}
	s1[0]=poc1; s1[n-1]=kraj1;
	s2[0]=poc2; s2[m-1]=kraj2;
	for (int i=0; i<n-1; i++) {
		if (s1[i]=='A' || s1[i+1]=='C' || (s1[i]!='A' && s1[i]!='C')) {
			if (sola==0) continue;
			sola--;
			s1[i]='A'; s1[i+1]='C';
		}
	}
	for (int i=0; i<m-1; i++) {
		if (s2[i]=='A' || s2[i+1]=='C' || (s2[i]!='A' && s2[i]!='C')) {
			if (solb==0) continue;
			solb--;
			s2[i]='A'; s2[i+1]='C';
		}
	}
	for (int i=0; i<n; i++) {
		cout << s1[i];
	}
	cout << endl;
	for (int i=0; i<m; i++) {
		cout << s2[i];
	}
}

void svi (int pos) {
	if (naso) return;
	if (pos==4) {
		if (n==1 && poc1!=kraj1) return;
		if (m==1 && poc2!=kraj2) return;
		if (f()) {
			naso=1;
			construct();
		}
	} else if (pos==0) {
		poc1='A'; svi(pos+1);
		poc1='C'; svi(pos+1);
		poc1='D'; svi(pos+1);
	} else if (pos==1) {
		poc2='A'; svi(pos+1);
		poc2='C'; svi(pos+1);
		poc2='D'; svi(pos+1);
	} else if (pos==2) {
		kraj1='A'; svi(pos+1);
		kraj1='C'; svi(pos+1);
		kraj1='D'; svi(pos+1);
	} else if (pos==3) {
		kraj2='A'; svi(pos+1);
		kraj2='C'; svi(pos+1);
		kraj2='D'; svi(pos+1);
	}
}

int main () {
	cin >> k >> x >> n >> m;
	fib[1]=fib[2]=1;
	for (int i=3; i<MAXN; i++) {
		fib[i]=fib[i-1]+fib[i-2];
	}
	a=fib[k-2], b=fib[k-1];
	svi(0);
	if (!naso) cout << "Happy new year!";
	return 0;
}
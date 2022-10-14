#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

typedef long long int llint;

llint t, n, k;
llint mod=1000000007;
llint sum[1005] [1005];
llint s[1005];
llint maxk=1003, maxn=1003;
llint l[1005] [1005];
llint p[1005] [1005];
llint fak[1005];
llint bio[1005] [1005];

llint modadd (llint a, llint b) {
	if (a+b>=mod) return a+b-mod;
	return a+b;
}

llint modmul (llint a, llint b) {
	return a*b%mod;
}

int main () {
	memset(bio, -1, sizeof bio);
	p[1] [0]=1;
	fak[0]=1;
	for (int i=1; i<=maxn; i++) {
		l[1] [i]=1;
		p[1] [i]=i+1;
		fak[i]=modmul(fak[i-1], i);
		sum[1] [i]=sum[1] [i-1]+1;
	}
	for (int i=2; i<=maxk; i++) {
		for (int j=1; j<=maxn; j++) {
			l[i] [j]=sum[i-1] [j-1];
			sum[i] [j]=modadd(sum[i] [j-1], l[i] [j]);
		}
	}
	for (int i=2; i<=maxk; i++) {
		memset(s, 0, sizeof s);
		for (int j=i-1; j<=maxn; j++) {
			s[(j-i+1)%i]=modadd(s[(j-i+1)%i], p[i-1] [j-i+1]);
			p[i] [j]=s[(j-i+1)%i];
		}
	}
	cin >> t;
	for (int i=0; i<t; i++) {
		scanf("%d%d", &n, &k);
		if (bio[n] [k]!=-1) {
			printf("%d\n", bio[n] [k]);
			continue;
		}
		llint res=0;
		for (int j=0; j<=n; j++) {
			if (p[k] [n-j]==0) break;
			if (l[k] [j]==0) continue;
			res=modadd(res, modmul(l[k] [j], modmul(p[k] [n-j], fak[k])));
		}
		res%=mod;
		bio[n] [k]=res;
		printf("%d\n", bio[n] [k]);
	}
	return 0;
}
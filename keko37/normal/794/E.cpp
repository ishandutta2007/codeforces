#include<iostream>
#include<cstdio>

using namespace std;

const int MAXN = 300005;
const int INF = 1000000007;

int n;
int l[MAXN], sol[MAXN], nep[MAXN], par[MAXN];

int abs (int x) {
	return x>0?x:-x;
}

int main () {
	cin >> n;
	for (int i=1; i<=n; i++) {
		sol[i]=-INF;
		nep[i]=par[i]=n;
	}
	for (int i=1; i<=n; i++) {
		scanf("%d", &l[i]);
	}
	for (int i=1; i<=n; i++) {
		if (l[i-1]>=l[i] || l[i]<=l[i+1]) {
			nep[i]=abs(n-i-(i-1));
		} else {
			nep[i]=n-1;
			if (l[i-1]>=l[i+1]) {
				nep[i-1]=min(nep[i-1], abs(n-i-1-(i-1-1)) );
				sol[nep[i-1]]=max(sol[nep[i-1]], l[i-1]);
			} else {
				nep[i+1]=min(nep[i+1], abs(n-i+1-(i+1-1)) );
				sol[nep[i+1]]=max(sol[nep[i+1]], l[i+1]);
			}
		}
		if (i>1 && l[i-1]<=l[i]) {
			par[i]=min(par[i], abs(n-i-(i-2)) );
		}
		if (i<n && l[i]>=l[i+1]) {
			par[i]=min(par[i], abs(n-i-1-(i-1)) );
		}
		sol[nep[i]]=max(sol[nep[i]], l[i]);
		sol[par[i]]=max(sol[par[i]], l[i]);
	}
	for (int i=0; i<n; i++) {
		if (i-2>=0) sol[i]=max(sol[i], sol[i-2]);
		printf("%d ", sol[i]);
	}
	return 0;
}
#include<iostream>
#include<cstdio>

using namespace std;

const int MAXN = 1000005;
const int MOD = 1000000007;

int n;
int l[MAXN], p[100];
int curr[MAXN], add[MAXN];
int prime[25]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

int f (int x) {
	int res=0;
	for (int i=0; prime[i]>0; i++) {
		int cnt=0;
		while (x%prime[i]==0) {
			x/=prime[i];
			cnt++;
		}
		cnt%=2;
		res|=cnt<<i;
	}
	return res;
}

int madd (int a, int b) {
	if (a+b>=MOD) return a+b-MOD; return a+b;
}

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		scanf("%d", &l[i]);
		p[l[i]]++;
	}
	curr[0]=1;
	for (int i=1; i<=70; i++) {
		if (!p[i]) continue;
		int mask=f(i), pot=1;
		for (int j=0; j<p[i]-1; j++) {
			pot=madd(pot, pot);
		}
		for (int j=0; j<MAXN-1; j++) {
			int novi=j^mask;
			if (novi>=MAXN-1) continue;
			add[novi]=madd(add[novi], ((long long) curr[j])*pot%MOD);
			add[j]=madd(add[j], ((long long) curr[j])*(pot-1)%MOD);
		}
		for (int j=0; j<MAXN-1; j++) {
			curr[j]=madd(curr[j], add[j]);
			add[j]=0;
		}
	}
	cout << (curr[0]-1+MOD)%MOD;
	return 0;
}
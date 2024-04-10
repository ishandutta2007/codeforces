#include<iostream>
#include<cstdio>

using namespace std;

typedef long long llint;

const int MAXN = 100005;

llint n, d, sol, ofs, curr;
int l[MAXN];
llint sum[MAXN], maxi[MAXN];

int main () {
	cin >> n >> d;
	for (int i=0; i<n; i++) {
		scanf("%d", &l[i]);
		if (i==0) sum[i]=l[i]; else sum[i]=sum[i-1]+l[i];
	}
	maxi[n]=-100000000000000007LL;
	for (int i=n-1; i>=0; i--) {
		maxi[i]=max(maxi[i+1], sum[i]);
	}
	for (int i=0; i<n; i++) {
		llint naj=maxi[i]+ofs;
		if (naj>d) {
			cout << -1;
			return 0;
		}
		if (l[i]!=0) {
			curr+=l[i];
		} else if (curr<0) {
			sol++;
			ofs+=d-naj;
			curr+=d-naj;
			if (curr<0) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << sol;
	return 0;
}
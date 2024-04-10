#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

typedef unsigned int uint;

const int MAXQ = 600005;

int n, m, q, lim=18;
int x1[MAXQ], y1[MAXQ], x2[MAXQ], y2[MAXQ];
char l[505] [505];
int ind[505];
int tab[505];
uint dp[505] [505] [20];
uint midd[505] [20];
uint midu[505] [20];
uint sol[MAXQ];

vector <int> v[MAXQ];

void dvc (int a, int b, int cvor) {
	if (a>b) return;
	int mid=(a+b)/2;
	for (int i=n-1; i>=0; i--) {
		for (int j=0; j<lim; j++) {
			midd[i] [j]=0;
			if (i!=n-1 && l[i+1] [mid]=='.') midd[i] [j] |= midd[i+1] [j];
		}
		if (l[i] [mid]=='.') midd[i] [ind[i]] |= (((uint) 1)<<tab[i]);
	}
	for (int i=mid-1; i>=a; i--) {
		for (int j=n-1; j>=0; j--) {
			for (int k=0; k<lim; k++) {
				dp[j] [i] [k]=0;
			}
			if (j!=n-1 && l[j+1] [i]=='.') {
				for (int k=0; k<lim; k++) {
					dp[j] [i] [k] |= dp[j+1] [i] [k];
				}
			}
			if (i==mid-1 && l[j] [i+1]=='.') {
				for (int k=0; k<lim; k++) {
					dp[j] [i] [k] |= midd[j] [k];
				}
			} else if (l[j] [i+1]=='.') {
				for (int k=0; k<lim; k++) {
					dp[j] [i] [k] |= dp[j] [i+1] [k];
				}
			}
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<lim; j++) {
			midu[i] [j]=0;
			if (i!=0 && l[i-1] [mid]=='.') midu[i] [j] |= midu[i-1] [j];
		}
		if (l[i] [mid]=='.') midu[i] [ind[i]] |= (((uint) 1)<<tab[i]);
	}
	for (int i=mid+1; i<=b; i++) {
		for (int j=0; j<n; j++) {
			for (int k=0; k<lim; k++) {
				dp[j] [i] [k]=0;
			}
			if (j!=0 && l[j-1] [i]=='.') {
				for (int k=0; k<lim; k++) {
					dp[j] [i] [k] |= dp[j-1] [i] [k];
				}
			}
			if (i==mid+1 && l[j] [i-1]=='.') {
				for (int k=0; k<lim; k++) {
					dp[j] [i] [k] |= midu[j] [k];
				}
			} else if (l[j] [i-1]=='.') {
				for (int k=0; k<lim; k++) {
					dp[j] [i] [k] |= dp[j] [i-1] [k];
				}
			}
		}
	}
	for (int i=0; i<v[cvor].size(); i++) {
		int pos=v[cvor] [i];
		if (y2[pos]<mid) v[cvor*2].push_back(pos);
		if (y1[pos]>mid) v[cvor*2+1].push_back(pos);
		if (y1[pos]<=mid && mid<=y2[pos]) {
			if (y1[pos]<mid && mid<y2[pos]) {
				uint res=0;
				for (int j=0; j<lim; j++) {
					res |= dp[x1[pos]] [y1[pos]] [j] & dp[x2[pos]] [y2[pos]] [j];
				}
				sol[pos]=res;
			} else if (y1[pos]<mid && mid==y2[pos]) {
				uint res=0;
				for (int j=0; j<lim; j++) {
					res |= dp[x1[pos]] [y1[pos]] [j] & midu[x2[pos]] [j];
				}
				sol[pos]=res;
			} else if (y1[pos]==mid && mid<y2[pos]) {
				uint res=0;
				for (int j=0; j<lim; j++) {
					res |= midd[x1[pos]] [j] & dp[x2[pos]] [y2[pos]] [j];
				}
				sol[pos]=res;
			} else {
				uint res=0;
				for (int j=0; j<lim; j++) {
					res |= midd[x1[pos]] [j] & midu[x2[pos]] [j];
				}
				sol[pos]=res;
			}
		}
	}
	dvc(a, mid-1, cvor*2);
	dvc(mid+1, b, cvor*2+1);
}

int main () {
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; i++) {
		ind[i]=i/32;
		tab[i]=i%32;
		for (int j=0; j<m; j++) {
			cin >> l[i] [j];
		}
	}
	cin >> q;
	for (int i=0; i<q; i++) {
		scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
		x1[i]--; y1[i]--; x2[i]--; y2[i]--;
		if (x1[i]<=x2[i] && y1[i]<=y2[i]) v[1].push_back(i);
	}
	dvc(0, m-1, 1);
	for (int i=0; i<q; i++) {
		if(sol[i]) printf("Yes\n"); else printf("No\n");
	}
	return 0;
}
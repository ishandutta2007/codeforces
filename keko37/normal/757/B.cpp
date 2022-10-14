#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

const int MAXN = 100005;
int n, x, sol=1;
int p[MAXN];
int l[MAXN];
vector <int> fak;

int main () {
	for (int i=2; i*i<MAXN; i++) {
		if (p[i]==0) {
			for (int j=i*i; j<MAXN; j+=i) {
				if (p[j]==0) p[j]=i;
			}
		}
	}
	cin >> n;
	for (int i=0; i<n; i++) {
		scanf("%d", &x);
		fak.clear();
		while (p[x]>0) {
			fak.push_back(p[x]);
			x/=p[x];
		}
		fak.push_back(x);
		for (int j=0; j<fak.size(); j++) {
			if (j==0 || fak[j-1]!=fak[j]) l[fak[j]]++;
		}
	}
	for (int i=2; i<MAXN; i++) {
		sol=max(sol, l[i]);
	}
	cout << sol;
	return 0;
}
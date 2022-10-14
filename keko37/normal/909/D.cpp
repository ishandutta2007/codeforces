#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 1000005;

int n, br, poc=1, izb, sol;
string t;
int nxt[MAXN], prv[MAXN], len[MAXN];
char znk[MAXN];
vector <int> v;

void brisi (int ind) {
	izb++;
	nxt[prv[ind]]=nxt[ind];
	prv[nxt[ind]]=prv[ind];
}

void idi () {
	v.clear();
	for (int i=poc; i!=br+1; i=nxt[i]) {
		if (i==poc || nxt[i]==br+1) len[i]-=1; else len[i]-=2;
		if (len[i]<=0) v.push_back(i);
	}
	for (int i=0; i<v.size(); i++) {
		if (v[i]==poc) poc=nxt[poc];
		brisi(v[i]);
	}
	for (int i=poc; i!=br+1; i=nxt[i]) {
		if (i==poc) continue;
		int prosli=prv[i];
		if (znk[prosli]==znk[i]) {
			if (prosli==poc) poc=i;
			brisi(prosli);
			len[i]+=len[prosli];
		}
	}
}

int main () {
	cin >> t;
	n=t.size();
	int cnt=1;
	for (int i=0; i<n; i++) {
		if (i==n-1 || t[i]!=t[i+1]) {
			br++;
			len[br]=cnt;
			znk[br]=t[i];
			cnt=1;
		} else {
			cnt++;
		}
	}
	for (int i=1; i<=br; i++) {
		prv[i]=i-1;
		nxt[i]=i+1;
	}
	int org=br;
	while (org-izb>1) {
		idi();
		sol++;
	}
	cout << sol;
	return 0;
}
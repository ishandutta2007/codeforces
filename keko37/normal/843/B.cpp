#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long llint;

const int MAXN = 50005;
const int LIM = 250;

int n, s, x, val[MAXN], nxt[MAXN];
int bio[MAXN];
llint m=1000000007, num=65464, k=1682525, r=7243;
vector < pair <int, int> > v;

void gen () {
	num=(k*num+r)%m;
}

void idi (int ind) {
	while (1) {
		if (ind==-1) {
			cout << "! " << -1;
			fflush(stdout);
			return;
		}
		if (!bio[ind]) {
			bio[ind]=1;
			printf("? %d\n", ind);
			fflush(stdout);
			scanf("%d%d", &val[ind], &nxt[ind]);
		}
		if (val[ind]>=x) {
			cout << "! " << val[ind];
			fflush(stdout);
			return;
		}
		ind=nxt[ind];
	}
}

int main () {
	cin >> n >> s >> x;
	
	printf("? %d\n", s);
	fflush(stdout);
	scanf("%d%d", &val[s], &nxt[s]);
	v.push_back(make_pair(val[s], s));
	bio[s]=1;
	
	if (val[s]>=x) {
		cout << "! " << val[s];
		fflush(stdout);
		return 0;
	}
	
	for (int i=0; i<LIM; i++) {
		gen();
		int ran=num%n+1;
		if (!bio[ran]) {
			bio[ran]=1;
			printf("? %d\n", ran);
			fflush(stdout);
			scanf("%d%d", &val[ran], &nxt[ran]);
			v.push_back(make_pair(val[ran], ran));
		}
	}
	sort(v.begin(), v.end());
	int pos=upper_bound(v.begin(), v.end(), make_pair(x, -100))-v.begin()-1;
	idi(v[pos].second);
	return 0;
}
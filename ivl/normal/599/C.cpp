#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back

using namespace std;

int n;
int h[100005]; // 1 indexirano

int pref[100005];
int suff[100005];

int main(){
	REP(i,100005) h[i] = 1000000005;
	
	cin >> n;
	FOR(i,1,n+1) scanf("%d", h+i);
	h[0] = -1;
	
	pref[0] = h[0];
	FOR(i,1,n+1) pref[i] = max(pref[i-1], h[i]);
	
	suff[100004] = h[100004];
	for (int i = 100003; i >= 0; --i)
		suff[i] = min(suff[i+1], h[i]);
	
	int R = 0;
	FOR(i,1,n+1) if (pref[i-1] <= suff[i]) ++R;
	cout << R << endl;
	
	return 0;
}
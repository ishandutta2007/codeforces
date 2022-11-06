#include<bits/stdc++.h>
#define REP(i, a, b) for(int i(a); i <= (b); ++i)

#define gc getchar()
struct Reader{
	template <class T> inline operator T() {
		T w; char c, p = 0;
		for(; !isdigit(c = gc); c == '-' && (p = 1));
		for(w = c & 15; isdigit(c = gc); w = w * 10 + (c & 15));
		return p ? -w : w;
	}
}rd;

template <class T> inline bool smin(T&x, const T&y){return y < x ? x = y, 1 : 0;}
template <class T> inline bool smax(T&x, const T&y){return x < y ? x = y, 1 : 0;}

typedef long long ll;

const int N(1e5 + 5);

int n, m, a[26], b[26], lc, rc;
char s[N];
void calc(){
	scanf("%s", s + 1), m = strlen(s + 1);
	memset(b, 0, sizeof b);
	int nw = 1;
	while(nw < m && s[nw] == s[nw + 1])++nw;
	lc = b[s[1] - 'a'] = nw;
	REP(i, nw + 1, m){
		if(s[i] != s[i - 1])smax(b[s[i] - 'a'], nw = 1);
		else smax(b[s[i] - 'a'], ++nw);
	}
	rc = nw;
}
int main(){
	scanf("%d", &n); calc();
	memcpy(a, b, sizeof a);
//	printf("%d %d\n", lc, rc);
//	printf("%d %d %d\n", a[0], a[1], a['n' - 'a']);
	while(--n){
		calc();
	//	printf("%d %d\n", lc, rc);
		if(lc == m){
			REP(i, 0, 25)
				if(s[1] - 'a' != i)a[i] = a[i] > 0;
				else a[i] = (a[i] + 1) * lc + a[i];
		}
		else if(s[1] == s[m]){
			REP(i, 0, 25)
				if(s[1] - 'a' != i)a[i] = a[i] > 0;
				else if(a[i])a[i] = lc + rc + 1;
		}
		else{
			REP(i, 0, 25)
				if(s[1] - 'a' == i)a[i] = (a[i] > 0) + lc;
				else if(s[m] - 'a' == i)a[i] = (a[i] > 0) + rc;
				else a[i] = a[i] > 0;
		}
		REP(i, 0, 25)smax(a[i], b[i]);
//		printf("%d %d %d\n", a[0], a[1], a['n' - 'a']);
	}
	int ans = 0;
	REP(i, 0, 25)smax(ans, a[i]);
	std::cout << ans;
	return 0;
}
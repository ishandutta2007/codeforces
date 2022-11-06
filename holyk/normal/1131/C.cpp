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

int n, a[105], b[105], c[105];
int main(){
	n = rd;
	REP(i, 1, n)a[i] = rd;
	static std::map<int, int> p;
	REP(i, 1, n)++p[a[i]];
	int l = 1, r = 1;
	for(auto t : p){
		while(t.second--){
			if(l <= r)a[l++] = t.first;
			else a[n - r++ + 1] = t.first;
		}
	}
	REP(i, 1, n)printf("%d ", a[i]);
	return 0;
}
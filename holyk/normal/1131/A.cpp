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
int a, b, c, d;
int main(){
	std::cin >> a >> b >> c >> d;
	std::cout << 
	1ll * (a + 2) * (b + 1) - 1ll * a * b + 
	1ll * (c + 2) * (d + 1) - 1ll * c * d + a - c;
	return 0;
}
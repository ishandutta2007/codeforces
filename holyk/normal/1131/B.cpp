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

const int N(1e4 + 5);
int main(){
	int n = rd, a = rd, b = rd;
	int ans = std::min(a, b) + 1;
	while(--n){
		int x = rd, y = rd;
		if(a < b){
			if(b <= x)a = b, ++ans;
		}
		else if(a > b){
			if(a <= y)b = a, ++ans;
		}
		if(a == b){
			ans += std::min(x, y) - a;
		}
		a = x, b = y;
	}
	std::cout << ans;
	return 0;
}
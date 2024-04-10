#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;

inline ll read(){
	ll a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c)){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int MAXN = 200010;
int N , L , rangeL , rangeR , ans[10 * MAXN][2];
struct point{
	ll t , x , y;
	bool operator <(const point a)const{
		return t % L < a.t % L || t % L == a.t % L && t < a.t;
	}
}now[MAXN];

inline ll abss(ll a){
	return a < 0 ? -a : a;
}

inline ll fl(ll x , ll y){
	return x >= 0 ? x / y : (x / y - (x % y ? 1 : 0));
}

inline ll cl(ll x , ll y){
	return x >= 0 ? (x + y - 1) / y : x / y;
}

signed main(){
	N = read();
	L = read();
	for(int i = 1 ; i <= N ; ++i){
		now[i].t = read();
		now[i].x = read();
		now[i].y = read();
		if(((now[i].x + now[i].y) & 1) != (now[i].t & 1)){
			puts("NO");
			return 0;
		}
		ll a = (now[i].x + now[i].y + now[i].t) / 2 , b = (now[i].x - now[i].y + now[i].t) / 2;
		now[i].x = a;
		now[i].y = b;
	}
	sort(now , now + N + 1);
	rangeL = 0;
	rangeR = L;
	for(int i = 1 ; i <= N && rangeL <= rangeR ; ++i){
		int l = now[i - 1].t / L - now[i].t / L , a = now[i - 1].x - now[i].x , b = now[i].t % L - now[i - 1].t % L + a;
		if(l == 0){
			if(a > 0 || b < 0){
				puts("NO");
				return 0;
			}
			continue;
		}
		else
			if(l < 0){
				l = -l;
				swap(a , b);
				a = -a;
				b = -b;
			}
		rangeL = max(rangeL , cl(a , l));
		rangeR = min(rangeR , fl(b , l));
	}
	rangeL = max(rangeL , cl(now[N].x , 1 + now[N].t / L));
	rangeR = min(rangeR , fl(now[N].x + L - now[N].t % L , 1 + now[N].t / L));
	if(rangeL > rangeR){
		puts("NO");
		return 0;
	}
	ans[L][0] = rangeL;
	for(int i = 1 ; i <= N ; ++i){
		ans[now[i].t % L][0] = now[i].x - rangeL * (now[i].t / L);
		for(int j = now[i - 1].t % L + 1 ; j < now[i].t % L ; ++j)
			ans[j][0] = ans[j - 1][0] + (ans[j - 1][0] < ans[now[i].t % L][0]);
	}
	for(int i = now[N].t % L + 1 ; i < L ; ++i)
		ans[i][0] = ans[i - 1][0] + (ans[i - 1][0] < ans[L][0]);
	rangeL = 0;
	rangeR = L;
	for(int i = 1 ; i <= N && rangeL <= rangeR ; ++i){
		int l = now[i - 1].t / L - now[i].t / L , a = now[i - 1].y - now[i].y , b = now[i].t % L - now[i - 1].t % L + a;
		if(l == 0){
			if(a > 0 || b < 0){
				puts("NO");
				return 0;
			}
			continue;
		}
		else
			if(l < 0){
				l = -l;
				swap(a , b);
				a = -a;
				b = -b;
			}
		rangeL = max(rangeL , cl(a , l));
		rangeR = min(rangeR , fl(b , l));
	}
	rangeL = max(rangeL , cl(now[N].y , 1 + now[N].t / L));
	rangeR = min(rangeR , fl(now[N].y + L - now[N].t % L , 1 + now[N].t / L));
	if(rangeL > rangeR){
		puts("NO");
		return 0;
	}
	ans[L][1] = rangeL;
	for(int i = 1 ; i <= N ; ++i){
		ans[now[i].t % L][1] = now[i].y - rangeL * (now[i].t / L);
		for(int j = now[i - 1].t % L + 1 ; j < now[i].t % L ; ++j)
			ans[j][1] = ans[j - 1][1] + (ans[j - 1][1] < ans[now[i].t % L][1]);
	}
	for(int i = now[N].t % L + 1 ; i < L ; ++i)
		ans[i][1] = ans[i - 1][1] + (ans[i - 1][1] < ans[L][1]);
	for(int i = 1 ; i <= L ; ++i)
		if(ans[i][0] == ans[i - 1][0])
			putchar(ans[i][1] > ans[i - 1][1] ? 'D' : 'L');
		else
			putchar(ans[i][1] > ans[i - 1][1] ? 'R' : 'U');
	return 0;
}
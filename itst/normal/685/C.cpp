#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll read(){
	ll a = 0; bool f = 0; char c = getchar(); while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}
const int _ = 1e5 + 7; ll X[_] , Y[_] , Z[_] , N , T , mnx , mny;

ll calc(ll midz , bool f){
	ll mnx = -3e18 , mxx = 3e18 , mny = -3e18 , mxy = 3e18;
	for(int i = 1 ; i <= N ; ++i){
		ll t = -abs(Z[i] - midz);
		mnx = max(mnx , X[i] + Y[i] - t); mxx = min(mxx , X[i] + Y[i] + t);
		mny = max(mny , X[i] - Y[i] - t); mxy = min(mxy , X[i] - Y[i] + t);
	}
	
	ll t = max((mnx - mxx + 1) / 2 , (mny - mxy + 1) / 2); mnx -= t; mxx += t; mny -= t; mxy += t;
	if(mnx == mxx && mny == mxy && ((mxx + mxy) & 1)) t += f;
	if((mnx + mny) & 1) mnx != mxx ? ++mnx : ++mny;
	::mnx = (mnx + mny) / 2; ::mny = (mnx - mny) / 2; return t;
}

int main(){
	for(T = read() ; T ; --T){
		N = read(); for(int i = 1 ; i <= N ; ++i){X[i] = read(); Y[i] = read(); Z[i] = read();}
		ll L = -1e18 , R = 1e18; while(L < R){ll mid = (L + R) >> 1; calc(mid , 0) <= calc(mid + 1 , 0) ? R = mid : L = mid + 1;}
		if(calc(L , 1) > calc(L + 1 , 1)) ++L;
		calc(L , 1); printf("%lld %lld %lld\n" , mnx , mny , L);
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();}
	return a;
}

const int _ = 1e5 + 7;
#define ll long long
#define PII pair < int , int >
ll tmp[_]; int N , M , K , P , a[_] , h[_];
priority_queue < PII > q; int tms;

int calc(int x){
	ll val = tmp[x] - 1ll * (M - tms) * a[x];
	if(val < 0) return tms + 1e9;
	if(val / a[x] < tms) return tms - val / a[x];
	else return val >= 1ll * a[x] * tms + h[x] ? -1 : 0;
}

bool check(ll x){
	while(!q.empty()) q.pop();
	tms = M - 1;
	for(int i = 1 ; i <= N ; ++i){tmp[i] = x; q.push(PII(calc(i) , i));}
	while(tms >= 0){
		for(int j = 1 ; j <= K ; ++j){
			PII t = q.top(); q.pop();
			if(t.first > tms) return 0;
			tmp[t.second] += P; q.push(PII(calc(t.second) , t.second));
		}
		--tms;
	}
	return q.top().first < 0;
}

int main(){
	ios::sync_with_stdio(0);
	N = read(); M = read(); K = read(); P = read();
	for(int i = 1 ; i <= N ; ++i){
		h[i] = read(); a[i] = read();
	}
	ll L = 0 , R = 1e18;
	while(L < R){
		ll mid = (L + R) >> 1;
		check(mid) ? R = mid : L = mid + 1;
	}
	cout << L; return 0;
}
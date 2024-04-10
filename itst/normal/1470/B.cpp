#include<bits/stdc++.h>
using namespace std;

#define int long long
int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

int T , N , A[100003] , Q , W;
bool nprm[1000003]; int lst[1000003] , prm[1000003] , cprm;
void sieve(){
	for(int i = 2 ; i <= 1e6 ; ++i){
		if(!nprm[i]) lst[prm[++cprm] = i] = i;
		for(int j = 1 ; prm[j] * i <= 1e6 ; ++j){
			nprm[prm[j] * i] = 1; lst[prm[j] * i] = prm[j];
			if(i % prm[j] == 0) break;
		}
	}
}

signed main(){
	sieve();
	for(T = read() ; T ; --T){
		N = read(); map < int , int > cnt;
		for(int i = 1 ; i <= N ; ++i){
			int A = read() , tms = 1;
			while(A != 1){int t = lst[A]; A /= t; tms % t ? tms *= t : tms /= t;}
			++cnt[tms];
		}
		int mx1 = 0 , mx2 = 0 , sum = 0;
		for(auto t : cnt){mx1 = max(mx1 , t.second); if(t.first != 1 && (t.second & 1)) mx2 = max(mx2 , t.second); else sum += t.second;}
		mx2 = max(mx2 , sum); for(Q = read() ; Q ; --Q){int T = read(); printf("%lld\n" , T ? mx2 : mx1);}
	}
	return 0;
}
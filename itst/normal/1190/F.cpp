#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll N , M , P;

void BF(){
	static bool vis[10000007]; vis[1] = 1;
	for(int i = 2 ; i <= M ; ++i)
		if(M % i == 0){
			int tms = P; while(!vis[tms]){vis[tms] = 1; tms = 1ll * tms * P % M;}
			for(int j = 1 ; j <= M / i ; ++j) vis[i * j] = 1;
			vector < int > ans; for(int i = 1 ; ans.size() < N && i < M ; ++i) if(!vis[i]) ans.push_back(i);
			if(ans.size() < N) puts("-1"); else for(auto t : ans) printf("%d " , t);
			break;
		}
}

ll FM(ll A , ll B , ll P){ll C = A * B - (ll)((long double)A / P * B + 0.5) * P; return C < 0 ? C + P : C;}
ll PW(ll A , ll B , ll P){ll T = 1; while(B){if(B & 1) T = FM(T , A , P); A = FM(A , A , P); B >>= 1;} return T;}

mt19937_64 rnd(time(0));
const int prm[] = {2,3,5,7,11,13,19,29,31,37,61,24251,998244353,19260817} , SZ = 14;
bool MR(ll P){
	for(int i = 0 ; i < SZ ; ++i)
		if(P == prm[i]) return 1;
		else if(P % prm[i] == 0) return 0;
		else if(PW(prm[i] , P - 1 , P) != 1) return 0;
	ll tms = P - 1; while(!(tms & 1)) tms >>= 1;
	for(int i = 0 ; i < SZ ; ++i){
		ll val = PW(prm[i] , tms , P); if(val == 1) continue;
		while(val != P - 1 && val != 1) val = FM(val , val , P);
		if(val == 1) return 0;
	}
	return 1;
}

ll PR(ll P){
	ll x0 = 0 , c = rnd() % (P - 1) + 1 , x = 0;
	for(int i = 1 ; ; i <<= 1 , x0 = x){
		ll tms = 1;
		for(int j = 1 ; j <= i ; ++j){
			x = (FM(x , x , P) + c) % P; tms = FM(tms , abs(x - x0) , P);
			if(j % 128 == 0 && __gcd(tms , P) != 1) return __gcd(tms , P);
		}
		if(__gcd(tms , P) != 1) return __gcd(tms , P);
	}
	return P;
}

vector < ll > pot;
void find(ll P , int tms){
	if(P == 1) return;
	if(MR(P)) return (void)pot.insert(pot.end() , tms , P);
	ll t = PR(P); while(t == P) t = PR(P);
	int cnt = 0; while(P % t == 0){P /= t; ++cnt;}
	find(t , tms * cnt); find(P , tms);
}

ll search(int pos , ll val){
	if(pos == pot.size()) return PW(P , val , M) == 1 ? val : 1e18;
	int p = pos; while(p < pot.size() && pot[p] == pot[pos]) ++p;
	ll ans = 1e18; for(int i = 0 ; i <= p - pos ; ++i , val = val * pot[pos]) ans = min(ans , search(p , val));
	return ans;
}
//
int main(){
	cin >> N >> M >> P;
	if(M <= 1e7) BF();
	else{
		vector < ll > ans; find(M , 1); ll prm = pot[0];
		if(P % prm == 0){
			for(int i = 2 ; i <= M && ans.size() < N ; ++i)
				if(i % prm != 0) ans.push_back(i);
			if(ans.size() < N) puts("-1");
			else for(auto t : ans) printf("%lld " , t);
		}else{
			pot.clear(); ll phi = M / prm * (prm - 1); find(phi , 1);
			sort(pot.begin() , pot.end()); ll rt , order = search(0 , 1);
			if(order + M / prm + N > M){puts("-1"); return 0;}
			if(prm == 2)
				if(P % 4 == 3){
					P = FM(P , P , M); rt = 5;
					for(ll i = 1 , tms = rt ; ans.size() < N ; ++i , tms = FM(tms , rt , M))
						if(i % (phi / order)) ans.push_back(tms);
				}else for(int i = 3 ; ans.size() < N ; i += 4) ans.push_back(i);
			else{
				for(int i = 2 ; ; ++i){
					bool flg = 1;
					for(int j = 0 ; j < pot.size() && flg ; ++j)
						if(!j || pot[j] != pot[j - 1]) flg = PW(i , phi / pot[j] , M) != 1;
					if(flg){rt = i; break;}
				}
				for(ll i = 1 , tms = rt ; ans.size() < N ; ++i , tms = FM(tms , rt , M))
					if(i % (phi / order)) ans.push_back(tms);
			}
			for(auto t : ans) printf("%lld " , t);
		}
	}
	return 0;
}
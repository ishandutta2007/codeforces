/*
5 3
1 4
3 0 1 2
 */
#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 7; int T , N , M , B , G; long long Ans = -1; vector < int > pl[_] , pr[_];
void exgcd(int a , int b , int &x , int &y){!b ? (x = 1 , y = 0) : (exgcd(b , a % b , y , x) , y -= a / b * x);}
int qiv(int x , int y){x %= y; int a , b; exgcd(x , y , a , b); return a < 0 ? a + y : a;}

void solve(vector < int > p1 , vector < int > p2 , int n , int m){
	map < int , int > pot; int iv = qiv(m / T , n / T) , mx = -1;
	for(int i = 0 ; i < p1.size() ; ++i) pot[1ll * p1[i] / T * iv % (n / T)] = p1[i];
	for(int i = 0 ; i < p2.size() ; ++i)
		if(pot.find(1ll * p2[i] / T * iv % (n / T)) == pot.end()){
			pot[1ll * p2[i] / T * iv % (n / T)] = p2[i]; mx = p2[i];
		}
	Ans = max(Ans , 0ll + mx);
	pot[n / T + pot.begin()->first] = pot.begin()->second;
	for(auto p = pot.begin() , q = ++pot.begin() ; q != pot.end() ; ++p , ++q)
		if(q->first - p->first != 1)
			Ans = max(Ans , (q->first - p->first - 1ll) * m + p->second);
}

int main(){
	ios::sync_with_stdio(0); cin >> N >> M; T = __gcd(N , M); if(T > 2e5){cout << -1; return 0;}
	cin >> B; for(int i = 1 ; i <= B ; ++i){int p; cin >> p; pl[p % T].push_back(p);}
	cin >> G; for(int i = 1 ; i <= G ; ++i){int p; cin >> p; pr[p % T].push_back(p);}
	for(int i = 0 ; i < T ; ++i){
		if(pl[i].empty() && pr[i].empty()){puts("-1"); return 0;}
		sort(pl[i].begin() , pl[i].end()); sort(pr[i].begin() , pr[i].end());
		solve(pl[i] , pr[i] , N , M); solve(pr[i] , pl[i] , M , N);
	}
	cout << Ans; return 0;
}
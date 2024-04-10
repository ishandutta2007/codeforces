#include<bits/stdc++.h>
using namespace std;

const int P = 998244353;
int T , K , N , A[200003] , pos[200003] , B[200003]; bool vis[200003];

int main(){
	for(cin >> T ; T ; --T){
		cin >> N >> K; for(int i = 1 ; i <= N ; ++i){cin >> A[i]; pos[A[i]] = i; vis[i] = 0;}
		for(int i = 1 ; i <= K ; ++i){cin >> B[i]; vis[pos[B[i]]] = 1;}
		vis[0] = vis[N + 1] = 1; int tms = 1;
		for(int i = 1 ; i <= K ; ++i){
			tms = 1ll * tms * (!vis[pos[B[i]] - 1] + !vis[pos[B[i]] + 1]) % P;
			vis[pos[B[i]]] = 0;
		}
		cout << tms << endl;
	}
	return 0;
}
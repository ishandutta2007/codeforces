#include<bits/stdc++.h>
using namespace std;

const int _ = 1e5 + 7;
vector < int > ys[_]; int prm[_] , mu[_] , cnt; bool nprm[_];

void init(){
	mu[1] = 1;
	for(int i = 2 ; i <= 1e5 ; ++i){
		if(!nprm[i]){prm[++cnt] = i; mu[i] = -1;}
		for(int j = 1 ; prm[j] * i <= 1e5 ; ++j){
			nprm[prm[j] * i] = 1; if(!(i % prm[j])) break;
			mu[prm[j] * i] = -mu[i];
		}
	}
	for(int i = 1 ; i <= 1e5 ; ++i) for(int j = i ; j <= 1e5 ; j += i) ys[j].push_back(i);
}

int pot[_] , N; stack < int > val; bool vis[_]; long long ans = 1;
void add(int x , int f){for(auto t : ys[x]) pot[t] += f;}
bool chk(int x){int sum = 0; for(auto t : ys[x]) sum += mu[t] * pot[t]; return sum;}

int main(){
	cin >> N; init(); for(int i = 1 ; i <= N ; ++i){int x; cin >> x; for(auto t : ys[x]) vis[t] = 1;}
	for(int i = 1e5 ; i ; --i)
		if(vis[i])
			if(!chk(i)){val.push(i); add(i , 1);}
			else while(1){int t = val.top(); val.pop(); add(t , -1); if(!chk(i)){ans = max(ans , 1ll * t * i); break;}}
	cout << ans; return 0;
}
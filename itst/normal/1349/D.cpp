#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second
const int _ = 3e5 + 7 , P = 998244353;
int N , sum , A[_] , val[_];
int poww(long long a , int b){int tms = 1; while(b){if(b & 1) tms = tms * a % P; a = a * a % P; b >>= 1;} return tms;}

unordered_map < int , int > func[_];
void calc(){
	int iv = poww(sum , P - 2);
	for(int i = 0 ; i < sum ; ++i){
		if(i) func[i][i - 1] = 1ll * (P - i) * iv % P;
		if(i + 1 != sum) func[i][i + 1] = 1ll * (P + i - sum) * iv % P * poww(N - 1 , P - 2) % P;
		func[i][i] = (1 + 1ll * (P + i - sum) * iv % P * poww(N - 1 , P - 2) % P * (N - 2)) % P;
		val[i] = 1;
	}
	for(int i = 0 ; i < sum ; ++i){
		int now = i; while(now < sum && func[now].find(i) == func[now].end()) ++now;
		assert(now != sum); swap(func[now] , func[i]); swap(val[now] , val[i]);
		int iv = poww(func[i][i] , P - 2); for(auto &t : func[i]) t.nd = 1ll * t.nd * iv % P;
		val[i] = 1ll * val[i] * iv % P;

		while(++now < i + 2)
			if(func[now].find(i) != func[now].end()){
				int coef = func[now][i]; val[now] = (val[now] - 1ll * coef * val[i] % P + P) % P;
				for(auto t : func[i])
					if(!(func[now][t.st] = (func[now][t.st] - 1ll * coef * t.nd % P + P) % P))
						func[now].erase(t.st);
			}
	}

	for(int i = sum - 1 ; ~i ; --i)
		for(auto t : func[i]) if(t.st != i) val[i] = (val[i] - 1ll * t.nd * val[t.st] % P + P) % P;
}

int main(){
	cin >> N; for(int i = 1 ; i <= N ; ++i){cin >> A[i]; sum += A[i];}
	calc(); int sum = (P - N + 1ll) * val[0] % P;
	for(int i = 1 ; i <= N ; ++i) sum = (sum + val[A[i]]) % P;
	cout << 1ll * sum * poww(N , P - 2) % P; return 0;
}
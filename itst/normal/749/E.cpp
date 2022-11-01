#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
const int _ = 1e5 + 7;
int p[_] , N; ld sum;
struct BIT{
#define lowbit(x) x & -x
	ll arr[_];
	void add(int x , int val){while(x <= N){arr[x] += val; x += lowbit(x);}}
	ll qry(int x){ll sum = 0; while(x){sum += arr[x]; x -= lowbit(x);} return sum;}
}T1 , T2;

int main(){
	cin >> N;
	for(int i = 1 ; i <= N ; ++i) cin >> p[i];
	for(int i = 1 ; i <= N ; ++i) sum += 1.0 * i * (N - i) * (N - i + 1) / 4;
	for(int i = N ; i ; --i){
		sum += N * (N + 1ll) / 2.0 * T1.qry(p[i]) - 1.0 * i * T2.qry(p[i]); 
		T1.add(p[i] , 1); T2.add(p[i] , N - i + 1);
	}
	cout << fixed << setprecision(13) << sum / (N * (N + 1ll) / 2.0);
	return 0;
}
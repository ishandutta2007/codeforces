#include<bits/stdc++.h>
using namespace std;

int N , K , arr[200003] , id[200003];
const int MOD = 998244353;

signed main(){
	ios::sync_with_stdio(0);
	cin >> N >> K;
	for(int i = 1 ; i <= N ; ++i){cin >> arr[i]; id[arr[i]] = i;}
	vector < int > pot; long long sum = 0;
	for(int i = N ; i > N - K ; --i){pot.push_back(id[i]); sum += i;}
	sort(pot.begin() , pot.end()); int tms = 1;
	for(int i = 1 ; i < pot.size() ; ++i) tms = 1ll * tms * (pot[i] - pot[i - 1]) % MOD;
	cout << sum << ' ' << tms << endl;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
mt19937 rnd(time(0));
const int MOD = 1e9 + 7 , _ = 1e6 + 7;
int N , seed , Hash1[_] , Hash2[_] , powsd[_]; string now , str;
 
signed main(){
	ios::sync_with_stdio(0);
	cin >> N >> now;
	seed = rnd() % (int)(1e8) + 12349;
	powsd[0] = 1;
	for(int i = 1 ; i <= 1e6 ; ++i)
		powsd[i] = (powsd[i - 1] * seed) % MOD;
	for(int i = 2 ; i <= N ; ++i){
		cin >> str;
		int len = min(now.size() , str.size());
		Hash1[len + 1] = 0;
		//cerr << now << ' ' << str << endl;
		for(int j = now.size() - 1 ; j >= (int)now.size() - len ; --j){
			int id = len - (now.size() - j - 1);
			Hash1[id] = (Hash1[id + 1] + now[j] * powsd[now.size() - j - 1]) % MOD;
		}
		for(int j = 0 ; j < len ; ++j)
			Hash2[j + 1] = (Hash2[j] * seed + str[j]) % MOD;
		bool flg = 0;
		for(int j = len ; !flg && j ; --j)
			if(Hash2[j] == Hash1[len - j + 1]){
				now += string(str , j , str.size() - j);
				flg = 1;
			}
		if(!flg)
			now += str;
	}
	cout << now;
	return 0;
}
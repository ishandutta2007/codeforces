#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<random>
#include<unistd.h>
//This code is written by Itst
using namespace std;

#define int long long
#define PII pair < int , int >
#define ld long double
const int _ = 1e5 + 7 , T = sqrt(_) + 5;
int arr[_] , add[_] , mrk[T] , id[_] , N;

ld sect(PII p , PII q){return 1.0 * (q.second - p.second) / (p.first - q.first);}
int calc(PII p , int q){return p.first * q + p.second;}

struct Hull{
	deque < PII > q; int mrk;

	int get(){while(q.size() >= 2 && calc(q[0] , mrk) <= calc(q[1] , mrk)) q.pop_front(); return calc(q[0] , mrk);}
	void up(){++mrk;}
	
	void rebuild(int bl){
		q.clear(); mrk = 0;
		for(int i = bl * T ; i < N && i < (bl + 1) * T ; ++i){
			PII now(arr[id[i]] , add[id[i]]);
			if(q.size() && q.back().first == now.first)
				if(q.back().second > now.second) continue;
				else q.pop_back();
			while(q.size() >= 2 && sect(q[q.size() - 2] , now) < sect(q[q.size() - 2] , q[q.size() - 1])) q.pop_back();
			q.push_back(now);
		}
	}
}now[T];

void down(int bl){
	for(int i = T * bl ; i < N && i < (bl + 1) * T ; ++i)
		add[i] += now[bl].mrk * arr[i] + mrk[bl];
	mrk[bl] = 0;
}

signed main(){
	scanf("%lld" , &N);
	for(int i = 0 ; i < N ; ++i){scanf("%lld" , &arr[id[i] = i]); add[i] = arr[i];}
	for(int i = 0 ; i < N ; i += T){
		sort(id + i , id + min(T + i , N) , [&](int p , int q){return arr[p] < arr[q];});
		now[i / T].rebuild(i / T);
	}
	int sum = 0;
	while(1){
		int mx = -1e18 , id = -1;
		for(int i = 0 ; i < N / T + (bool)(N % T) ; ++i) if(mx < now[i].get() + mrk[i]){mx = now[i].get() + mrk[i]; id = i;}
		if(mx < 0) break;
		sum += mx; down(id);
		for(int i = T * id ; i < (id + 1) * T ; ++i)
			if(add[i] == mx){
				for(int j = 0 ; j < id ; ++j) mrk[j] += arr[i];
				for(int j = id + 1 ; j < N / T + (bool)(N % T) ; ++j) now[j].up();
				for(int j = T * id ; j < i ; ++j) add[j] += arr[i];
				add[i] = -1e15;
				for(int j = i + 1 ; j < N && j < (id + 1) * T ; ++j) add[j] += arr[j];
				now[id].rebuild(id);
				break;
			}
	}
	printf("%lld\n" , sum); return 0;
}
#include<iostream>
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

int N , K , to[123][123] , mx[123] , tmp[7] , tmp1[7] , tmp2[7] , val[200005]; bool vis[123];

int Cantor(int *arr){
	int sum = 0 , tms = 1;
	for(int i = K ; i ; tms *= K - (--i)) for(int j = i + 1 ; j <= K ; ++j) sum += tms * (arr[j] < arr[i]);
	return sum;
}

signed main(){
	cin >> N >> K; int jc = 1; for(int i = 2 ; i <= K ; ++i) jc *= i;
	for(int i = 1 ; i <= N ; ++i){
		for(int j = 1 ; j <= K ; ++j) cin >> tmp[j];
		val[i] = Cantor(tmp);
	}
	for(int i = 1 ; i <= K ; ++i) tmp[i] = i;
	int cnt = 0;
	do{
		for(int i = 1 ; i <= K ; ++i) tmp1[i] = i;
		int cnt1 = 0;
		do{
			for(int i = 1 ; i <= K ; ++i) tmp2[tmp1[i]] = tmp[i];
			to[cnt][cnt1++] = Cantor(tmp2);
		}while(next_permutation(tmp1 + 1 , tmp1 + K + 1));
		++cnt;
	}while(next_permutation(tmp + 1 , tmp + K + 1));
	memset(mx , -1 , sizeof(mx)); long long sum = N * (N + 1ll) / 2;
	for(int i = 1 ; i <= N ; ++i){
		memset(vis , 0 , sizeof(vis)); vis[0] = 1; int x = -1 , id; mx[val[i]] = i;
		for(int j = 0 ; j < jc ; ++j) if(!vis[j] && x < mx[j]){x = mx[j]; id = j;}
		vector < int > in;
		while(x > 0){
			in.push_back(id); queue < int > q;
			for(int i = 0 ; i < jc ; ++i) if(vis[i] && !vis[to[i][id]]){vis[to[i][id]] = 1; q.push(to[i][id]);}
			while(!q.empty()){
				int t = q.front(); q.pop(); sum += x;
				for(auto p : in) if(!vis[to[t][p]]){vis[to[t][p]] = 1; q.push(to[t][p]);}
			}
			x = -1; for(int j = 0 ; j < jc ; ++j) if(!vis[j] && x < mx[j]){x = mx[j]; id = j;}
		}
	}
	cout << sum; return 0;
}
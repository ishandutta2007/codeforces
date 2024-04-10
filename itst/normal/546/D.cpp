#include<bits/stdc++.h>
using namespace std;

const int _ = 5e6 + 7;
int prm[_] , num[_] , cnt; bool nprm[_];

void init(){
	for(int i = 2 ; i <= 5e6 ; ++i){
		if(!nprm[i]) num[prm[++cnt] = i] = 1;
		for(int j = 1 ; prm[j] * i <= 5e6 ; ++j){
			nprm[prm[j] * i] = 1; num[prm[j] * i] = num[i] + 1;
			if(i % prm[j] == 0) break;
		}
	}
	for(int i = 2 ; i <= 5e6 ; ++i) num[i] += num[i - 1];
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T , N , M; init();
	for(cin >> T ; T ; --T){cin >> N >> M; cout << num[N] - num[M] << '\n';}
	return 0;
}
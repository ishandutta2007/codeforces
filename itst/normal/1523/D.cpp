#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

string str[200003]; int N , M , P , cnt[1 << 15]; long long ans;

void queryans(int x){
	vector < int > pot; memset(cnt , 0 , sizeof(cnt));
	for(int i = 0 ; i < M ; ++i) if(str[x][i] == '1') pot.push_back(i);
	for(int i = 1 ; i <= N ; ++i){
		int sum = 0;
		for(int j = 0 ; j < pot.size() ; ++j)
			sum |= (str[i][pot[j]] - '0') << j;
		++cnt[sum];
	}
	for(int i = 0 ; i < pot.size() ; ++i)
		for(int j = 0 ; j < 1 << (pot.size()) ; ++j)
			if(j >> i & 1) cnt[j ^ (1 << i)] += cnt[j];
	int mx = 0;
	for(int i = 1 ; i < 1 << pot.size() ; ++i)
		if(cnt[i] >= (N + 1) / 2 && __builtin_popcount(mx) < __builtin_popcount(i))
			mx = i;
	if(__builtin_popcountll(ans) < __builtin_popcount(mx)){
		ans = 0;
		for(int i = 0 ; i < pot.size() ; ++i) if(mx >> i & 1) ans |= 1ll << pot[i];
	}
}

int main(){
	ios::sync_with_stdio(0); cin >> N >> M >> P;
	for(int i = 1 ; i <= N ; ++i) cin >> str[i];
	mt19937 rnd(time(0)); for(int i = 1 ; i <= 16 ; ++i) queryans(rnd() % N + 1);
	for(int i = 0 ; i < M ; ++i) cout << (ans >> i & 1);
	return 0;
}
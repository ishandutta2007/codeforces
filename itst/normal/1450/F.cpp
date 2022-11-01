#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

int T , N , seq[100003] , cnt[100003]; vector < pair < int , int > > pot;

int main(){
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 1 ; i <= N ; ++i) cnt[i] = 0;
		for(int i = 1 ; i <= N ; ++i){cin >> seq[i]; ++cnt[seq[i]];}
		int pre = 1; pot.clear(); int mx = 0;
		for(int i = 1 ; i <= N ; ++i) mx = max(mx , cnt[i]);
		if(mx > (N + 1) / 2){puts("-1"); continue;}
		for(int i = 1 ; i <= N ; ++i) cnt[i] = 0;
		for(int i = 2 ; i <= N ; ++i)
			if(seq[i] == seq[i - 1]){pot.push_back(make_pair(seq[pre] , seq[i - 1])); pre = i;}
		pot.push_back(make_pair(seq[pre] , seq[N])); for(auto t : pot) if(t.first == t.second) ++cnt[t.first];
		mx = 0; for(int i = 1 ; i <= N ; ++i) if(cnt[i] > cnt[mx]) mx = i;
		int cntl = 0; for(auto t : pot) cntl += t.first != mx && t.second != mx;
		if(cntl >= cnt[mx] - 1){cout << pot.size() - 1 << endl;}
		else cout << pot.size() + (cnt[mx] - 1 - cntl) - 1 << endl;
	}
	return 0;
}
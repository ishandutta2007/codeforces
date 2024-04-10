#include<bits/stdc++.h>
using namespace std;

int N , seq[1003] , now[1003] , cnt;

int main(){
	cin >> N; if(N <= 3){cout << 0 << endl; return 0;}
	int mn = N , id = 0;
	for(int i = N / 2 - 1 ; i ; --i){
		int val = N / (i + 1) + (bool)(N % (i + 1)) + i;
		if(mn > val){mn = val; id = i;}
	}
	for(int i = 0 ; i + 1 < N ; ++i) seq[i] = (i + 1) % (id + 1);
	while(cnt < N - mn){
		vector < int > pos;
		for(int i = 0 ; i < N ; ++i) if(now[i] != seq[i]){now[i] = seq[i]; pos.push_back(i + 1); ++cnt;}
		cout << pos.size() << endl; for(int i = 0 ; i < pos.size() ; ++i) cout << pos[i] << ' ';
		cout << endl; int p; cin >> p; --p;
		for(int i = p , num = 0 ; num < pos.size() ; ++num , i = (i + 1) % N)
			if(now[i]){now[i] = 0; --cnt;}
	}
	cout << 0 << endl; return 0;
}
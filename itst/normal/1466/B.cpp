#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

int V[200003] , T , N;

int main(){
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> V[i];
		int cnt = 1; ++V[N];
		for(int i = N - 1 ; i ; --i){
			if(V[i] < V[i + 1] - 1) ++V[i];
			cnt += V[i] != V[i + 1];
		}
		cout << cnt << endl;
	}
	return 0;
}
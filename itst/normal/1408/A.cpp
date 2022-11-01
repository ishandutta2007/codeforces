#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

int T , N , A[103] , B[103] , C[103] , P[103];

int main(){
	for(cin >> T ; T ; --T){
		cin >> N;
		for(int i = 1 ; i <= N ; ++i) cin >> A[i];
		for(int i = 1 ; i <= N ; ++i) cin >> B[i];
		for(int i = 1 ; i <= N ; ++i) cin >> C[i];
		P[1] = A[1];
		for(int i = 2 ; i <= N ; ++i){
			P[i + 1] = i == N ? P[1] : 0;
			vector < int > pot{A[i] , B[i] , C[i]};
			for(int j = 0 ; j < 3 ; ++j)
				if(pot[j] != P[i - 1] && pot[j] != P[i + 1])
					P[i] = pot[j];
		}
		for(int i = 1 ; i <= N ; ++i) cout << P[i] << " \n"[i == N];
	}
	return 0;
}
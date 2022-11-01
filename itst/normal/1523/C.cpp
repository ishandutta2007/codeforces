#include<bits/stdc++.h>
using namespace std;

int T , N , A[1003]; bool vis[1003]; vector < int > seq[1003];

int main(){
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 1 ; i <= N ; ++i){cin >> A[i]; vis[i] = 0;}
		seq[1].clear(); seq[1].push_back(1);
		for(int i = 2 ; i <= N ; ++i)
			if(A[i] == 1){seq[i] = seq[i - 1]; seq[i].push_back(1);}
			else{
				seq[i] = seq[i - 1]; while(seq[i].back() + 1 != A[i]) seq[i].pop_back();
				++seq[i].back();
			}
		for(int i = 1 ; i <= N ; ++i)
			for(int j = 0 ; j < seq[i].size() ; ++j)
				cout << seq[i][j] << ".\n"[j + 1 == seq[i].size()];
	}
	return 0;
}
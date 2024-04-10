#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	long long P , Q , T;
	for(cin >> T ; T ; --T){
		cin >> P >> Q; if(P % Q){cout << P << endl; continue;}
		long long mx = 0;
		for(int i = 2 ; i * i <= Q ; ++i)
			if(Q % i == 0){
				int cnt1 = 0; while(Q % i == 0){Q /= i; ++cnt1;}
				long long V = P; while(V % i == 0) V /= i;
				for(int j = 1 ; j < cnt1 ; ++j) V *= i;
				mx = max(mx , V);
			}
		if(Q != 1){
			long long V = P; while(V % Q == 0) V /= Q;
			mx = max(mx , V);
		}
		cout << mx << endl;
	}
	return 0;
}
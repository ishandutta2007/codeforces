#include<bits/stdc++.h>
using namespace std;

int A[10003] , O[10003] , N , K , B[10003] , ans[10003];

int main(){
	cin >> N >> K;
	for(int i = 1 ; i <= N ; ++i){
		cout << "or " << i << ' ' << (i == 1 ? 3 : i - 1) << endl; cin>>O[i];
		cout << "and " << i << ' ' << (i == 1 ? 3 : i - 1) << endl; cin>>A[i];
	}
	for(int i = 0 ; i < 30 ; ++i)
		for(int t = 0 ; t < 2 ; ++t){
			B[1] = t; bool f = 1;
			for(int j = 2 ; j <= N ; ++j){
				bool flg = (O[j] >> i & 1) & !(A[j] >> i & 1);
				B[j] = B[j - 1] ^ flg;
				f &= ((B[j] | B[j - 1]) == (O[j] >> i & 1)) && ((B[j] & B[j - 1]) == (A[j] >> i & 1));
			}
			f &= ((B[1] & B[3]) == (A[1] >> i & 1)) && ((B[1] | B[3]) == (O[1] >> i & 1));
			if(f) for(int j = 1 ; j <= N ; ++j) ans[j] |= B[j] << i;
		}
	sort(ans + 1 , ans + N + 1); cout << "finish " << ans[K] << endl;
	return 0;
}
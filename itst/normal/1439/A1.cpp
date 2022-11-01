#include<bits/stdc++.h>
using namespace std;

struct dat{int x1 , y1 , x2 , y2 , x3 , y3;};
int T , N , M; string str[103];

signed main(){
	for(cin >> T ; T ; --T){
		cin >> N >> M; for(int i = 0 ; i < N ; ++i) cin >> str[i];
		vector < dat > pot;
		for(int i = N - 1 ; i >= 2 ; --i)
			for(int j = M - 1 ; ~j ; --j)
				if(str[i][j] == '1'){
					pot.push_back((dat){i , j , i - 1 , j , i - 1 , j ? j - 1 : 1});
					str[i][j] = '0'; str[i - 1][j] ^= 1; str[i - 1][j ? j - 1 : 1] ^= 1;
				}
		for(int j = M - 1 ; j >= 2 ; --j)
			for(int i = 0 ; i < 2 ; ++i)
				if(str[i][j] == '1'){
					pot.push_back((dat){i , j , i , j - 1 , i ^ 1 , j - 1});
					str[i][j] = '0'; str[0][j - 1] ^= 1; str[1][j - 1] ^= 1;
				}
		int mn = 15;
		for(int i = 0 ; i < 1 << 4 ; ++i){
			int v[2][2] = {str[0][0] - '0' , str[0][1] - '0' , str[1][0] - '0' , str[1][1] - '0'};
			for(int j = 0 ; j < 2 ; ++j)
				for(int k = 0 ; k < 2 ; ++k)
					if(i >> (j * 2 + k) & 1){
						v[j][k] ^= 1; v[j ^ 1][k] ^= 1; v[j][k ^ 1] ^= 1;
					}
			bool f = 1; for(int p = 0 ; p < 2 ; ++p) for(int q = 0 ; q < 2 ; ++q) f &= !v[p][q];
			if(f && __builtin_popcount(mn) > __builtin_popcount(i)) mn = i;
		}
		for(int i = 0 ; i < 2 ; ++i)
			for(int j = 0 ; j < 2 ; ++j)
				if(mn >> (i * 2 + j) & 1)
					pot.push_back((dat){i , j , i ^ 1 , j , i , j ^ 1});
		cout << pot.size() << endl;
		for(auto t : pot) cout << t.x1 + 1 << ' ' << t.y1 + 1 << ' ' << t.x2 + 1 << ' ' << t.y2 + 1 << ' ' << t.x3 + 1 << ' ' << t.y3 + 1 << endl;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int _ = 2003 , P = 1e9 + 7; void inc(int &a , int b){a = a + b >= P ? a + b - P : a + b;}
char str[2][_] , mod[_]; int tol[2][_][_] , tor[2][_][_] , dpl[2][_][_] , dpr[2][_][_] , N , K;

int main(){
	scanf("%s %s" , str[0] + 1 , str[1] + 1); N = strlen(str[0] + 1); scanf("%s" , mod + 1); K = strlen(mod + 1);
	for(int i = 0 ; i < 2 ; ++i) for(int j = 1 ; j <= N ; ++j) tol[i][j][K + 1] = tor[i][j][K + 1] = K + 1;
	for(int i = 0 ; i < 2 ; ++i) for(int j = 0 ; j <= K + 1 ; ++j) tol[i][0][j] = tor[i][N + 1][j] = j;
	for(int L = K ; L ; --L)
		for(int i = 0 ; i < 2 ; ++i)
			for(int j = 1 ; j <= N ; ++j)
				if(mod[L] == str[i][j]){tol[i][j][L] = tol[i][j - 1][L + 1]; tor[i][j][L] = tor[i][j + 1][L + 1];}
				else tol[i][j][L] = tor[i][j][L] = L;

	for(int L = K ; L ; --L)
		for(int i = 0 ; i < 2 ; ++i)
			for(int j = 1 ; j <= N ; ++j)
				if(tol[i][j][L] != L)
					if(L == K) dpl[i][j][L] = dpr[i][j][L] = 1;
					else{
						inc(dpl[i][j][L] , dpl[i][j - 1][L + 1]); inc(dpr[i][j][L] , dpr[i][j + 1][L + 1]);
						if(str[i ^ 1][j] == mod[L + 1] && L != K - 1){
							inc(dpl[i][j][L] , dpl[i ^ 1][j - 1][L + 2]); inc(dpr[i][j][L] , dpr[i ^ 1][j + 1][L + 2]);
						}
						int len = (K + 1 - L) / 2;
						if(!((K + 1 - L) & 1)){
							dpl[i][j][L] += tol[i][j][L] >= L + len && tor[i ^ 1][j - len + 1][L + len] == K + 1;
							dpr[i][j][L] += tor[i][j][L] >= L + len && tol[i ^ 1][j + len - 1][L + len] == K + 1;
						}
					}

	int sum = 0;
	for(int i = 0 ; i < 2 ; ++i)
		for(int j = 1 ; j <= N ; ++j){
			for(int k = 1 ; k < tol[i][j][1] ; ++k){
				if(tor[i ^ 1][j - k + 1][k + 1] >= min(K + 1 , 2 * k + 1))
					if(2 * k + 1 < K + 1) inc(sum , dpr[i ^ 1][j + 1][2 * k + 1]); else ++sum;
				if(k != 1 && k < K - 1 && tol[i ^ 1][j - k + 1][k + 1] != k + 1) inc(sum , dpl[i ^ 1][j - k][k + 2]);
			}
			for(int k = 1 ; k < tor[i][j][1] ; ++k){
				if(tol[i ^ 1][j + k - 1][k + 1] >= min(K + 1 , 2 * k + 1))
					if(2 * k + 1 < K + 1) inc(sum , dpl[i ^ 1][j - 1][2 * k + 1]); else sum += k != 1;
				if(k != 1 && k < K - 1 && tor[i ^ 1][j + k - 1][k + 1] != k + 1) inc(sum , dpr[i ^ 1][j + k][k + 2]);
			}
		}
	cout << (sum % P + P) % P; return 0;
}
#include<bits/stdc++.h>
#define MAXN 2010
using namespace std;

int sumA[MAXN] , sumB[MAXN] , minA[MAXN] , minB[MAXN];

int main(){
	int N , M , x , s = 0;
	cin >> N >> M;
	memset(minA , 0x3f , sizeof(minA));
	memset(minB , 0x3f , sizeof(minB));
	for(int i = 1 ; i <= N ; i++){
		cin >> sumA[i];
		sumA[i] += sumA[i - 1];
		for(int j = 1 ; j <= i ; j++)
			minA[j] = min(minA[j] , sumA[i] - sumA[i - j]);
	}
	for(int i = 1 ; i <= M ; i++){
		cin >> sumB[i];
		sumB[i] += sumB[i - 1];
		for(int j = 1 ; j <= i ; j++)
			minB[j] = min(minB[j] , sumB[i] - sumB[i - j]);
	}
	cin >> x;
	int dir = 0;
	for(int i = M ; i ; i--){
		while(dir < N && minA[dir + 1] * (long long)minB[i] <= x)
			dir++;
		s = max(s , dir * i);
	}
	cout << s;
	return 0;
}
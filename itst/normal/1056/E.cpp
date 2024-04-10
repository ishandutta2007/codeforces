#include<bits/stdc++.h>
#define ll long long
#define PLL pair < ll , ll > 
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c) && c != EOF){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	if(c == EOF)
		exit(0);
	while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int seed = 13331 , MOD1 = 1e9 + 7 , MOD2 = 1e9 + 9;
char s1[100010] , s2[1000010];
int L1 , L2 , cnt0 , cnt1 , cnt;
ll Hash[1000010][2] , poww[1000010][2];

void input(){
	scanf("%s %s" , s1 + 1 , s2 + 1);
	L1 = strlen(s1 + 1);
	L2 = strlen(s2 + 1);
}

void init(){
	for(int i = 1 ; i <= L1 ; ++i)
		s1[i] == '0' ? ++cnt0 : ++cnt1;
	poww[0][0] = poww[0][1] = 1;
	for(int i = 1 ; i <= L2 ; ++i){
		Hash[i][0] = (Hash[i - 1][0] * seed + s2[i]) % MOD1;
		Hash[i][1] = (Hash[i - 1][1] * seed + s2[i]) % MOD2;
		poww[i][0] = poww[i - 1][0] * seed % MOD1;
		poww[i][1] = poww[i - 1][1] * seed % MOD2;
	}
}

inline PLL calcHash(int i , int j){
	return PLL((Hash[i + j - 1][0] - Hash[i - 1][0] * poww[j][0] % MOD1 + MOD1) % MOD1 , (Hash[i + j - 1][1] - Hash[i - 1][1] * poww[j][1] % MOD2 + MOD2) % MOD2);
}

void work(){
	for(int i = 1 ; i * cnt0 < L2 ; ++i)
		if(!((L2 - i * cnt0) % cnt1)){
			int p = 1 , j = (L2 - i * cnt0) / cnt1;
			bool f = 1;
			PLL Hash0 = PLL(-1,0) , Hash1 = PLL(-1,0);
			for(int k = 1 ; f && k <= L1 ; ++k)
				if(s1[k] == '0'){
					if(Hash0.first == -1)
						Hash0 = calcHash(p , i);
					else
						if(Hash0 != calcHash(p , i))
							f = 0;
					p += i;
				}
				else{
					if(Hash1.first == -1)
						Hash1 = calcHash(p , j);
					else
						if(Hash1 != calcHash(p , j))
							f = 0;
					p += j;
				}
			cnt += f && (Hash0 != Hash1);
		}
}

void output(){
	cout << cnt;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
#endif
	input();
	init();
	work();
	output();
	return 0;
}
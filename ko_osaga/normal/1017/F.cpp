#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;

char che[12500005]; // (1, 5, 7, 11) .. (i / 6 + (i % 6 == 5))
int main(){
	int n;
	unsigned a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	int FUCK1 = 1;
	for(int i=5; i<=n && i<=20000; i+=2){
		if(i % 6 == 3) continue;
		if(che[FUCK1 >> 3] & (1 << (FUCK1 & 7))){
			FUCK1++;
			continue;
		}
		for(int j=i*i; j<=n; j+=i+i){
			if(j % 6 == 3) continue;
			int ptr = 2 * (j / 6) + (j % 6 == 5);
			che[ptr >> 3] |= (1 << (ptr & 7));
		}
		FUCK1++;
	}
	auto func = [&](unsigned p){
		unsigned ret = a * p * p * p + b * p * p + c * p + d;
		unsigned jesu = 0;
		long long temp = p;
		while(temp <= n){
			jesu += n / temp;
			temp *= p;
		}
		return ret * jesu;
	};
	unsigned ans = func(2) + func(3);
	FUCK1 = 1;
	for(int i=5; i<=n; i+=6, FUCK1 += 2){
		if(che[FUCK1 >> 3] & (1 << (FUCK1 & 7))){
			continue;
		}
		ans += func(i);
	}
	FUCK1 = 2;
	for(int i=7; i<=n; i+=6, FUCK1 += 2){
		if(che[FUCK1 >> 3] & (1 << (FUCK1 & 7))){
			continue;
		}
		ans += func(i);
	}
	cout << ans << endl;
}
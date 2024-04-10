#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c)){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

int main(){
	int K , N , ans = 1e9 + 10;
	cin >> N >> K;
	for(int i = 1 ; i < K ; ++i)
		if(N % i == 0)
			ans = min(ans , N / i * K + i);
	cout << ans;
	return 0;
}
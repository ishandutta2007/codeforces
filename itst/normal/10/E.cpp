#include<bits/stdc++.h>
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

int num[410] , N;

int main(){
	int ans = -1;
	N = read();
	for(int i = 1 ; i <= N ; ++i)
		num[i] = read();
	for(int i = 2 ; i <= N ; ++i)
		for(int j = i ; j <= N ; ++j){
			int t = num[i - 1] - 1 , cnt = 1 , w = num[j];
			for(int k = i ; k <= j ; ++k){
				cnt += t / num[k];
				w += t / num[k] * num[k];
				t %= num[k];
			}
			t = w;
			for(int k = 1 ; k <= N ; ++k){
				cnt -= t / num[k];
				t %= num[k];
			}
			if(cnt < 0 && (ans == -1 || w < ans))
				ans = w;
		}
	cout << ans;
	return 0;
}
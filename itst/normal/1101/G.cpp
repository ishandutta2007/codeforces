#include<bits/stdc++.h>
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return a;
}

const int MAXN = 2e5 + 10;
int N , cnt , num[MAXN] , xxj[32];

int main(){
	N = read();
	for(int i = 1 ; i <= N ; ++i)
		num[i] = read() ^ num[i - 1];
	if(num[N] == 0){
		puts("-1");
		return 0;
	}
	xxj[(int)log2(num[N] + 0.5)] = num[N];
	cnt = 1;
	for(int i = 1 ; i < N ; ++i)
		while(num[i]){
			int t = (int)log2(num[i] + 0.5);
			if(xxj[t])
				num[i] ^= xxj[t];
			else{
				++cnt;
				xxj[t] = num[i];
				break;
			}
		}
	cout << cnt << endl;
	return 0;
}
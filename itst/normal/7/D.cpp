#include<bits/stdc++.h>
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
		a = a * 10 + c - 48;
		c = getchar();
	}
	return f ? -a : a;
}

const int MAXN = 5e6 + 7;
char s[MAXN] , S[MAXN << 1];
int len[MAXN] , val[MAXN] , L;

void work(){
	int maxR = 1 , maxI = 1;
	for(int i = 1 ; i <= L ; ++i){
		len[i] = min(len[2 * maxI - i] , maxR - i);
		while(i - len[i] && i + len[i] < 2 * L && S[i - len[i]] == S[i + len[i]])
			++len[i];
		if(!(i - len[i])){
			int L = (i + len[i]) >> 1;
			val[L] = val[L >> 1] + 1;
		}
		if(i + len[i] >= maxR){
			maxR = i + len[i];
			maxI = i;
		}
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	scanf("%s" , s + 1);
	L = strlen(s + 1);
	for(int i = 1 ; i <= L ; ++i)
		S[2 * i - 1] = s[i];
	work();
	long long ans = 0;
	for(int i = 1 ; i <= L ; ++i)
		ans += val[i];
	cout << ans;
	return 0;
}
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

const int MAXN = 1e5 + 10;
int num[MAXN] , times[MAXN] , N , maxN , minN;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
#endif
	N = read();
	for(int i = 1 ; i <= N ; ++i)
		num[i] = read();
	int maxLen = 1 , p = 1;
	times[num[1]] = 1;
	maxN = minN = num[1];
	for(int i = 1 ; i < N ; ++i){
		while(p < N && num[p + 1] - minN <= 1 && maxN - num[p + 1] <= 1){
			if(!times[num[p + 1]])
				if(maxN < num[p + 1])
					maxN = num[p + 1];
				else
					minN = num[p + 1];
			++times[num[++p]];
		}
		maxLen = max(maxLen , p - i + 1);
		if(times[num[i]] == 1)
			if(minN == num[i])
				minN = num[i] + 1;
			else
				maxN = num[i] - 1;
		--times[num[i]];
	}
	cout << maxLen;
	return 0;
}
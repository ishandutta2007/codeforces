#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	bool f = 0;
	char c = getchar();
	while(c != EOF && !isdigit(c)){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	while(c != EOF && isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int MAXN = 200010;
int num[MAXN] , pot[MAXN];

int main(){
#ifndef ONLINE_JUDGE
	freopen("1077E.in" , "r" , stdin);
	//freopen("1077E.out" , "w" , stdout);
#endif
	int N = read();
	for(int i = 1 ; i <= N ; ++i)
		num[i] = read();
	sort(num + 1 , num + N + 1);
	int cnt = 0 , nowNum = num[1] , nowCnt = 1;
	for(int i = 2 ; i <= N + 1 ; ++i)
		if(num[i] == nowNum)
			nowCnt++;
		else{
			pot[++cnt] = nowCnt;
			nowNum = num[i];
			nowCnt = 1;
		}
	sort(pot + 1 , pot + cnt + 1);
	int nowMin = MAXN << 1 , maxN = 0;
	for(int i = cnt ; i ; --i){
		nowMin = min(nowMin >> 1 , pot[i]);
		if(!nowMin)
			break;
		maxN = max(maxN , ((1 << cnt - i + 1) - 1) * nowMin);
	}
	cout << maxN;
	return 0;
}
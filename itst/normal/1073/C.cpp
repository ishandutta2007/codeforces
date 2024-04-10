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
char s[MAXN];
int front[MAXN][2] , back[MAXN][2] , N , x , y;

inline int abs(int x){
	return x < 0 ? -x : x;
}

bool check(int mid){
	for(int i = mid + 1 ; i <= N + 1 ; ++i){
		int _x = front[i - mid - 1][0] + back[i][0] , _y = front[i - mid - 1][1] + back[i][1];
		if(abs(_x - x) + abs(_y - y) <= mid)
			return 1;
	}
	return 0;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("1073C.in" , "r" , stdin);
	//freopen("1073C.out" , "w" , stdout);
#endif
	N = read();
	scanf("%s" , s + 1);
	x = read();
	y = read();
	if(((x + y & 1) ^ (N & 1)) || abs(x) + abs(y) > N){
		puts("-1");
		return 0;
	}
	for(int i = 1 ; i <= N ; ++i)
		switch(s[i]){
		case 'L':
			front[i][0] = back[i][0] = -1;
			break;
		case 'R':
			front[i][0] = back[i][0] = 1;
			break;
		case 'U':
			front[i][1] = back[i][1] = 1;
			break;
		default:
			front[i][1] = back[i][1] = -1;
		}
	for(int i = 1 ; i <= N ; ++i){
		front[i][0] += front[i - 1][0];
		front[i][1] += front[i - 1][1];
	}
	for(int i = N ; i ; --i){
		back[i][0] += back[i + 1][0];
		back[i][1] += back[i + 1][1];
	}
	int l = 0 , r = N;
	while(l < r){
		int mid = l + r >> 1;
		check(mid) ? r = mid : l = mid + 1;
	}
	cout << l;
	return 0;
}
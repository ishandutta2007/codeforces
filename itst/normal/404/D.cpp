#include<bits/stdc++.h>
#define NO {cout << 0; return 0;}
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

const int MAXN = 1000010 , MOD = 1e9 + 7;
char s[MAXN];
int now[MAXN] , N;

inline int poww(long long a , int b){
	int times = 1;
	while(b){
		if(b & 1)
			times = times * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return times;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("404D.in" , "r" , stdin);
	//freopen("404D.out" , "w" , stdout);
#endif
	scanf("%s" , s + 1);
	N = strlen(s + 1);
	now[0] = now[N + 1] = 1;
	for(int i = 1 ; i <= N ; ++i)
		if(s[i] == '*'){
			if(now[i] == 1)
				NO
			else
				now[i] = -1;
		}
		else
			if(s[i] != '?'){
				if(now[i] == -1)
					NO
				now[i] = 1;
				if(s[i] == '2')
					if(now[i - 1] == 1)
						NO
					else
						now[i - 1] = now[i + 1] = -1;
				else
					if(s[i] == '0')
						if(now[i - 1] == -1)
							NO
						else
							now[i - 1] = now[i + 1] = 1;
			}
	for(int i = 1 ; i <= N ; ++i)
		if(s[i] == '1')
			if(now[i - 1] == -1)
				if(now[i + 1] == -1)
					NO
				else
					now[i + 1] = 1;
			else
				if(now[i - 1] == 1)
					if(now[i + 1] == 1)
						NO
					else
						now[i + 1] = -1;
	for(int i = N ; i ; --i)
		if(s[i] == '1')
			if(now[i + 1] == -1)
				if(now[i - 1] == -1)
					NO
				else
					now[i - 1] = 1;
			else
				if(now[i + 1] == 1)
					if(now[i - 1] == 1)
						NO
					else
						now[i - 1] = -1;
	int cnt = 0;
	for(int i = 1 ; i <= N ; i++)
		if(s[i] == '1' && !now[i - 1] && !now[i + 1])
			--cnt;
		else
			if(!now[i])
				++cnt;
	cout << poww(2 , cnt);
	return 0;
}
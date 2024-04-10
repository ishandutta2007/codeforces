#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

bitset < 4003 > now[2003];
int N , M , s[500003] , t[500003];

#define REP(i , j , k) for(int i = j , TEMP = k ; i <= TEMP ; ++i)
int main(){
	N = read(); M = read();
	REP(i , 1 , M){s[i] = read(); t[i] = read(); now[s[i]].set(t[i]);}
	REP(i , 1 , N) now[i].set(i + N);
	REP(i , 1 , N){
	    REP(j , i , N) if(now[j][i]){swap(now[i] , now[j]); break;}
		REP(j , i + 1 , N) if(now[j][i]) now[j] ^= now[i];
	}
	REP(i , 1 , N) REP(j , 1 , i - 1) if(now[j][i]) now[j] ^= now[i];
	REP(i , 1 , M) puts(now[t[i]][s[i] + N] ? "NO" : "YES");
	return 0;
}
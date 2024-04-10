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

const int MAXN = 1e6 + 9;
struct Edge{
	int end , upEd;
}Ed[MAXN << 1];
int head[MAXN] , in[MAXN] , N , cntEd , cnt;
char s[MAXN];

inline void addEd(int a , int b){
	Ed[++cntEd].end = b;
	Ed[cntEd].upEd = head[a];
	head[a] = cntEd;
	++in[a];
}

int main(){
	for(int T = read() ; T ; --T){
		N = read();
		cntEd = 0;
		memset(head , 0 , sizeof(int) * (N + 1));
		memset(in , 0 , sizeof(int) * (N + 1));
		for(int i = 1 ; i < N ; ++i){
			int a = read() , b = read();
			addEd(a , b);
			addEd(b , a);
		}
		scanf("%s" , s + 1);
		if(N < 3){
		    puts("Draw");
		    continue;
		}
		if(N == 3){
		    int cnt = 0;
		    for(int i = 1 ; i <= N ; ++i)
		        cnt += s[i] == 'W';
		    puts(cnt >= 2 ? "White" : "Draw");
		    continue;
		}
		bool ifans = 0;
		int cnt1 = 0;
		for(int i = 1 ; i <= N ; ++i)
		    if(s[i] == 'W'){
		        addEd(i , ++N);
		        head[N] = 0;
		        addEd(N , i);
		        in[N] = 3;
		    }
		for(int i = 1 ; !ifans && i <= N ; ++i)
			if(in[i] > 3)
				ifans = 1;
			else
				if(in[i] == 3){
					int cnt = 0; 
					for(int j = head[i] ; j ; j = Ed[j].upEd)
						cnt += in[Ed[j].end] >= 2;
					ifans = cnt >= 2;
					++cnt1;
			}
		if(cnt1 == 2 && (N & 1))
		    ifans = 1;
		puts(ifans ? "White" : "Draw");
	}
	return 0;
}
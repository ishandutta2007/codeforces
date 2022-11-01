#include<bits/stdc++.h>
#define int long long
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

inline char getc(){
	char c =getchar();
	while(c == '\n' || c == '\r' || c == ' ')
		c = getchar();
	return c;
}
#define PII pair < int , int >
const int MAXN = 1e5 + 10;
int N , M , num[MAXN] , cost[MAXN];
priority_queue < PII > q;

signed main(){
	N = read();
	M = read();
	for(int i = 1 ; i <= N ; ++i)
		num[i] = read();
	for(int i = 1 ; i <= N ; ++i){
		cost[i] = read();
		q.push(PII(-cost[i] , -i));
	}
	while(M--){
		int sum = 0 , t = read() , b = read() , k = min(num[t] , b);
		sum += k * cost[t];
		num[t] -= k;
		b -= k;
		while(b && !q.empty()){
			int p = -q.top().second;
			q.pop();
			k = min(num[p] , b);
			sum += k * cost[p];
			num[p] -= k;
			b -= k;
			if(num[p])
				q.push(PII(-cost[p] , -p));
		}
		if(b)
			cout << 0 << '\n';
		else
			cout << sum << '\n';
	}
	return 0;
}
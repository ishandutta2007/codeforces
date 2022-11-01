#include<bits/stdc++.h>
#define int long long
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

inline int calc(int x1 , int y1 , int x2 , int y2 , int type){
	if((x2 - x1 & 1) || (y2 - y1 & 1))
		return (x2 - x1 + 1) * (y2 - y1 + 1) >> 1;
	else
		return ((x2 - x1 + 1) * (y2 - y1 + 1) >> 1) + (x1 + y1 + type & 1);
}

signed main(){
	for(int T = read() ; T ; --T){
		int a = read() , b = read();
		int nowB = calc(1 , 1 , a , b , 0) , nowW = calc(1 , 1 , a , b , 1);
		int x1 = read() , y1 = read() , x2 = read() , y2 = read();
		nowB -= calc(x1 , y1 , x2 , y2 , 0);
		nowW += calc(x1 , y1 , x2 , y2 , 0);
		int p1 = read() , q1 = read() , p2 = read() , q2 = read();
		nowB += calc(p1 , q1 , p2 , q2 , 1);
		nowW -= calc(p1 , q1 , p2 , q2 , 1);
		int m1 = max(p1 , x1) , n1 = max(y1 , q1) , m2 = min(p2 , x2) , n2 = min(y2 , q2);
		if(m1 <= m2 && n1 <= n2){
			nowB += calc(m1 , n1 , m2 , n2 , 0);
			nowW -= calc(m1 , n1 , m2 , n2 , 0);
		}
		cout << nowW << ' ' << nowB << endl;
	}
	return 0;
}
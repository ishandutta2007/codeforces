#include<bits/stdc++.h>
using namespace std;

int N ;
struct comp{
	int x , y;
	comp(int _x = 0 , int _y = 0) : x(_x) , y(_y){}
	friend comp operator +(comp x , comp y){return comp(x.x + y.x , x.y + y.y);}
	friend comp operator -(comp x , comp y){return comp(x.x - y.x , x.y - y.y);}
	friend long long operator %(comp x , comp y){return 1ll * x.x * y.y - 1ll * x.y * y.x;}
	long long len2(){return 1ll * x * x + 1ll * y * y;}
}node[100003];

int main(){
	cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> node[i].x >> node[i].y;
	node[N + 1] = node[1]; if(N & 1){puts("NO"); return 0;}
	for(int i = 1 ; i <= N / 2 ; ++i){
		comp p = node[i + 1] - node[i] , q = node[N / 2 + i + 1] - node[N / 2 + i];
		if((p % q) != 0 || p.len2() != q.len2()){puts("NO"); return 0;}
	}
	puts("YES");
	return 0;
}
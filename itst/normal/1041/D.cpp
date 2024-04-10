 #include<bits/stdc++.h>
#define MAXN 200001
using namespace std;
inline int read(){
	int a = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return a;
}

inline int max(int a , int b){
	return a > b ? a : b;
}

int flow[MAXN][2];

int main()
{
	int num = read() , y = read() , dir = 0 , ans = 0;
	for(int i = 1 ; i <= num ; i++){
		flow[i][0] = read();
		flow[i][1] = read();
	}
	for(int i = 1 ; i <= num && dir < num ; i++){
		if(dir < i)
			dir++;
		while(dir < num && flow[dir + 1][0] - flow[dir][1] < y){
			y -= flow[dir + 1][0] - flow[dir][1];
			dir++;
		}
		ans = max(ans , y + flow[dir][1] - flow[i][0]);
		if(dir >= i + 1)
			y += flow[i + 1][0] - flow[i][1];
	}
	cout << ans;
 	return 0;
}
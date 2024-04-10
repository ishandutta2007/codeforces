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

struct node{
	int x , y;
}now[3];
int X , Y , ans[100010][2] , x[3] , cnt;
bool vis[1010][1010];

bool cmp1(node x , node y){
	return x.x < y.x;
}

bool cmp2(node x , node y){
	return x.y < y.y;
}

int main(){
	ans[1][0] = now[0].x = read();
	ans[1][1] = now[0].y = read();
	ans[2][0] = now[1].x = read();
	ans[2][1] = now[1].y = read();
	ans[3][0] = now[2].x = read();
	ans[3][1] = now[2].y = read();
	vis[now[0].x][now[0].y] = vis[now[1].x][now[1].y] = vis[now[2].x][now[2].y] = 1;
	cnt = 3;
	sort(now , now + 3 , cmp1);
	while(now[0].x < now[1].x)
		if(!vis[++now[0].x][now[0].y]){
			ans[++cnt][0] = now[0].x;
			ans[cnt][1] = now[0].y;
			vis[now[0].x][now[0].y] = 1;
		}
	while(now[2].x > now[1].x)
		if(!vis[--now[2].x][now[2].y]){
			ans[++cnt][0] = now[2].x;
			ans[cnt][1] = now[2].y;
			vis[now[2].x][now[2].y] = 1;
		}
	sort(now , now + 3 , cmp2);
	while(now[0].y + 1 < now[1].y)
		if(!vis[now[0].x][++now[0].y]){
			ans[++cnt][0] = now[0].x;
			ans[cnt][1] = now[0].y;
			vis[now[0].x][now[0].y] = 1;
		}
	while(now[2].y - 1 > now[1].y)
		if(!vis[now[2].x][--now[2].y]){
			ans[++cnt][0] = now[2].x;
			ans[cnt][1] = now[2].y;
			vis[now[2].x][now[2].y] = 1;
		}
	cout << cnt << endl;
	for(int i = 1 ; i <= cnt ; ++i)
		cout << ans[i][0] << ' ' << ans[i][1] << endl;
	return 0;
}
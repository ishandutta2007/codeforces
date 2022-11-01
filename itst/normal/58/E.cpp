#include<bits/stdc++.h>
using namespace std;
int now[15][3] , ans[15][3] , nA , nB , nC , minN = 12 , cnt , t[13];
void dfs(int a , int b , int c , int num , int jw , int cou , bool ifA , bool ifB){
	if(!a && !b && !c && !jw){
		minN = num;
		cnt = cou;
		memcpy(ans , now , sizeof(now));
		return;
	}
	if(a % 10 + b % 10 - c % 10 + jw == 0 && c)
		dfs(a / 10 , b / 10 , c / 10 , num , 0 , cou + 1 , a ? 0 : 1 , b ? 0 : 1);
	else	if(a % 10 + b % 10 - c % 10 + jw == 10 && c)
		dfs(a / 10 , b / 10 , c / 10 , num , 1 , cou + 1 , a ? 0 : 1 , b ? 0 : 1);
	else{
		if(minN - ++num <= 0)	return;
		now[num][2] = ++cou;
		if(!ifA && c){
			now[num][0] = 1;
			now[num][1] = (c % 10 - b % 10 - jw + 10) % 10;
			bool f = ifB;
			if(!b)	ifB = 1;
			dfs(a , b / 10 , c / 10 , num , (now[num][1] + b % 10 + jw - c % 10) / 10 , cou , ifA , ifB);
			ifB = f;
		}
		if(!ifB && c){
			now[num][0] = 2;
			now[num][1] = (c % 10 - a % 10 + 10 - jw) % 10;
			bool f = ifA;
			if(a == 0)	ifA = 1;
			dfs(a / 10 , b , c / 10 , num , (now[num][1] + a % 10 + jw - c % 10) / 10 , cou , ifA , ifB);
			ifA = f;
		}
		now[num][0] = 3;
		now[num][1] = (a % 10 + b % 10 + jw) % 10;
		if(!a)	ifA = 1;
		if(!b)	ifB = 1;
		dfs(a / 10 , b / 10 , c , num , (a % 10 + b % 10 + jw - now[num][1]) / 10 , cou , ifA , ifB);
	}
}
int main(){
	int a , b , c;
	bool f;
	scanf("%d+%d=%d" , &a , &b , &c);
	dfs(a , b , c , 0 , 0 , 0 , 0 , 0);
	int p = 1;
	while(p <= minN && ans[p][0] - 1)	p++;
	for(int i = 1 ; i <= cnt ; i++)
		if(p <= minN && ans[p][2] == i){
			t[i] = ans[p++][1];
			while(p <= minN && ans[p][0] - 1)	p++;
		}
		else{
			t[i] = a % 10;
			a /= 10;
		}
	f = 0;
	for(int i = cnt ; i ; i--)
		if(f || t[i]){
			putchar(t[i] + '0');
			f = 1;
		}
	putchar('+');
	p = 1;
	while(p <= minN && ans[p][0] - 2)	p++;
	for(int i = 1 ; i <= cnt ; i++)
		if(p <= minN && ans[p][2] == i){
			t[i] = ans[p++][1];
			while(p <= minN && ans[p][0] - 2)	p++;
		}
		else{
			t[i] = b % 10;
			b /= 10;
		}
	f = 0;
	for(int i = cnt ; i ; i--)
		if(f || t[i]){
			putchar(t[i] + '0');
			f = 1;
		}
	putchar('=');
	p = 1;
	while(p <= minN && ans[p][0] - 3)	p++;
	for(int i = 1 ; i <= cnt ; i++)
		if(p <= minN && ans[p][2] == i){
			t[i] = ans[p][1];
			p++;
			while(p <= minN && ans[p][0] - 3)	p++;
		}
		else{
			t[i] = c % 10;
			c /= 10;
		}
	f = 0;
	for(int i = cnt ; i ; i--)
		if(f || t[i]){
			putchar(t[i] + '0');
			f = 1;
		}
	return 0;
}
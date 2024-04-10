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

struct scroll{
	int pow , dmg , ind , times;
	bool operator <(const scroll a)const{
		return dmg < a.dmg;
	}
}now[1010] , ans[1010];
int cnt , k , maxN , reg , cur , N , all_damage;
priority_queue < scroll > q;

bool cmp(scroll a , scroll b){
	return a.pow > b.pow;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
#endif
	N = read();
	cur = maxN = read();
	reg = read();
	for(int i = 1 ; i <= N ; ++i){
		now[i].pow = read();
		now[i].dmg = read();
		now[i].ind = i;
	}
	sort(now + 1 , now + N + 1 , cmp);
	int p = 1;
	while(p <= N && cur * 100 <= maxN * now[p].pow)
		q.push(now[p++]);
	while(cur > 0){
		if(!q.empty()){
			ans[++k] = q.top();
			q.pop();
			ans[k].times = cnt;
			all_damage += ans[k].dmg;
		}
		else
			if(all_damage <= reg){
				puts("NO");
				return 0;
			}
		++cnt;
		cur = min(cur - all_damage + reg , maxN);
		while(p <= N && cur * 100 <= maxN * now[p].pow)
			q.push(now[p++]);
	}
	puts("YES");
	printf("%d %d\n" , cnt , k);
	for(int i = 1 ; i <= k ; ++i)
		printf("%d %d\n" , ans[i].times , ans[i].ind);
	return 0;
}
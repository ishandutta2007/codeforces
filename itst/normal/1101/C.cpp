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

const int MAXN = 1e5 + 10;
struct line{
	int l , r , ind;
}now[MAXN];
int N , ans[MAXN];

bool cmp(line a , line b){
	return a.l < b.l || a.l == b.l && a.r < b.r;
}

int main(){
	for(int T = read() ; T ; --T){
		N = read();
		bool f = 0;
		for(int i = 1 ; i <= N ; ++i){
			now[i].l = read();
			now[i].r = read();
			now[i].ind = i;
		}
		sort(now + 1 , now + N + 1 , cmp);
		int maxR = now[1].r;
		for(int i = 2 ; !f && i <= N ; ++i){
			if(now[i].l > maxR)
				f = 1;
			maxR = max(maxR , now[i].r);
		}
		if(!f)
			cout << -1;
		else{
			int cnt = 0;
			maxR = now[1].r;
			ans[now[1].ind] = 1;
			for(int i = 2 ; i <= N ; ++i){
				if(now[i].l > maxR)
					cnt ^= 1;
				maxR = max(maxR , now[i].r);
				ans[now[i].ind] = cnt + 1;
			}
			for(int i = 1 ; i <= N ; ++i)
				cout << ans[i] << ' ';
		}
		putchar('\n');
	}
	return 0;
}
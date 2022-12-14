#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<iomanip>
using namespace std;

int T , t , m , ml , mr , x , l , r;

int main(){
	for(scanf("%d" , &T) ; T ; --T){
		scanf("%d %d" , &t , &m); ml = mr = m; int current = 0; bool flg = 1;
		for(int i = 1 ; i <= t ; ++i){
			scanf("%d %d %d" , &x , &l , &r);
			ml -= x - current; mr += x - current; current = x;
			ml = max(ml , l); mr = min(mr , r); flg &= ml <= mr;
		}
		puts(flg ? "YES" : "NO");
	}
	return 0;
}
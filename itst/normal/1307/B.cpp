#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
	int T , N , x;
	for(scanf("%d" , &T) ; T ; --T){
		scanf("%d %d" , &N , &x); int mn = 1e9;
		for(int i = 1 ; i <= N ; ++i){
			int t; scanf("%d" , &t);
			if(t > x) mn = min(mn , 2); else mn = min(mn , (x + t - 1) / t);
		}
		printf("%d\n" , mn);
	}
	return 0;
}
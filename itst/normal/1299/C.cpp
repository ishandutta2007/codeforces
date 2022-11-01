#include<bits/stdc++.h>
using namespace std;

#define ld long double
struct pr{long long sum , num;}stk[1000003]; int top;
int N;

int main(){
	scanf("%d" , &N);
	for(int i = 1 , x ; i <= N ; ++i){
		scanf("%d" , &x); pr now; now.sum = x; now.num = 1;
		while(top && stk[top].sum * now.num >= now.sum * stk[top].num){
			now.sum += stk[top].sum; now.num += stk[top].num; --top;
		}
		stk[++top] = now;
	}
	for(int i = 1 ; i <= top ; ++i){
		double now = stk[i].sum * 1.0 / stk[i].num;
		for(int j = 1 ; j <= stk[i].num ; ++j)
			printf("%.9lf\n" , now);
	}
	return 0;
}
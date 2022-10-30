#include<cstdio>
#include<cmath>
using namespace std;

int val[51] , N;

int main(){
	scanf("%d" , &N);
	for(int i = 1 ; i <= N ; ++i) scanf("%d" , val + i);
	int ans = 0 , sum = 0;
	for(int i = N ; i ; --i){ans = abs(val[i] - ans); sum += val[i];}
	printf("%d %d" , (sum - ans) / 2 , (sum + ans) / 2);
	return 0;
}
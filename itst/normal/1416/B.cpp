#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

int A[10003] , T , N;

int main(){
	for(T = read() ; T ; --T){
		N = read(); int sum = 0; for(int i = 1 ; i <= N ; ++i){A[i] = read(); sum += A[i];}
		if(sum % N) puts("-1");
		else{
			printf("%d\n" , 3 * (N - 1));
			for(int i = 2 ; i <= N ; ++i){
				printf("1 %d %d\n" , i , (i - A[i] % i) % i); A[i] += (i - A[i] % i) % i;
				printf("%d 1 %d\n" , i , A[i] / i);
			}
			for(int i = 2 ; i <= N ; ++i) printf("1 %d %d\n" , i , sum / N);
		}
	}
	return 0;
}
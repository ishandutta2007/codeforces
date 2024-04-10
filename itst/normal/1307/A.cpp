#include<stdio.h>
using namespace std;

int arr[103] , T , N , d;

int main(){
	for(scanf("%d" , &T) ; T ; --T){
		scanf("%d %d" , &N , &d);
		for(int i = 1 ; i <= N ; ++i) scanf("%d" , &arr[i]);
		for(int i = 1 ; i <= d ; ++i)
			for(int j = 2 ; j <= N ; ++j) if(arr[j]){++arr[j - 1]; --arr[j]; break;}
		printf("%d\n" , arr[1]);
	}
	return 0;
}
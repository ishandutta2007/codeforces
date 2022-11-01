#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;

char str[100003]; long long pot[26] , pot1[26][26] , L;

int main(){
	scanf("%s" , str + 1); L = strlen(str + 1);
	for(int i = 1 ; i <= L ; ++i){
		int t = str[i] - 'a';
		for(int j = 0 ; j < 26 ; ++j) pot1[j][t] += pot[j];
		++pot[t];
	}
	long long mx = 0;
	for(int i = 0 ; i < 26 ; ++i) mx = max(mx , pot[i]);
	for(int i = 0 ; i < 26 ; ++i)
		for(int j = 0 ; j < 26 ; ++j)
			mx = max(mx , pot1[i][j]);
	printf("%lld\n" ,  mx);
	return 0;
}
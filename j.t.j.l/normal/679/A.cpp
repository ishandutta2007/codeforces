#include<bits/stdc++.h>

using namespace std;

int b[1001];

int work(int x, int p){
	int m = 100 / p;
	char t[1001];
	for (int j = 1; j <= 20 - x && b[j] * p <= 100; j++){
		printf("%d\n", b[j] * p);
		fflush(stdout);
		scanf("%s", t);
		if (t[0] == 'y'){
			printf("composite\n");
			return 0;
		}
	}
	printf("prime\n");
	return 0;
}

int main(){
	int n = 0;
	for(int i = 2; i <= 100; i++){
		int flag = 1;
		for(int j = 2; j * j <= i; j++)
			if (i % j == 0){
				flag = 0;
				break;
			}
		if (flag)
			b[++n] = i;
	}
	char s[100];
	for(int i = 1; b[i] <= 50; i++){
		printf("%d\n", b[i]);
		fflush(stdout);
		scanf("%s", s);
		if (s[0] == 'y'){
			work(i, b[i]);
			return 0;
		}
	}
	printf("prime\n");
	return 0;
}
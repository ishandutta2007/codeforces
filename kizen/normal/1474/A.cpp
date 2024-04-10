#include <bits/stdc++.h>

using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int N;
		scanf("%d", &N);
		int last = -1;
		for(int i = 0; i < N; ++i){
			int val; scanf("%1d", &val);
			if(val + 1 != last){
				printf("1"); last = val + 1;
			}
			else{
				printf("0"); last = val;
			}
		}
		puts("");
	}
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, a, b;
	cin>>n>>a>>b;
	if ((n + 1) / 2 <= (a * b + 1) / 2 && n / 2 <= a * b / 2){
		int p = 1, q = 2;
		for(int i = 1; i <= a; i++){
			for(int j = 1; j <= b; j++){
				if ((i + j) % 2 == 0){
					printf("%d%c", ((p <= n) ? p : 0), " \n"[j == b]);
					p += 2;
				}
				else{
					printf("%d%c", ((q <= n) ? q : 0), " \n"[j == b]);
					q += 2;
				}
			}
		}
	}
	else
		puts("-1");
	return 0;
}
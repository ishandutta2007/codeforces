#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){
	cin>>n>>m;
	if (m == 1 || m >= 4){puts("-1"); return;}
	if (m == 2){
		if (n <= 4) {puts("-1"); return;}
		else{
			printf("%d\n", n-1);
			for(int i = 1; i < n; i++)
				printf("%d %d\n", i, i + 1);
		}
	}
	else{
		if (n <= 3) {puts("-1"); return;}
		else if (n == 4){puts("3\n1 2\n2 3\n3 4"); return;}
		else if (n == 5){puts("5\n1 2\n2 3\n2 4\n3 4\n4 5\n"); return;}
		else{
			printf("%d\n", 2*n-4);
			for(int i = 2; i < n; i++)
				printf("%d %d\n", i-1, i);
			for(int i = 3; i < n; i++)
				printf("%d %d\n", 1, i);
			printf("2 %d\n", n);
		}
	}
}

void solve(int casi){

}

void printans(){

}


int main(){
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}
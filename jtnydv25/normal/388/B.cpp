#include <bits/stdc++.h>
using namespace std;
#define ll long long
int con[1005][1005], cnt;
void addpath(int i, int j, int k, int z){
	for(int iter = 1; iter <= z; iter++){
		int prev = i;
		for(int l = 1; l < k; l++){
			con[prev][++cnt] = 1;
			con[cnt][prev] = 1;
			prev = cnt;
		}
		con[prev][j] = con[j][prev] = 1;
	}
}

bool sol[1000005];

void get(int k){
	for(int i = 1; i <= 100; i++)
		for(int j = 1; j <= 100; j++)
			for(int k = 1; k <= 100; k++){
				sol[i * j * k] = 1;
			}

	int iter = 0;
	int mnx5 = 1000000000;
	for(int x1 = 1; x1 <= 1000; x1++)
		for(int x2 = x1; x1 + x2 <= 1000; x2++){
			int prod = x1 * x2 * x2;
			int P = prod;
			for(int x3 = x2; x1 + x2 + x3 <= 1000; x3++, P += prod){
				iter++;
				int x4 = k / P;
				int x5 = k - x1 * x2 * x3 * x4;
				if(8 + x1 + x2 + x3 + x4 <= 1000 && x5 <= 1000000 && sol[x5]){
					for(int i = 1; i <= 100; i++)
						for(int j = i; j <= 100; j++)
							for(int k = j; k <= 100; k++)
								if(i * j * k == x5 && 9 + x1 + x2 + x3 + x4 + i + j + k <= 1000){
									cnt = 8;
									addpath(1, 3, 2, x1);
									addpath(3, 4, 2, x2);
									addpath(4, 5, 2, x3);
									addpath(5, 2, 2, x4);
									addpath(1, 6, 2, i);
									addpath(6, 7, 2, j);
									addpath(7, 8, 2, k);
									addpath(8, 2, 2, 1);
									int n = cnt;
									printf("%d\n", n);
									for(int i = 1; i <= n; i++){
										for(int j = 1; j <= n; j++) printf("%s", con[i][j] ? "Y": "N");
										printf("\n");
									}
									return;
								}
				}
			}
		}
}

int main(){
	int k;
	cin >> k;
	get(k);
}
#include<stdio.h>
using namespace std;

int sq[103][103][103] , N;
void swap(int &a , int &b){a ^= b ^= a ^= b;}

int main(){
	scanf("%d" , &N);
	if(N == 1){puts("1"); return 0;}
	sq[1][1][2] = 1; sq[1][2][2] = 2; sq[1][2][1] = 3; sq[1][1][1] = 4;
	sq[2][1][1] = 5; sq[2][2][1] = 6; sq[2][2][2] = 7; sq[2][1][2] = 8;
	sq[3][1][2] = 9; sq[3][1][1] = 10; sq[3][2][1] = 11; sq[3][2][2] = 12;
	for(int i = 3 ; i <= N ; ++i)
		if(i & 1){
			int p1 = 1 , p2 = sq[i][i - 1][i - 1];
			for(int j = 1 ; j <= i ; ++j) sq[j][1][i] = --p1;
			for(int j = i - 1 ; j >= 2 ; --j) sq[i][j][i] = ++p2;
			for(int j = 2 ; j < i ; ++j)
				if(j & 1) for(int k = 1 ; k < i ; ++k) sq[k][j][i] = ++p2;
				else for(int k = i - 1 ; k ; --k) sq[k][j][i] = ++p2;
			for(int j = i ; j ; --j)
				if((j - i) & 1) for(int k = 1 ; k <= i ; ++k) sq[j][0][k] = --p1;
				else for(int k = i ; k ; --k) sq[j][0][k] = --p1;
			for(int j = 1 ; j <= i ; ++j)
				if(j & 1) for(int k = i ; k ; --k) sq[j][i][k] = ++p2;
				else for(int k = 1 ; k <= i ; ++k) sq[j][i][k] = ++p2;
			for(int p = i + 1 ; p ; --p)
				for(int x = 1 ; x <= i ; ++x)
					for(int y = 1 ; y <= i ; ++y)
						sq[x][p][y] = sq[x][p - 1][y] - p1 + 1;
			for(int x = 1 ; x <= i ; ++x)
				for(int y = 1 ; y <= i + 1 ; ++y)
					for(int z = 1 ; z * 2 <= i ; ++z)
						swap(sq[x][y][z] , sq[x][y][i + 1 - z]);
		}
		else{
			int p1 = 1 , p2 = sq[i - 1][i][i - 1];
			for(int j = 1 ; j <= i ; ++j) sq[1][j][i] = --p1;
			for(int j = i ; j ; --j)
				if((i - j) & 1) for(int k = 2 ; k < i ; ++k) sq[k][j][i] = ++p2;
				else for(int k = i - 1 ; k >= 2 ; --k) sq[k][j][i] = ++p2;
			for(int j = i ; j ; --j)
				if((i - j) & 1) for(int k = 1 ; k <= i ; ++k) sq[0][j][k] = --p1;
				else for(int k = i ; k ; --k) sq[0][j][k] = --p1;
			for(int j = 1 ; j <= i ; ++j)
				if(j & 1) for(int k = i ; k ; --k) sq[i][j][k] = ++p2;
				else for(int k = 1 ; k <= i ; ++k) sq[i][j][k] = ++p2;
			for(int p = i + 1 ; p ; --p)
				for(int x = 1 ; x <= i ; ++x)
					for(int y = 1 ; y <= i ; ++y)
						sq[p][x][y] = sq[p - 1][x][y] - p1 + 1;
		}
	for(int y = 1 ; y <= N ; ++y){
		for(int z = N ; z ; --z)
			for(int x = 1 ; x <= N ; ++x)
				printf("%d%c" , sq[x][y][z] , " \n"[x == N]);
		puts("");
	}
}
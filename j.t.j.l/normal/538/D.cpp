#include<bits/stdc++.h>

using namespace std;

const int MAXN = 111;

char a[MAXN][MAXN];
char b[MAXN][MAXN];
int n;

int check(int p, int q){
	if (p < 1 || p > n || q < 1 || q > n)
		return 1;
	if (a[p][q] != '.')
		return 1;
	else
		return 0;
}

int work(int x, int y){
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if (a[i][j] == 'o'){
				if (!check(i + x, j + y))
					return 0;
				/*
				int flag = 1;
				for(int k = 1; k <= n; k++)
					for(int l = 1; l <= n; l++)
						if (a[k][l] == 'o'){
							if (!check(k + i - x, l - j + y))
								int flag = 0;
								goto Nico;
						}
				Nico:
				if (flag){
					b[n + i - x][n + j - x] = 'x';
				}*/
			}
	return 1;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			char ch = getchar();
			while(ch != 'o' && ch != 'x' && ch != '.')
				ch = getchar();
			a[i][j] = ch;
		}
	for(int i = 1; i <= 2 * n - 1; i++)
		for(int j = 1; j <= 2 * n - 1; j++)
			b[i][j] = '.';
/*	int x,y;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if (a[i][j] == 'o'){
				x = i;
				y = j;
				break;
			}
	work(x, y);
	for(int i = 1; i <= n; i++)
		for(int j = n; j >= 1; j--)
			if (a[i][j] == 'o'){
				x = i;
				y = j;
				break;
			}
	work(x, y);
	for(int i = n; i >= 1; i--)
		for(int j = 1; j <= n; j++)
			if (a[i][j] == 'o'){
				x = i;
				y = j;
				break;
			}
	work(x, y);
	for(int i = n; i >= 1; i--)
		for(int j = n; j >= 1; j--)
			if (a[i][j] == 'o'){
				x = i;
				y = j;
				break;
			}
	work(x, y);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if (a[j][i] == 'o'){
				x = j;
				y = i;
				break;
			}
	work(x, y);
	for(int i = 1; i <= n; i++)
		for(int j = n; j >= 1; j--)
			if (a[j][i] == 'o'){
				x = j;
				y = i;
				break;
			}
	work(x, y);
	for(int i = n; i >= 1; i--)
		for(int j = 1; j <= n; j++)
			if (a[j][i] == 'o'){
				x = j;
				y = i;
				break;
			}
	work(x, y);
	for(int i = n; i >= 1; i--)
		for(int j = n; j >= 1; j--)
			if (a[j][i] == 'o'){
				x = j;
				y = i;
				break;
			}
	work(x, y);
	*/
	for(int i = 1; i <= 2 * n - 1; i++)
		for(int j = 1; j <= 2 * n - 1; j++){
			if (work(i - n, j - n))
				b[i][j] = 'x';
		}
	b[n][n] = 'o';
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)	
			if (a[i][j] == 'o'){
				for(int k = 1; k <= n; k++)
					for(int l = 1; l <= n; l++)
						if (a[k][l] == 'x' && b[n - i + k][n - j + l] == 'x')
							a[k][l] = '.';
			}
	int Nico = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if (a[i][j] == 'x')
				Nico = 0;
	if (Nico){
		puts("YES");
		for(int i = 1; i <= 2 * n - 1; i++){
			for(int j = 1; j <= 2 *n - 1; j++)
				printf("%c", b[i][j]);
			puts("");
		}
	}
	else
		puts("NO");
	return 0;
}
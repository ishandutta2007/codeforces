#include <cstdio>

int mat[100][100];
int r;
int c;

int max(int A, int B) { return ((A>B)?A:B); }

int calc(int a, int b)
{
	if ((b-a)&1)
		return (b-a);
	int m = (a+b)>>1;
	for (int i = a;i < m;i++) for (int j = 0;j < c;j++) if (mat[i][j] != mat[b-i-1][j])
		return (b-a);
	return max(calc(a, m), calc(m, b));
}

int main()
{
	scanf("%d%d", &r, &c);
	for (int i = 0;i < r;i++) for (int j = 0;j < c;j++)
		scanf("%d", &mat[i][j]);
	printf("%d\n", calc(0, r));
	return 0;
}
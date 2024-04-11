#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#define N 555
#define M 33
int n,m,curl,f[N][M][M];
int a[M][M];
struct cell {
	int x,y;
	
	bool operator <(const cell& A) const {
		return f[curl][x][y] < f[curl][A.x][A.y];
	}
	
	bool operator >(const cell& A) const {
		return f[curl][x][y] > f[curl][A.x][A.y];
	}
} fath[N][M][M],lu[M][M],ru[M][M],ld[M][M],rd[M][M];
char w[N][N];


inline void calc(int l) {
	for (char x='a';x<='z';x++)
		for (char y='a';y<='z';y++) {
			if (x == y) {
				a[x-'a'][y-'a'] = (int) 1e8;
				continue;
			}
			int ans = 0;
			for (int i=0;i<m;i++)
				if (i&1) {
					if (w[l][i] != y) ans++;
				} else {
					if (w[l][i] != x) ans++;
				}
			a[x-'a'][y-'a'] = ans;
		}
}

inline void prep(int l) {
	curl = l;
	for (int i=0;i<26;i++)
		for (int j=0;j<26;j++) {
			lu[i][j] = (cell) {i,j};
			if (i && lu[i][j] > lu[i-1][j]) lu[i][j] = lu[i-1][j]; 
			if (j && lu[i][j] > lu[i][j-1]) lu[i][j] = lu[i][j-1]; 
		}
	for (int i=25;i>=0;i--)
		for (int j=0;j<26;j++) {
			ru[i][j] = (cell) {i,j};
			if (i < 25 && ru[i][j] > ru[i+1][j]) ru[i][j] = ru[i+1][j]; 
			if (j && ru[i][j] > ru[i][j-1]) ru[i][j] = ru[i][j-1]; 
		}
	for (int i=25;i>=0;i--)
		for (int j=25;j>=0;j--) {
			rd[i][j] = (cell) {i,j};
			if (i < 25 && rd[i][j] > rd[i+1][j]) rd[i][j] = rd[i+1][j]; 
			if (j < 25 && rd[i][j] > rd[i][j+1]) rd[i][j] = rd[i][j+1]; 
		}
	for (int i=0;i<26;i++)
		for (int j=25;j>=0;j--) {
			ld[i][j] = (cell) {i,j};
			if (i && ld[i][j] > ld[i-1][j]) ld[i][j] = ld[i-1][j]; 
			if (j < 25 && ld[i][j] > ld[i][j+1]) ld[i][j] = ld[i][j+1]; 
		}
}

int main(void) {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	
	scanf("%d%d\n",&n,&m);
	for (int i=0;i<n;i++) gets(w[i]);
	
	calc(0);
	for (int x=0;x<26;x++)
		for (int y=0;y<26;y++)
			f[0][x][y] = a[x][y];
	prep(0);
	for (int i=1;i<n;i++) {
		calc(i);
		for (int x=0;x<26;x++)
			for (int y=0;y<26;y++) {
				cell p = (cell) {0,0};
				if (x && y && p > lu[x-1][y-1]) p = lu[x-1][y-1];  
				if (x<25 && y && p > ru[x+1][y-1]) p = ru[x+1][y-1];  
				if (x && y<25 && p > ld[x-1][y+1]) p = ld[x-1][y+1];  
				if (x<25 && y<25 && p > rd[x+1][y+1]) p = rd[x+1][y+1];
				f[i][x][y] = f[i-1][p.x][p.y] + a[x][y];
				fath[i][x][y] = p;  
			}
		prep(i);
	}
	
	cell ans = lu[25][25];
	printf("%d\n",f[n-1][ans.x][ans.y]);
	
	curl = n-1;
	while (curl >= 0) {
		for (int i=0;i<m;i++) 
			if (i&1) w[curl][i] = 'a'+ans.y;
			else w[curl][i] = 'a'+ans.x;
		ans = fath[curl][ans.x][ans.y];
		curl--;
	}
		
	for (int i=0;i<n;i++) puts(w[i]);
		
	return 0;
}
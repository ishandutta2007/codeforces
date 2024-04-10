#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define xx first
#define yy second

typedef long long ll;
typedef pair<int,int> pii;

const int N = 100010; 
int n, m, tot; 
bool f[4][N]; 
int main() { 
	scanf("%d%d", & n, & m); 
	for (int i = 1; i <= m; i ++) { 
		int x, y; 
		scanf("%d%d", & x, & y); 
		if (f[x][y]) { 
			for (int i =- 1; i <= 1; i ++) tot -= f[x - 1][y + i] + f[x + 1][y + i]; 
			f[x][y] = 0; 
		} 
		else { 
			for (int i =- 1; i <= 1; i ++) tot += f[x - 1][y + i] + f[x + 1][y + i]; 
			f[x][y] = 1; 
		} 
		puts(tot ? "No" : "Yes"); 
	} 
}
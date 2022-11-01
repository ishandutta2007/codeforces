#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, x, y, z;
map<int, map<int, map<int, int> > > mp;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d%d%d", &x, &y, &z), mp[x][y][z] = i;
	int lastx = 0;
 	for(auto &x : mp){
 		int lasty = 0;
		for(auto &y : x.second){
			int lastz = 0;
			for(auto &z : y.second){
				if(lastz) printf("%d %d\n", lastz, z.second), lastz = 0;
				else lastz = z.second;
			}
			if(lastz){
				if(lasty) printf("%d %d\n", lastz, lasty), lasty = 0;
				else lasty = lastz;
			}
		}
		if(lasty){
			if(lastx) printf("%d %d\n", lasty, lastx), lastx = 0;
			else lastx = lasty;
		}
	}
}
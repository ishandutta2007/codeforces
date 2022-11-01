#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
vector<int> v;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int x = n;
		for(int i = 1;i <= n;i++){
			int y = 0;
			for(int j = 0;j < 4;j++){
				if(j == 0){
					if(x) x--;
					else y++;
				}
				if(j == 1 || j == 2){
					if(x) x--;
				}
				if(j == 3){
					if(x) x--;
					y += 8;
				}
			}
			v.push_back(y);
		}
		while(v.size()) printf("%d", v.back()), v.pop_back();
		puts("");
	}
}
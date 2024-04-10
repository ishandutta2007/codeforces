#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, m;
const int a[12] = {0,2,3,5,7,11,13,17,19,23,29,31};
int c[12], x;
int b[maxn];

vector<int> v[20];

int main(){
	scanf("%d", &t);
	while(t--){
		m = 0;
		memset(c, 0, sizeof(c));
		scanf("%d", &n);
		for(int i = 1;i <= n;i++){
			scanf("%d", &x);
			for(int j = 1;j <= 11;j++){
				if(x % a[j] == 0){
					if(!c[j]) c[j] = ++m;
					b[i] = c[j];
					break;
				}
			}
		}
		printf("%d\n", m);
		for(register int i = 1;i <= n;i++) printf("%d ", b[i]);
		puts("");
	}
}
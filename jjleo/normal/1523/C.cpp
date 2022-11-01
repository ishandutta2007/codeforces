#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
vector<int> v[maxn];
int x;
int sk[maxn];
int top;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		top = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d", &x);
			v[i].clear();
			if(!top) v[i].push_back(1), sk[++top] = i;
			else if(x == 1){
				v[i] = v[i - 1];
				v[i].push_back(1);
				sk[++top] = i;
			}else{
				while(top && v[sk[top]].back() != x - 1) top--;
				v[i] = v[sk[top]];
				v[i][v[i].size() - 1]++;
				sk[top] = i;
			}
			for(int j = 0;j < v[i].size();j++){
				if(j) printf(".");
				printf("%d", v[i][j]);
			}
			puts(""); 
		}
	} 
}
#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
set<int> st;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		st.clear();
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 1;i <= n;i++){
			for(int j = 1;j < i;j++){
				st.insert(a[i] - a[j]);
			}
		}
		printf("%d\n", st.size());
	}
}
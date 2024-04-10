#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int sg[maxn];
int a[maxn];
set<int> st;

int main(){
	scanf("%d", &t);
	for(int i = 1, j = 2;i < 30;i++,j *= 2) if(i & 1) st.insert(j);
	while(t--){
		scanf("%d", &n);
		puts(st.find(n) != st.end() || (n & 1) ? "Bob" : "Alice"); 
	}
}
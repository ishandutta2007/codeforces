#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
char s[maxn];
int a[maxn], cnt;
vector<int> v;

int main(){
	scanf("%d%s", &n, s + 1);
	for(int i = 1;i <= n;i++){
		if(s[i] == 'B') v.push_back(i);
	}
	if(!(v.size() & 1)){
		for(int i = 0;i < v.size();i += 2){
			for(int j = v[i];j < v[i + 1];j++) a[++cnt] = j;
		}
		printf("%d\n", cnt);
		for(int i = 1;i <= cnt;i++) printf("%d ", a[i]);
		return 0;
	}
	v.clear();
	for(int i = 1;i <= n;i++){
		if(s[i] == 'W') v.push_back(i);
	}
	if(!(v.size() & 1)){
		for(int i = 0;i < v.size();i += 2){
			for(int j = v[i];j < v[i + 1];j++) a[++cnt] = j;
		}
		printf("%d\n", cnt);
		for(int i = 1;i <= cnt;i++) printf("%d ", a[i]);
		return 0;
	}
	printf("-1");
		
}
#include <bits/stdc++.h>
#define maxn 5005

using namespace std;

int t;
int n;
int a[maxn];
int b, c;
vector<int> v;
bool f[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n * 2;i++) scanf("%d", &a[i]);
		int x = 1; 
		bool tag = true;
		b = c = 0;
		v.clear();
		while(x <= n * 2){
			int i = x + 1;
			for(;i <= n * 2;i++){
				if(a[i] > a[x]) break;
			}
			i--;
			v.push_back(i - x + 1);
			x = i + 1;
		} 
		for(int i = 1;i <= n;i++) f[i] = false;
		f[0] = 1;
		for(int i = 0;i < v.size();i++){
			for(int j = n;j;j--){
				if(j - v[i] >= 0) f[j] |= f[j - v[i]];
			}
		}
		puts(f[n] ? "YES" : "NO");
	}
}
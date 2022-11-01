#include <bits/stdc++.h>
#define maxn 100086
using namespace std;

int t;
int n;
char a[maxn], b[maxn];
vector<int> v;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		scanf("%s%s", a + 1, b + 1);
		int l = 1, r = n;
		v.clear();
		bool tag = false;
		for(int i = n;i;i--){
			if(!tag){
				if(a[r] == b[i]){
					r--;
					continue;
				}
				if(a[l] == b[i]){
					v.push_back(1);
				}
				v.push_back(i);
				tag = true;
				l++;
			}else{
				if(a[l] != b[i]){
					l++;
					continue;
				}
				if(a[r] != b[i]){
					v.push_back(1);
				}
				v.push_back(i);
				tag = false;
				r--;
			}

		}
		printf("%d", v.size());
		for(int i = 0;i < v.size();i++) printf(" %d", v[i]);
		puts("");
	}
}
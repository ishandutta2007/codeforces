#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int a[4], b[4];
vector<int> v;

int main(){
	for(int i = 0;i < 4;i++) scanf("%d", &b[i]), n += b[i];
	for(int i = 0;i < 4;i++){
		for(int j = 0;j < 4;j++) a[j] = b[j];
		if(!a[i]) continue;
		v.clear(), v.push_back(i), a[i]--;
		for(int j = 2;j <= n;j++){
			if(v.back() - 1 >= 0){
				if(a[v.back() - 1]){
					a[v.back() - 1]--, v.push_back(v.back() - 1);
				}else{
					if(v.back() + 1 < 4 && a[v.back() + 1]){
						a[v.back() + 1]--, v.push_back(v.back() + 1);
					}else{
						break;
					}
				}
			}else{
				if(v.back() + 1 < 4 && a[v.back() + 1]){
					a[v.back() + 1]--, v.push_back(v.back() + 1);
				}else{
					break;
				}
			}
		}
		if(v.size() == n){
			puts("YES");
			for(int j = 0;j < v.size();j++) printf("%d ", v[j]);
			return 0;
		}
	}
	printf("NO");
}
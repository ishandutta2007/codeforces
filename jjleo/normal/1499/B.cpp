#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
char s[maxn];
int n;
vector<int> v;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		for(int i = 0;i <= n;i++){
			v.clear();
			for(int j = 1;j <= i;j++) if(s[j] == '1') v.push_back(j);
			for(int j = i + 1;j <= n;j++) if(s[j] == '0') v.push_back(j);
			bool tag = false;
			for(int j = 1;j < v.size() && !tag;j++) if(v[j] == v[j - 1] + 1) tag = true;
			if(!tag){
				puts("YES");
				break;
			}
			if(i == n) puts("NO");
		}
	}
}
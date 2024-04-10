#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int a[maxn];
char s[maxn];

vector<pair<int, pair<int, int> > > v;  

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", &a[i]);
		for(int j = 1;j < i;j++){
			v.push_back({abs(a[i] - a[j]), {a[i] > a[j] ? i : j, a[i] > a[j] ? j : i}});
		}
	}
	sort(v.begin(), v.end());
	while(!v.empty()){
		printf("? %d %d\n", v.back().second.first, v.back().second.second);
		fflush(stdout);
		scanf("%s", s);
		if(s[0] == 'Y') return printf("! %d %d\n", v.back().second.first, v.back().second.second), 0;
		v.pop_back();
	}
	puts("! 0 0");
	
}
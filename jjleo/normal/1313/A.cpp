#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, a[10], ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &a[1], &a[2], &a[3]), ans = 0;
		if(a[1]) ans++, a[1]--;
		if(a[2]) ans++, a[2]--;
		if(a[3]) ans++, a[3]--;
		sort(a + 1, a + 3 + 1), reverse(a + 1, a + 1 + 3);
		if(a[1] && a[2]) ans++, a[1]--, a[2]--;
		if(a[1] && a[3]) ans++, a[1]--, a[3]--;
		if(a[2] && a[3]) ans++, a[2]--, a[3]--;
		if(a[1] && a[2] && a[3]) ans++;
		printf("%d\n", ans);
	}
}
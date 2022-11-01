#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;

inline int query(int x, int y, int z){
	printf("? %d %d %d\n", x, y, z), fflush(stdout);
	scanf("%d", &x);
	return x; 
}

int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 3;i <= n;i++) a[i] = query(1, 2, i);
		if(*max_element(a + 3, a + n + 1) == *min_element(a + 3, a + n + 1)){
			int mx = *max_element(a + 3, a + n + 1);
			for(int i = 2;i <= n;i++) if(i ^ 3) a[i] = query(1, 3, i);
			swap(a[2], a[3]);
			if(*max_element(a + 3, a + n + 1) == mx) printf("! %d %d\n", 1, 2), fflush(stdout);
			else{
				int pos = max_element(a + 3, a + n + 1) - a;
				if(pos == 3) pos = 2;
				printf("! %d %d\n", 3, pos), fflush(stdout);
			}
		}else{
			int x = max_element(a + 3, a + n + 1) - a;
			pair<int, int> p = {-1, 0};
			set<int> st;
			for(int i = 2;i <= n;i++) if(i ^ x){
				int val = query(1, x, i);
				st.insert(val);
				p = max(p, {val, i});
			}
			if(st.size() == 1) printf("! %d %d\n", x, 1), fflush(stdout);
			else printf("! %d %d\n", x, p.second), fflush(stdout);
		}
	}
}
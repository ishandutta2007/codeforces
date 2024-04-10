#include <bits/stdc++.h>
#define maxn 1000086
using namespace std;

typedef long long ll; 

int n;
int a[maxn], b[maxn], cnt;
int id;
ll ans;
int sk[maxn], top;
int l[maxn], r[maxn], num[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", &a[i]);
		if(a[i] > a[id]) id = i;	
	}
	for(int i = id;i <= n;i++) b[++cnt] = a[i];
	for(int i = 1;i <= id;i++) b[++cnt] = a[i];
	memcpy(a, b, sizeof(b));
	++n;
	for(int i = 1;i <= n;i++){
		while(top && a[sk[top]] <= a[i]) --top;
		//printf("%d %d %d--\n", i, a[i], a[sk[top]]); 
		if(top) l[i] = sk[top];
		sk[++top] = i;
	}
	top = 0;
	for(int i = n;i;i--){
		while(top && a[sk[top]] < a[i]) --top;
		if(top){
			if(a[i] == a[sk[top]]) num[i] = num[sk[top]] + 1, r[i] = r[sk[top]];
			else r[i] = sk[top];
		}
		//printf("%d %d %d %d--\n", i, l[i], r[i], num[i]);
		sk[++top] = i;
	}
	for(int i = 1;i <= n;i++){
		if(l[i]) ++ans;
		if(r[i]) ++ans;
		if(l[i] == 1 && r[i] == n) ans--;//debug: 
		ans += num[i]; 
	}
	printf("%lld", ans - num[1]);//debug: 
}
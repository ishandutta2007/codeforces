#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[maxn], sum;
struct Node{
	int a, b, c;
};

vector<Node> v;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		sum = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), sum += a[i];
		if(sum % n){
			puts("-1");
			continue;
		}
		sum /= n;
		v.clear();
		for(int i = 2;i <= n;i++){
			v.push_back((Node){1, i, (i - a[i] % i) % i});
			v.push_back((Node){i, 1, (a[i] + i - 1) / i});
		}
		for(int i = 2;i <= n;i++) v.push_back((Node){1, i, sum});
		printf("%d\n", v.size());
		for(int i = 0;i < v.size();i++) printf("%d %d %d\n", v[i].a, v[i].b, v[i].c);
	}
}
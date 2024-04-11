#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MAXN = 200005;

int n, m, ta, tb, k;
int a[MAXN], b[MAXN];

int main(){
	cin >> n >> m >> ta >> tb >> k;
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	for(int i=0; i<m; i++) scanf("%d",&b[i]);
	int ptrA = 0;
	for(int i=0; i<m; i++){
		if(ptrA < n && a[ptrA] + ta <= b[i]){
			ptrA++;
			k--;
			if(k == -1){
				cout << b[i] + tb << endl;
				return 0;
			}
		}
	}
	puts("-1");
}
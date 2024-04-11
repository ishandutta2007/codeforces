#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

int a[1005], n, q;

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i != j) scanf("%*d");
			else scanf("%d",&a[i]);
		}
	}
	int ret = 0;
	for(int i=0; i<n; i++) ret ^= a[i];
	scanf("%d",&q);
	for(int i=0; i<q; i++){
		int t;
		scanf("%d",&t);
		if(t != 3){
			scanf("%*d");
			ret ^= 1;
		}
		else{
			printf("%d",ret);
		}
	}
}
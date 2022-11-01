#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		vector<int> v;
		while(n) v.push_back(n % 10), n /= 10;
		if(v.size() == 2) printf("%d\n", v[0]);
		else printf("%d\n", *min_element(v.begin(), v.end())); 
	}
}
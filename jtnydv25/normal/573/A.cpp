#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

set<int> st;
int main(){
	int x;
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		while(x % 2 == 0) x /= 2;
		while(x % 3 == 0) x /= 3;
		st.insert(x);
	}
	if(st.size()==1) printf("Yes\n");
	else printf("No\n");
}
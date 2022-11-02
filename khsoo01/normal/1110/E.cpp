#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a, b;

int main()
{
	scanf("%d",&n);
	for(int i=1,j=0;i<=n;i++) {
		int T;
		scanf("%d",&T);
		a.push_back(T-j);
		j = T;
	}
	for(int i=1,j=0;i<=n;i++) {
		int T;
		scanf("%d",&T);
		b.push_back(T-j);
		j = T;
	}
	sort(a.begin()+1, a.end());
	sort(b.begin()+1, b.end());
	for(int i=0;i<n;i++) {
		if(a[i] != b[i]) {puts("No"); return 0;}
	}
	puts("Yes");
}
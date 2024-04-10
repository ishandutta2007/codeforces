#include<bits/stdc++.h>
using namespace std;
const int N = 200005;

int n, m, c[N], l[N];
vector<pair<int,int> > ans;

int main()
{
	scanf("%d%d",&n,&m);
	if(n - m == 2) {
		puts("3\n1 2\n1 3");
		for(int i=4;i<=n;i++) printf("2 %d\n",i);
	}
	else {
		for(int i=0;i<m;i++) l[i] = 1;
		for(int i=2;i<=n-m;i++) {
			ans.push_back({i, l[(i-2)%m]});
			l[(i-2)%m] = i;
			c[(i-2)%m]++;
		}
		int T = 0;
		for(int i=n-m+1;i<=n;i++) {
			ans.push_back({i, l[T]});
			T = min(T+1, m-1);
		}
		printf("%d\n",c[0]+c[1]+2);
		for(auto &X : ans) printf("%d %d\n",X.first,X.second);
	}
}
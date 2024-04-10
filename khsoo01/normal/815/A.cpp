#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int h, w, a[105][105];
vector<pair<int,int> > ans;

int main()
{
	scanf("%d%d",&h,&w);
	for(int i=1;i<=h;i++) {
		for(int j=1;j<=w;j++) {
			scanf("%d",&a[i][j]);
		}
	}
	if(w >= h) {
		for(int i=1;i<=h;i++) {
			int mn = inf;
			for(int j=1;j<=w;j++) {
				mn = min(mn, a[i][j]);
			}
			for(int j=0;j<mn;j++) ans.push_back({0, i});
			for(int j=1;j<=w;j++) {
				a[i][j] -= mn;
			}
		}
		for(int i=1;i<=w;i++) {
			for(int j=2;j<=h;j++) {
				if(a[j][i] != a[j-1][i]) {puts("-1"); return 0;}
			}
			for(int j=0;j<a[1][i];j++) ans.push_back({1, i});
		}
		printf("%d\n",ans.size());
		for(auto &T : ans) {
			int A, B; tie(A, B) = T;
			printf(A ? "col " : "row ");
			printf("%d\n",B);
		}
	}
	else {
		for(int i=1;i<=w;i++) {
			int mn = inf;
			for(int j=1;j<=h;j++) {
				mn = min(mn, a[j][i]);
			}
			for(int j=0;j<mn;j++) ans.push_back({0, i});
			for(int j=1;j<=h;j++) {
				a[j][i] -= mn;
			}
		}
		for(int i=1;i<=h;i++) {
			for(int j=2;j<=w;j++) {
				if(a[i][j] != a[i][j-1]) {puts("-1"); return 0;}
			}
			for(int j=0;j<a[i][1];j++) ans.push_back({1, i});
		}
		printf("%d\n",ans.size());
		for(auto &T : ans) {
			int A, B; tie(A, B) = T;
			printf(A ? "row " : "col ");
			printf("%d\n",B);
		}
	}
}
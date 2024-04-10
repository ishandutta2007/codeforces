#include<bits/stdc++.h>
using namespace std;
int n;
char ipt[10010];
bool dt[10005][2];
vector<string> ans;

int main()
{
	scanf("%s",ipt+1);
	n = strlen(ipt+1);
	dt[n-1][0] = true;
	dt[n-2][1] = true;
	for(int i=n-3;i>5;i--) {
		for(int k=0;k<2;k++) {
			if(dt[i+k+2][k^1]) {dt[i][k] = true; continue;}
			if(!dt[i+k+2][k]) continue;
			bool flag = true;
			for(int j=0;j<k+2;j++) {
				if(ipt[i+j] != ipt[i+k+2+j]) {
					flag = false; break;
				}
			}
			if(!flag) dt[i][k] = true;
		}
	}
	for(int i=n-1;i>5;i--) {
		for(int k=0;k<2;k++) {
			if(!dt[i][k]) continue;
			string tmp;
			for(int j=0;j<k+2;j++) tmp += ipt[i+j];
			ans.push_back(tmp);
		}
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) {
		cout << ans[i] << endl;
	}
}
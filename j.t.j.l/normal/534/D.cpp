#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

typedef pair<int, int> PII;

int mm[MAXN];
vector<PII> E[5];
int cnt[5];
int a[MAXN], b[MAXN];
vector<int> F[MAXN];

int main(){
	int n;
	cin>>n;
	for(int i = 0; i < 3; i++)
		cnt[i] = 0;
	for(int i = 0; i < n; i++)
		mm[i] = 0, F[i].clear();
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		cnt[a[i]%3]++;
		E[a[i]%3].push_back(PII(a[i], i));
		mm[a[i]]++;
		F[a[i]].push_back(i);
	}
	int flag = 1;
	vector<int> ans;
	ans.clear();
	int now = 0;
	for(int i = 0; i < n; i++){
		while (now >= 0 && !mm[now]){
			now -= 3;
		}
		if (now < 0){
			flag = 0;
			break;
		}
		if (mm[now] == 0){
			flag = 0;
			break;
		}
		mm[now]--;
		ans.push_back(F[now][mm[now]]);
		now++;
	}
	if (flag){
		puts("Possible");
		for(int i = 0; i < n; i++)
			printf("%d%c", ans[i], " \n"[i == n-  1]);
	}
	else
		puts("Impossible");
	return 0;
}
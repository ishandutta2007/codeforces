#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int MAXN = 1e3 + 10;
const int MM = 1e9 + 7;

char s[MAXN];
int a[MAXN], vis[MAXN];

int main(){
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		vis[i] = 0;
	}
	int tmp = 0;
	int flag = 0;
	int cnt = 0;
	while(tmp < n){
		cnt++;
		if (!flag)
		for(int i = 1; i <= n; i++){
			if (!vis[i] && tmp >= a[i]){
				vis[i] = 1;
				tmp++;
			}
		}
		else{
			for(int i = n; i >= 1; i--)
				if (!vis[i] && tmp >= a[i]){
					vis[i] = 1;
					tmp++;
				}
		}
		flag = 1 - flag;
	}
	cout<<cnt-1<<endl;
	return 0;
}
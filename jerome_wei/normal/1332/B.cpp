#include<bits/stdc++.h>
using namespace std;
int n;
int prime[] = {2,3,5,7,11,13,17,19,23,29,31};

int a[1110];
vector<int> s[11];
int main(){
	int t;cin >> t;
	while(t--){
		cin >> n;
		for(int i=0;i<11;i++)s[i].clear();
		for(int i=1;i<=n;i++){
			int x;scanf("%d",&x);
			for(int j=0;j<11;j++){
				if(x%prime[j]==0){
					s[j].push_back(i);break;
				}
			}
		}
		int ans=0;
		for(int i=0;i<11;i++){
			if(s[i].size())++ans;
			for(size_t j=0;j<s[i].size();j++){
				a[s[i][j]]=ans;
			}
		}cout << ans << endl;
		for(int i=1;i<=n;i++)printf("%d ",a[i]);
		puts("");
	}
}
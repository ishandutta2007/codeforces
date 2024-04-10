#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll mod = 1e9+7;
const int mn = 3e5+10;

int av[mn];
void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int ans=-1;
	for(int i=0;i<n-1;i++){
		if(s[i+1]>s[i]){
			ans=i;
			break;
		}
	}
	if(ans==-1){
		ans=n-1;
	}
	if(n>=2&&s[0]==s[1])ans=0;
	for(int i=0;i<=ans;i++)printf("%c",s[i]);
	for(int i=ans;i>=0;i--)printf("%c",s[i]);
	printf("\n");
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int tc;
	cin>>tc;
	while(tc--){
		solve();
	}
}
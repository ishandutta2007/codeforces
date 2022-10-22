#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll mod = 1e9+7;
const int mn = 3e5+10;

int eval(int x,int b){
	int num=x>>(b+1);
	int ex=x%(1<<(b+1))+1;
	return (num<<b) + min(ex,1<<b);
}

void solve(){
	int a,b;
	cin>>a>>b;
	int ans=INT_MAX;
	for(int i=0;i<30;i++){
		ans=min(ans,eval(b,i)-eval(a-1,i));
	}
	printf("%d\n",ans);
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
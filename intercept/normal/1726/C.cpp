#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=2e5+9;
int n,m,top;
int t[M],vis[M];
char s[M];
void work(){
	cin>>n>>(s+1);
	n*=2;
	top=0;
	for(int i=0;i<=n;++i)vis[i]=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='('){
			vis[t[top]]=1;
			t[++top]=i;
		}
		else top--;
	}
	int ans=0;
	for(int i=0;i<=n;++i)ans+=vis[i];
	cout<<ans<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
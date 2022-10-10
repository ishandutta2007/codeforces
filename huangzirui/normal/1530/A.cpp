#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0;do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=1000010;
int i,j,k,n,m,T,a[maxn];
int main(){
	//freopen("A.in","r",stdin);
	//freopen("A.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int ans=0;
		while(n){
			ans=max(ans,n%10);
			n/=10;
		}cout<<ans<<endl;
	}
}
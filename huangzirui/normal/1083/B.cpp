#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0;do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=500010;
int i,j,k,n,m,T;
string s1,s2;
int main(){
	cin>>n>>m;
	cin>>s1>>s2;
	ll S=1,ans=0;
	for(i=0;i<n;i++){
		S*=2;
		if(s1[i]=='b')--S;
		if(s2[i]=='a')--S;
		if(S>=m){
			ans+=m;
			ans+=1ll*m*(n-i-1);
			cout<<ans<<endl;
			return 0;
		}ans+=S;
		//cout<<"ans="<<ans<<endl;
	}cout<<ans<<endl;
	//cout<<n<<endl;
	return 0;
}
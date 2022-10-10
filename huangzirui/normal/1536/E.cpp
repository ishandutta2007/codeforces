#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}


const int mod=1e9+7;
int i,j,k,n,m,T;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>T;
	while(T--){
		string S;
		cin>>n>>m;
		bool is=0;ll num=1;
		for(i=1;i<=n;i++){
			cin>>S;
			for(j=0;j<S.size();j++)if(S[j]=='0')is=1;else{num<<=1,num%=mod;}
		}
		if(is);else num--;
		cout<<num<<endl;
	}
}
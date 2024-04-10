#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
int i,j,k,n,m,T;
string S;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>T;
	while(T--){
		cin>>S;
		n=S.size();
		bool f=false;
		for(int i=0;i<=n;i++){
			int last=-2;bool b=true;
			for(int j=0;j<i;j++){
				if(S[j]=='1'){
					if(j-last<=1)b=false;
					last=j;
				}
			}
			for(int j=i;j<n;j++){
				if(S[j]=='0'){
					if(j-last<=1)b=false;
					last=j;
				}
			}f|=b;
		}
		if(f)puts("YES");
		else puts("NO");
	}
}
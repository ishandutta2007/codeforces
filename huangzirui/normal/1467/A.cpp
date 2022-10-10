#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}

int i,j,k,n,m,T;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n==1)cout<<9<<endl;
		else if(n==2)cout<<98<<endl;
		else{
			cout<<98;
			int x=9;
			for(i=1;i<=n-2;i++){
				printf("%d",x);
				x++;if(x==10)x=0;
			}
			puts("");
		}
	}
}
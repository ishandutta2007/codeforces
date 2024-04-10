#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,x,y;
bool b[66666];

int main(){
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
    	cin>>n>>m;
    	if(n==4&&m==3){
    		cout<<"-1\n";continue;
		}
		memset(b,0,sizeof(b));
		if(m!=(n-1)){
			cout<<n-1<<' '<<m<<'\n';
			b[n-1]=b[m]=1;
			for(i=n-1;i>=0;i--){
				if(b[i])continue;
				if(b[i^(n-1)]){
					x=i;y=0;
				}
				else{
					x=i;y=(n-1-i);
				}
				b[x]=b[y]=1;
				cout<<x<<' '<<y<<'\n';
			}
		}
		else{
			cout<<n-1<<' '<<n-2<<'\n';
			cout<<n-3<<' '<<1<<'\n';
			cout<<0<<' '<<2<<'\n';
			for(i=3;;i++){
				j=n-1-i;
				if(j<=i)break;
				cout<<i<<' '<<j<<'\n';
			}
		}
	}
}
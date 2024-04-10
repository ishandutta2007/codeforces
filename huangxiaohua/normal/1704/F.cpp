#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,k,n,m,t,cur,res,f[1050],mex[1050];
string s;

void init(){
	for(i=2;i<=1000;i++){
		memset(mex,0,sizeof(mex));
		for(j=0;j+2<=i;j++){
			mex[f[j]^f[i-2-j]]=1;
		}
		for(j=0;;j++){
			if(!mex[j]){
				//cout<<i<<' '<<j<<endl;
				f[i]=j;break;
			}
		}
	}
}

int fuck(int x){
	if(x<=666)return f[x];
	x=x-((x-666)/34)*34;
	return f[x];
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	init();
	cin>>t;
	while(t--){
		cin>>n>>s;
		k=0;
		for(auto i:s){
			if(i=='R')k++;
			else k--;
		}
		if(k){
			if(k>0)cout<<"Alice\n";
			else cout<<"Bob\n";
			continue;
		}
		char lst='x';
		res=0;k=1;
		for(i=1;i<=n;i++){
			if(i!=n&&s[i]!=s[i-1]){
				k++;
			}
			else{
				res^=fuck(k);
				k=1;
			}
		}
		if(res)cout<<"Alice\n";
		else cout<<"Bob\n";
	}
}
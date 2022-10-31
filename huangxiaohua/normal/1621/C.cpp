#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

int i,j,k,n,m,t,a[10050],it,b[10050],cur,lst,nxt[10050];
bool vis[10050];

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		cin>>n;
		cur=0;
		for(i=1;i<=n;i++){
			if(vis[i])continue;
			it=0;
			lst=cur+1;
			while(1){
				cout<<"? "<<i<<endl;
				cur++;
				cin>>k;
				if(vis[k])break;
				b[++it]=k;
				vis[k]=1;
			}
			
			for(j=1;j<it;j++){
				a[b[j]]=b[j+1];
			}
			a[b[it]]=b[1];
		}
		cout<<"! "<<endl;
		for(i=1;i<=n;i++){
			cout<<a[i]<<' ';
		}
		cout<<endl;
	}
}
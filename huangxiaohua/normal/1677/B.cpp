#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,p[1005000],res[1005000],it,sb[1005000],cur;
char s[1005000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m>>s+1;
		memset(p,0,n*m*4+50);
		memset(sb,0,n*m*4+50);
		memset(res,0,n*m*4+50);
		k=-1;
		it=0;
		cur=0;
		for(i=1;i<=n*m;i++){
			p[i]=p[i-1];
			if(s[i]=='1')p[i]++;
			it++;
			if(it>m)it=1;
			if(k==-1&&s[i]=='1')k=it;
			if(k!=-1&&i>=m&&p[i]==p[i-m])sb[it]--;
			if(k==it)cur++;
			res[i]=cur+sb[it];
			//printf("NMSL%d %d %d %d\n",i,it,k,sb[i]);
		}
		k=0;
		memset(p,0,n*m*4+50);
		for(i=1;i<=n*m;i++){
			if(s[i]=='1'&&!p[i%m]){
				k++;p[i%m]=1;
			}
			res[i]+=k;
		}
		for(i=1;i<=n*m;i++)cout<<res[i]<<' ';
		cout<<'\n';
	}
}
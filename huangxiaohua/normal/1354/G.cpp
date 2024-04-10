#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,shi[1050],v[1050],it,q[1050],l,r,md,res,cur;
string s;

bool ask(int m){
	int i;string s;
	printf("? %d %d\n",m,m);
	for(i=1;i<=m;i++)printf("%d ",v[i]);
	puts("");
	for(i=1;i<=m;i++)printf("%d ",q[i]);
	cout<<endl;cin>>s;
	return (s[0]=='E');
}

int main(){
	cin>>t;
	while(t--){
		cin>>n>>i;
		
		mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()+1);
		uniform_int_distribution<int>lim(1,n);
		memset(shi,0,sizeof(shi));
		
		cur=1;it=0;
		for(i=1;i<=25;i++){
			j=lim(rng);if(j==cur){i--;continue;}
			printf("? 1 1\n%d\n%d",cur,j);cout<<endl;
			cin>>s;
			if(s[0]=='S')cur=j;
		}
		v[++it]=cur;shi[cur]=1;

		while(1){
			m=min(n-it,it);k=0;
			for(i=1;i<=n&&k<m;i++){
				if(!shi[i])q[++k]=i;
			}
			if(ask(m)){
				for(i=1;i<=m;i++)v[++it]=q[i],shi[q[i]]=1;
			}
			else{
				l=1;r=m;res=114514;
				while(l<=r){
					md=(l+r)/2;
					if(ask(md))l=md+1;
					else res=min(res,md),r=md-1;
				}
				break;
			}
		}
		printf("! %d\n",q[res]);cout<<endl;
	}
}
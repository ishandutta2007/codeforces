#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,sb[66],num,it,tmp;
char res[105][105],s[105][105],mp[66];

int main() {
	ios::sync_with_stdio(0);
	for(i=1;i<=10;i++){
		mp[i]='0'+i-1;
	}
	for(i=11;i<=36;i++){
		mp[i]='a'+i-11;
	}
	for(i=37;i<=62;i++){
		mp[i]='A'+i-37;
	}
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		num=0;
		for(i=1;i<=n;i++){
			cin>>s[i]+1;
			for(j=1;j<=m;j++){
				if(s[i][j]=='R'){num++;}
			}
		}
		j=num/k;
		for(i=1;i<=k;i++){
			sb[i]=j;num-=j;
		}
		for(i=1;i<=k;i++){
			if(num){sb[i]++;num--;}
		}
		it=1;tmp=0;
		for(i=1;i<=n;i++){
			if(i&1){
				for(j=1;j<=m;j++){
					res[i][j]=it;
					tmp+=(s[i][j]=='R');
					if(it<k&&tmp==sb[it]){it++;tmp=0;}
				}
			}
			else{
				for(j=m;j>=1;j--){
					res[i][j]=it;
					tmp+=(s[i][j]=='R');
					if(it<k&&tmp==sb[it]){it++;tmp=0;}
				}
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				cout<<mp[res[i][j]];
			}cout<<endl;
		}
	}
}
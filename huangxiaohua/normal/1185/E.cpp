#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))
int i,j,k,n,m,t,res[66][66],sx[2050],sy[2050],it,mx1,mx2,sx2,sy2;

char s[2050][2050];
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		it=0;
		for(i=1;i<=n;i++){
			cin>>s[i]+1;
		}
		for(k='z';k>='a';k--){
			memset(sx,0,sizeof(sx));
			memset(sy,0,sizeof(sy));
			sx2=sy2=0;
			for(i=1;i<=n;i++){
				for(j=1;j<=m;j++){
					if(s[i][j]==k){
						sx[i]++;sy[j]++;
					}
				}
			}
			
			for(i=1;i<=n;i++){
				if(sx[i]){sx2++;}
			}
			for(i=1;i<=m;i++){
				if(sy[i]){sy2++;}
			}
			mx1=sx2;mx2=sy2;
			//printf("%d %d\n",mx1,mx2);
			if(mx1>1&&mx2>1){
				cout<<"NO"<<endl;goto aaa;
			}
			if(!mx1&&!mx2){
				if(!it){continue;}
				for(i=1;i<=n;i++){
					for(j=1;j<=m;j++){
						if(s[i][j]=='0'){
							res[k-'a'+1][1]=i;
							res[k-'a'+1][2]=j;
							res[k-'a'+1][3]=i;
							res[k-'a'+1][4]=j;
							goto bbb;
						}
					}
				}
				cout<<"NO"<<endl;goto aaa;
				bbb:;
			}
			if(!it){it=k-'a'+1;}
			if(mx2>1){
				int l,r;l=m+1;r=0;
				for(i=1;i<=n;i++){
					if(sx[i]){
						for(j=1;j<=m;j++){
							if(s[i][j]==k){
								l=min(l,j);
								r=max(r,j);
							}
						}
						for(j=l;j<=r;j++){
							if(s[i][j]!=k&&s[i][j]!='0'){
								cout<<"NO"<<endl;goto aaa;
							}
						}
						res[k-'a'+1][1]=i;
						res[k-'a'+1][2]=l;
						res[k-'a'+1][3]=i;
						res[k-'a'+1][4]=r;
						for(j=l;j<=r;j++){
							s[i][j]='0';
						}
						break;
					}
				}
				continue;
			}
			
			if(mx1>1){
				int l,r;l=n+1;r=0;
				for(j=1;j<=m;j++){
					if(sy[j]){
						for(i=1;i<=n;i++){
							if(s[i][j]==k){
								l=min(l,i);
								r=max(r,i);
							}
						}
						for(i=l;i<=r;i++){
							if(s[i][j]!=k&&s[i][j]!='0'){
								cout<<"NO"<<endl;goto aaa;
							}
						}
						res[k-'a'+1][1]=l;
						res[k-'a'+1][2]=j;
						res[k-'a'+1][3]=r;
						res[k-'a'+1][4]=j;
						for(i=l;i<=r;i++){
							s[i][j]='0';
						}
						break;
					}
				}
				continue;
			}
			
			if(mx1==1&&mx2==1){
				for(i=1;i<=n;i++){
					for(j=1;j<=m;j++){
						if(s[i][j]==k){
							res[k-'a'+1][1]=i;
							res[k-'a'+1][2]=j;
							res[k-'a'+1][3]=i;
							res[k-'a'+1][4]=j;
							s[i][j]='0';
						}
					}
				}
			}
		}
		cout<<"YES"<<endl<<it<<endl;
		for(i=1;i<=it;i++){
			for(j=1;j<=4;j++){
				cout<<res[i][j]<<" ";
			}
			cout<<endl;
		}
		aaa:;
	}
}
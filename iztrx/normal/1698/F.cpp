#include<bits/stdc++.h>
using namespace std;
#define N 300005
#define ll long long
#define mod 998244353

int T,n,i,j,qwq,s,fl,gg,k,p[N],c[N],a[N],b[N],op[N][2],tot;
ll ans;
void OP(int l,int r){
	op[++tot][0]=l;
	op[tot][1]=r;
	for(int i=l;i+i<l+r;++i){
		swap(a[i],a[l+r-i]);
	}
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;++i){
			cin>>a[i];
		}
		for(i=1;i<=n;++i){
			cin>>b[i];
		}
		a[n+1]=a[n+2]=b[n+1]=b[n+2]=0;
		if(a[1]!=b[1]||a[n]!=b[n]){
			cout<<"NO\n";continue;
		}
		else{
			tot=0;gg=0;
			for(i=1;i<=n;++i){
				if(a[i]==b[i])continue;
				int fl=0;
				for(j=i+1;j<=n;++j){
					if(a[j]==b[i]&&a[j+1]==a[i-1]){
						OP(i-1,j+1);fl=1;break;
					}
				}
				if(fl)continue;
				for(j=1;j<=n;++j)c[j]=0;
				for(j=i+1;j<=n;++j){
					if(a[j]==b[i]&&a[j-1]==a[i-1]){
						++c[j-1];
					}
				}
				for(j=i+1;j<=n;++j)c[j]+=c[j-1]; 
				fl=0;
				for(j=i-1;j<=n;++j){
					for(k=j+1;k<=n;++k){
						if(a[j]==a[k]&&c[k-1]-c[j-1]){
							OP(j,k);fl=1;break;
						}
					}
					if(fl)break;
				}
				if(fl){
					for(j=i+1;j<=n;++j){
						if(a[j]==b[i]&&a[j+1]==a[i-1]){
							OP(i-1,j+1);break;
						}
					}
				}
				else{
					gg=1;cout<<"NO\n";break;
				}
			}
			if(!gg){
				cout<<"YES\n";cout<<tot<<"\n";
				for(i=1;i<=tot;++i)cout<<op[i][0]<<" "<<op[i][1]<<"\n";
			}
		}
	}
}
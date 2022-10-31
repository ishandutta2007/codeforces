#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k,n,m,t,x,y,vis[5050];
vector<int> v[5050];
ll p[5050]={1},f[5050],a1[5050],a2[5050],a3[5050],tmp,tmp2;
struct sb{
	int l,r,ty;
	bool operator<(const sb x)const{return l<x.l;}
}s[5050];

int main(){
	for(i=1;i<=5000;i++){
		v[i].push_back(0);
		p[i]=p[i-1]*2%M;
	}
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		v[k].push_back(i);
	}
	for(i=1;i<=m;i++){
		scanf("%d%d",&j,&k);
		x=v[j].size()-1;
		if(k>x){s[i].l=114514;s[i].r=-1;continue;}
		s[i].l=v[j][k];
		s[i].r=v[j][x+1-k];
		s[i].ty=j;
	}
	sort(s+1,s+m+1);
	for(i=0;i<=m;i++){
		if(s[i].l==114514){break;}
		x=s[i].l;
		tmp=0;tmp2=1;
		
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		memset(a3,0,sizeof(a3));
		
		for(j=i+1;j<=m;j++){
			if(s[j].r>x){
				a3[s[j].ty]++;
			}
		}
		for(j=i-1;j>=1;j--){
			a1[s[j].ty]++;
			if(s[j].r>x){
				a2[s[j].ty]++;
			}
		}
		
		for(j=1;j<=5000;j++){
			if(j==s[i].ty){
				tmp++;
				if(a2[j]||a3[j]){
					tmp++;
					tmp2=tmp2*(a2[j]+a3[j])%M;
				}
				continue;
			}
			
			if(!(a1[j]+a2[j]+a3[j])){continue;}
			
			if(!a3[j]){
				if(a2[j]==1){
					if(a1[j]==1){
						tmp++;tmp2=tmp2*2%M;continue;
					}
					else{
						tmp+=2;tmp2=tmp2*(a1[j]-1)%M;continue;
					}
				}
				if(a2[j]>1){
					tmp+=2;
					tmp2=tmp2*a2[j]%M*(a1[j]-1)%M;continue;
				}
				tmp++;
				tmp2=tmp2*a1[j]%M;continue;
			}
			tmp++;
			if(a1[j]){
				tmp++;
				tmp2=tmp2*((a1[j]-a2[j])*(a2[j]+a3[j])%M+a2[j]*(a2[j]-1+a3[j])%M)%M;continue;
			}
			else{
				tmp2=tmp2*a3[j]%M;continue;
			}
		}
		vis[tmp]=1;
		f[tmp]+=tmp2;
		f[tmp]=(f[tmp]%M+M)%M;
	}
	
	for(i=5001;i>=0;i--){
		if(vis[i]){
			printf("%d %lld",i,f[i]%M);return 0;
		}
	}
	return 1;
	
}
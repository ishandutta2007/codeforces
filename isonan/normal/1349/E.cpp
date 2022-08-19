#include <cstdio>
#include <vector>
#include <cstring>
#include <cassert>
#include <algorithm>
#define int long long

int n,stk[200001],top,cnt,f[2][200001],g[2][200001],v[200001];
int ans[200001];
long long t[200001];
std::vector<int>vec[200001];
long long canget(int l,int r,long long S,int x=-1){
//	printf("canget %d %d %lld %d\n",l,r,S,x);
	if(!S&&!~x)return 1;
//	if(l>r)return (~x)?0x7f7f7f7f:0;
	std::swap(l,r);
	l=n-l+1,r=n-r+1;
	long long ans=0x7f7f7f7f;
	if(~x&&n-S+1>=x)ans=n-S+1;
	for(int i=1;i<=r-l+1;i++){
		long long mn=(i*(l+l+i-1))>>1ll,mx=(i*(r+r-i+1))>>1ll;
		if(!~x&&mn<=S&&mx>=S)return 1;
		if(~x&&n+1-S+mx>=x)ans=std::min(ans,std::max(x,n+1-S+mn));
	}
	if(!~x)return 0;
	else return ans;
}
void get(int l,int r,long long S){
//	printf("get %d %d %lld\n",l,r,S);
	std::swap(l,r);
	l=n-l+1,r=n-r+1;
	for(int i=1;i<=r-l+1;i++){
		long long mn=(i*(l+l+i-1))>>1ll,mx=(i*(r+r-i+1))>>1ll;
		if(mn<=S&&mx>=S){
//			printf("%d %d\n",mn,mx);
			int siz=i;
			for(int j=l;j<=r&&siz;j++){
				mn=((siz-1)*(j+1+j+siz-1))>>1ll,mx=((siz-1)*(r+r-(siz-1)+1))>>1ll;
//				printf("%lld %lld %lld\n",j,mn,mx);
				if(mn<=S-j&&mx>=S-j){
//					printf("%d\n",j);
					ans[n-j+1]=1;
					S-=j;
					--siz;
				}
			}
			return;
		}
	}
}
void Check(int i,int v){
	assert(!t[i]||t[i]==v);
}
signed main(){
//	freopen("in.txt","r",stdin);
	scanf("%lld",&n);
	vec[0].push_back(0);
	bool allone=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",t+i);
		allone&=(t[i]<=1);
		v[i]=(t[i]==0)+v[i-1];
		if(t[i]){
			while(top&&t[vec[stk[top]][0]]<t[i])--top;
			if(!top||t[vec[stk[top]][0]]<t[i])stk[++top]=++cnt;
			vec[stk[top]].push_back(i);
		}
	}
	if(allone){
		for(int i=1;i<=n;i++)putchar('0');
		return 0;
	}
//	for(int i=0;i<=cnt;i++,putchar('\n'))
//		for(int j=0;j<vec[i].size();j++)
//			printf("%d ",vec[i][j]);
	memset(f,0x7f7f7f7f,sizeof f);
	f[1][0]=0; 
	for(int i=1;i<=cnt;i++){
		bool same=1;
		int p=vec[i].back();
		for(int j=0;j<(int)vec[i].size()-1;j++){
			same&=(t[vec[i][j]]==t[vec[i][j+1]]);
			if(t[p]>t[vec[i][j]])p=vec[i][j];
		}
		for(int j=0;j<2;j++){
			int end=f[j][i-1];
			if(end>n||(end>vec[i-1].back()&&t[end]))continue;
			long long sum=t[vec[i-1].back()]-(end!=vec[i-1].back());
//			printf("%d %d %d %lld %d %d %d %d\n",i-1,j,end,sum,vec[i-1].back(),t[0],same,p);
			if(same)
				if(i==cnt){
					int L=end+1,R=vec[i][0]-1;
					long long S=t[vec[i][0]]-1-sum;
//					printf("*%d %d %d\n",S,L,R);
					if(n-S+1>=vec[cnt][0]+1&&n-S+1<=n&&!t[n-S+1]){
						f[0][cnt]=n-S+1;
						g[0][cnt]=j;
					}
					else if(L<=R){
//						printf("%d %d\n",L,R);
						std::swap(L,R);
						L=n-L+1,R=n-R+1;
						for(int i=0;i<=R-L+1;i++){
							long long mn=(i*(L+L+i-1))>>1ll,mx=(i*(R+R-i+1))>>1ll;
							if(mn<=S&&mx>=S){
								f[0][cnt]=0;
								g[0][cnt]=j;
								break;
							}
							long long l=std::max(vec[cnt][0]+1,n+1-S+mn),r=std::min(n,n+1-S+mx);
							if(l<=r&&v[r]-v[l-1]>0){
								for(int k=l;k<=r;k++)
									if(!t[k]){
										f[0][cnt]=k;
										g[0][cnt]=j;
									}
								break;
							}
						}
					}
				}
				else{
					long long This=canget(end+1,vec[i][0]-1,t[vec[i][0]]-1-sum,vec[i].back()+1);
					if(This<f[0][i]){
						f[0][i]=This;
						g[0][i]=j;
					}
				}
//			printf("%d %d %d\n",t[p],sum,p);
			if(!same||vec[i].size()==1){
				if(canget(end+1,vec[i][0]-1,t[p]-sum-(n-p+1))){
					f[1][i]=p;
					g[1][i]=j;
				}
			}
		}
		if(f[0][i]>n&&f[1][i]>n&&i==cnt){
			for(int i=0;i<vec[cnt].size();i++)vec[cnt-1].push_back(vec[cnt][i]);
			--cnt;
			i-=2;
			f[0][cnt]=f[1][cnt]=0x7f7f7f7f;
		}
//		printf("%d %d %d\n",i,f[0][i],f[1][i]);
	}
	int p=(f[0][cnt]<=n?0:1);
	for(int i=cnt;i;i--){
		ans[f[p][i]]=1;
		int pre=g[p][i];
		long long sum=(t[f[p][i]]?t[f[p][i]]:(t[vec[i].back()]-1))-((t[f[pre][i-1]]||i==1)?t[f[pre][i-1]]:(t[vec[i-1].back()]-1))-(n-f[p][i]+1);
		if(!f[p][i])sum+=n-f[p][i]+1;
//		printf("%d %d %d %d %d\n",i,f[p][i],f[pre][i-1],pre,(t[f[p][i]]?t[f[p][i]]:(t[vec[i].back()]-1)));
		get(f[pre][i-1]+1,vec[i][0]-1,sum);
		p=pre;
	}
	for(int i=1;i<=n;i++)printf("%d",ans[i]);
	long long sum=0;
	for(int i=1,last=0;i<=n;i++){
		if(ans[i]){
			sum+=n-i+1;
			Check(i,sum);
			for(int j=last+1;j<i;j++)Check(j,sum+1);
			last=i;
		}
		else if(i==n){
			for(int j=last+1;j<i;j++)Check(j,sum+1);
		}
	}
}
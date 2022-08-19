#include <cstdio>
#include <vector>
#include <algorithm>

const int P=1000000007;
int n,m,s[5001],f[5001],h[5001],stat[5001],mx,mn[5001],c[5001][5001],now[5001],ind[5001];
std::vector<int>pos[5001],end[5001];
std::vector<std::pair<int,int> >vec[5001];
void update(int ind,int x){
	for(;ind;ind-=ind&-ind)c[x][ind]++;
}
int query(int ind,int x){
	int tot=0;
	for(;ind<=n;ind+=ind&-ind)tot+=c[x][ind];
	return tot;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",s+i),pos[s[i]].push_back(i);
	for(int i=1;i<=m;i++){
		scanf("%d%d",f+i,h+i);
		if(pos[f[i]].size()>=h[i]){
			vec[f[i]].push_back(std::make_pair(pos[f[i]][h[i]-1],pos[f[i]][pos[f[i]].size()-h[i]]));
			end[f[i]].push_back(pos[f[i]][pos[f[i]].size()-h[i]]);
		}
	}
	for(int i=1;i<=n;i++)std::sort(vec[i].begin(),vec[i].end());
	for(int i=1;i<=n;i++)std::sort(end[i].begin(),end[i].end()),std::reverse(end[i].begin(),end[i].end()),ind[i]=end[i].size()-1;
	int ans=0,tot=0;
	for(int i=0;i<=n;i++){
		int tem1=0,tem2=1;
		bool check=0;
		for(int j=1;j<=n;j++){
			stat[j]=0;
			while(now[j]<vec[j].size()&&vec[j][now[j]].first<=i){
				update(vec[j][now[j]].second,j);
				++now[j];
			}
			while(end[j].size()&&ind[j]>=0&&end[j][ind[j]]<=i){
				--ind[j];
			}
			int cnt1=now[j],cnt2=ind[j]+1,cnt3=query(i+1,j);
			if(now[j]&&vec[j][now[j]-1].first==i){
				++tem1;
				if(vec[j][now[j]-1].second>i)--cnt2;
				if(cnt2){
					++tem1,tem2=1ll*tem2*cnt2%P;
				}
				check=1;
			}
			else{
				if(cnt1==1&&cnt2==1&&cnt3==1){
					tem1++,tem2=1ll*tem2*2%P;
				}
				else if(!cnt1&&cnt2){
					tem1++,tem2=1ll*tem2*cnt2%P;
				}
				else if(cnt1&&!cnt2){
					tem1++,tem2=1ll*tem2*cnt1%P;
				}
				else if(cnt1&&cnt2){
					tem1+=2,tem2=1ll*tem2*(1ll*cnt1*cnt2%P+P-cnt3)%P;
				}
			}
		}
		if(check||i==0){
			if(tem1>ans)ans=tem1,tot=tem2;
			else if(tem1==ans)tot=(tot+tem2)%P;
		}
	}
	printf("%d %d\n",ans,tot);
}
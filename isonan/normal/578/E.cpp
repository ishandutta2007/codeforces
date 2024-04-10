#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>

std::queue<int>q[2];
std::vector<int>num[2][2];
int pre[100001],nxt[100001],n,end[100001];
char S[100001];
int cnt[2][2];
inline void con(int l,int r){nxt[l]=r,pre[r]=l;}
void iterate(int x){
	while(x)printf("%d ",x),x=nxt[x];
}
int main(){
	scanf("%s",S+1);
	n=strlen(S+1);
	int Cnt=n-1;
	for(int i=1;i<=n;i++){
		S[i]=(S[i]=='L');
		if(!q[S[i]].empty())con(q[S[i]].front(),i),q[S[i]].pop(),--Cnt;
		q[S[i]^1].push(i);
	}
	for(int i=1;i<=n;i++)
		if(!pre[i]){
			int tem=i;
			for(;nxt[tem];tem=nxt[tem]);
			num[S[i]][S[tem]].push_back(i);
			cnt[S[i]][S[tem]]++;
			end[i]=tem;
		}
	printf("%d\n",Cnt);
	if(cnt[0][0]>cnt[1][1]){
		for(int i=0;i<num[1][1].size();i++)
			con(end[num[0][0][i]],num[1][1][i]),
			con(end[num[1][1][i]],num[0][0][i+1]);
		end[num[0][0][0]]=end[num[0][0].back()];
		num[1][1].clear();
		num[0][0].resize(1);
		cnt[0][0]=1,cnt[1][1]=0;
	}
	else if(cnt[1][1]>cnt[0][0]){
		for(int i=0;i<num[0][0].size();i++)
			con(end[num[1][1][i]],num[0][0][i]),
			con(end[num[0][0][i]],num[1][1][i+1]);
		end[num[1][1][0]]=end[num[1][1].back()];
		num[0][0].clear();
		num[1][1].resize(1);
		cnt[1][1]=1,cnt[0][0]=0;
	}
	else if(cnt[1][1]){
		if(cnt[1][0]&&cnt[0][1]){
			for(int i=0;i<num[1][1].size()-1;i++)
				con(end[num[0][0][i]],num[1][1][i]),
				con(end[num[1][1][i]],num[0][0][i+1]);
			end[num[0][0][0]]=end[num[0][0].back()];
			num[1][1][0]=num[1][1].back();
			num[1][1].resize(1);
			num[0][0].resize(1);
			cnt[0][0]=1,cnt[1][1]=1;
		}
		else if(cnt[1][0]){
			for(int i=0;i<num[0][0].size();i++){
				con(end[num[1][1][i]],num[0][0][i]);
				if(i<num[0][0].size()-1)con(end[num[0][0][i]],num[1][1][i+1]);
			}
			end[num[1][1][0]]=end[num[0][0].back()];
			num[1][0].push_back(num[1][1][0]);
			num[0][0].clear(),num[1][1].clear();
			cnt[1][1]=0,cnt[0][0]=0,cnt[1][0]++;
		}
		else{
			for(int i=0;i<num[0][0].size();i++){
				con(end[num[0][0][i]],num[1][1][i]);
				if(i<num[0][0].size()-1)con(end[num[1][1][i]],num[0][0][i+1]);
			}
			end[num[0][0][0]]=end[num[1][1].back()];
			num[0][1].push_back(num[0][0][0]);
			num[0][0].clear(),num[1][1].clear();
			cnt[1][1]=0,cnt[0][0]=0,cnt[0][1]++;
		}
	}
	if(cnt[1][0]){
		for(int i=0;i<num[1][0].size()-1;i++)
			con(end[num[1][0][i]],num[1][0][i+1]);
		end[num[1][0][0]]=end[num[1][0].back()];
		num[1][0].resize(1);
	}
	if(cnt[0][1]){
		for(int i=0;i<num[0][1].size()-1;i++)
			con(end[num[0][1][i]],num[0][1][i+1]);
		end[num[0][1][0]]=end[num[0][1].back()];
		num[0][1].resize(1);
	}
	if(cnt[0][1]&&cnt[1][0]){
		if(cnt[0][0]&&cnt[1][1])iterate(num[0][1][0]),iterate(num[0][0][0]),iterate(num[1][0][0]),iterate(num[1][1][0]);
		else if(cnt[0][0])iterate(num[0][1][0]),iterate(num[0][0][0]),iterate(num[1][0][0]);
		else		 iterate(num[1][0][0]),iterate(num[1][1][0]),iterate(num[0][1][0]);
	}
	else if(cnt[0][1]){
		if(cnt[0][0])     iterate(num[0][1][0]),iterate(num[0][0][0]);
		else if(cnt[1][1])iterate(num[1][1][0]),iterate(num[0][1][0]);
		else              iterate(num[0][1][0]);
	}
	else if(cnt[1][0]){
		if(cnt[0][0])     iterate(num[0][0][0]),iterate(num[1][0][0]);
		else if(cnt[1][1])iterate(num[1][0][0]),iterate(num[1][1][0]);
		else              iterate(num[1][0][0]);
	}
	else{
		if(cnt[0][0])iterate(num[0][0][0]);
		else         iterate(num[1][1][0]);
	}
}
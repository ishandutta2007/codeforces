#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

char str[100001];
std::vector<int>pos[2][100001];
int last[26];
int n;
struct info{int num,dis;long long ans;};
info merge(info a,info b){
	if(!a.num)return b;
	if(!b.num)return a;
	return (info){a.num+b.num,a.dis+b.dis,1ll*b.num*a.dis+a.ans+b.ans};
}
int Log[100001];
struct bl{
	int s[100001],pos[100001][26],nxt[100001][17],Next[100001];
	int st[100001][17];
	int q[100001],h,t,last[26];
	info val[100001][17];
	bool rev;
	int query(int l,int r){
		int k=Log[r-l+1];
//		printf("%d %d %d %d %d\n",l,r,k,st[l][0],std::max(st[l][k],st[r-(1<<k)+1][k]));
		return std::max(st[l][k],st[r-(1<<k)+1][k]);
	}
	void init(){
		for(int i=0;i<26;i++)last[i]=n;
		for(int i=n;i;i--){
			Next[i]=last[s[i]];
			last[s[i]]=i;
		}
//		for(int i=n;i;i--)printf("%d ",n+1-Next[i]);putchar('\n');
		for(int i=0;i<26;i++)last[i]=0;
		for(int i=1;i<=n;i++)
			st[i][0]=Next[i];
		for(int j=1;(1<<j)<=n;j++)
			for(int i=1;i+(1<<j)-1<=n;i++)
				st[i][j]=std::max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		for(int i=1;i<=n;i++){
			nxt[i][0]=query(last[s[i]],i);
//			printf("%d %d\n",i,nxt[i][0]);
			val[i][0]=(info){nxt[i][0]-i,1,nxt[i][0]-i};
			last[s[i]]=i;
		}
		for(int j=1;j<=16;j++)
			for(int i=1;i<=n;i++)
				nxt[i][j]=nxt[nxt[i][j-1]][j-1],
				val[i][j]=merge(val[i][j-1],val[nxt[i][j-1]][j-1]);
//		for(int k=0;k<3;k++)
//		printf("%d %d %d\n",val[n+1-4][k].num,val[n+1-4][k].dis,val[n+1-4][k].ans);
	}
}front,back;
int main(){
	scanf("%s",str+1);
	n=strlen(str+1);
	Log[1]=0;
	for(int i=2;i<=n;i++)Log[i]=Log[i>>1]+1;
	for(int i=1;i<=n;i++)front.s[i]=back.s[n-i+1]=str[i]-'a';
	front.init();
	back.init();
	for(int i=1;i<=n;i++){
		last[str[i]-'a']=i;
		for(int j=0;j<26;j++)
			pos[0][i].push_back(last[j]);
		pos[0][i].push_back(0);
	}
	for(int i=0;i<26;i++)last[i]=n+1;
	for(int i=n;i;i--){
		last[str[i]-'a']=i;
		for(int j=0;j<26;j++)
			pos[1][i].push_back(last[j]);
		pos[1][i].push_back(n+1);
	}
	long long tot=0;
	for(int i=1;i<=n;i++){
		int L=i,R=i;
		info ansL=(info){0,0,0},ansR=(info){0,0,0};
		std::sort(pos[0][i].begin(),pos[0][i].end());
		std::sort(pos[1][i].begin(),pos[1][i].end());
		std::reverse(pos[1][i].begin(),pos[1][i].end());
		for(;L>1||R<n;){
			while(L<=pos[0][i].back()||R>=pos[1][i].back()){
				while(L<=pos[0][i].back())pos[0][i].pop_back();
				while(R>=pos[1][i].back())pos[1][i].pop_back();
				int nR=front.query(L,R),nL=n+1-back.query(n-R+1,n-L+1);
				ansL=merge(ansL,(info){L-nL,1,L-nL});
				ansR=merge(ansR,(info){nR-R,1,nR-R});
				L=nL,R=nR;
			}
			
			for(int j=16;~j;--j)
				if(front.nxt[R][j]<pos[1][i].back()&&n+1-back.nxt[n-L+1][j]>pos[0][i].back())
					ansL=merge(ansL,back.val[n-L+1][j]),
					ansR=merge(ansR,front.val[R][j]),
					R=front.nxt[R][j],L=n+1-back.nxt[n-L+1][j];
//					printf("%d %d %d %lld %d %d\n",i,L,R,ansL.ans+ansR.ans,ansL.dis,ansR.dis);
			if(L>pos[0][i].back()&&R<pos[1][i].back()){
				ansL=merge(ansL,back.val[n-L+1][0]),
				ansR=merge(ansR,front.val[R][0]),
				R=front.nxt[R][0],L=n+1-back.nxt[n-L+1][0];
			}
		}
		tot+=ansL.ans+ansR.ans;
//		printf("%d %lld %lld\n",i,ansL.ans+ansR.ans,tot);
	}
	printf("%lld\n",tot);
}
//tfftfffftfffcccfftffttfctfcf
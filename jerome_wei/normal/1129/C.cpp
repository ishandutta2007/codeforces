#include<bits/stdc++.h>
using namespace std;
const int N=4010;
int a[N*2];
int n;
const int mod=1e9+7;
struct SAM{
	struct node{
		int len,ch[2],right,par;
	}t[N*3];
	int cnt,root,tail;
	inline int newnode(int _len){
		++cnt;t[cnt].len=_len;return cnt;
	}
	inline void init(){
		root=tail=newnode(0);
	}
	inline int extend(int c){
		int np=newnode(t[tail].len+1),p=tail;
		while(p&&!t[p].ch[c])t[p].ch[c]=np,p=t[p].par;
		if(p==0)t[np].par=root;
		else if(t[t[p].ch[c]].len==t[p].len+1)t[np].par=t[p].ch[c];
		else {
			int nq=newnode(t[p].len+1),q=t[p].ch[c];
			memcpy(t[nq].ch,t[q].ch,sizeof(t[q].ch));t[nq].par=t[q].par;
			t[q].par=t[np].par=nq;
			while(p&&t[p].ch[c]==q)t[p].ch[c]=nq,p=t[p].par;
		}
		t[np].right=1,tail=np;
		return t[t[np].par].len+1;
	}
}sam;
int minlen[N];
int f[N][N];
bool judge(int l,int r){
	if(r-l+1<4)return 1;
	if(r-l+1>4)return 0;
	int tmp=a[l]+a[l+1]*2+a[l+2]*4+a[l+3]*8;
	if(tmp==12||tmp==15||tmp==10||tmp==7)return false;
	return true;
}
int main()
{
	scanf("%d",&n);
	sam.init();
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		minlen[i]=sam.extend(a[i]);
//		cout<<"::"<<minlen[i]<<endl;
	}
	for(int i=1;i<=n;i++){
		f[i][i-1]=1;
		for(int j=i;j<=n;j++){
			for(int k=j-1;k>=max(i-1,j-4);k--)if(judge(k+1,j)){
				f[i][j]+=f[i][k];
				f[i][j]%=mod;
			}
		}
	}
//	cout<<f[1][3]<<"!"<<endl;
	int ans=0;
	for(int i=1;i<=n;i++){
		int R=i-minlen[i]+1;
		for(int j=1;j<=R;j++)ans=(ans+f[j][i])%mod;
		printf("%d\n",ans);
	}
}
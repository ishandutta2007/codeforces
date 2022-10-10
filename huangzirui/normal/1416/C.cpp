#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=300010;
int i,j,k,n,m,a[maxn];
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}struct trie{
	int son[2],is,sum[2];ll ans[2];
}T[maxn*35];int cnt=1,root=1;ll ans[55],Ans,ans2[55][2],Ans2;
void insert(int &root,int S,int d){
	int num=S/(1<<d);
	if(!root)root=++cnt;
	T[root].sum[num]++;
	T[root].ans[num]+=T[root].sum[1-num];
	if(d)insert(T[root].son[num],S%(1<<d),d-1);
}void getans(int root,int d){
	if(!root)return;
//	cout<<"root="<<root<<" d="<<d<<" ans="<<T[root].ans[1]<<' '<<T[root].ans[0]<<' '<<T[root].sum[0]<<' '<<T[root].sum[1]<<endl;
	if(d){
		getans(T[root].son[0],d-1);
		getans(T[root].son[1],d-1);
	}ans[d]+=T[root].ans[1]-T[root].ans[0];
	ans2[d][0]+=T[root].ans[0];ans2[d][1]+=T[root].ans[1];
}
signed main(){
	cin>>n;
	for(i=1;i<=n;i++){
		a[i]=read();
		insert(root,a[i],30);
	}getans(root,30);
	for(i=30;i>=0;i--)
		if(ans[i]<0)Ans+=(1<<i),Ans2+=ans2[i][1];
		else Ans2+=ans2[i][0];
	cout<<Ans2<<' '<<Ans<<endl;
	return 0;
}
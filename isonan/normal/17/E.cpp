#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

const int P=51123987;
long long val[2][2000010];
int dep[2000010],nxt[2000010],len[2000010],cnt,last;
int head[2000010],key[2000010],Nxt[2000010],b[2000010],k;
void push(int s,int t,int val){
	Nxt[++k]=head[s];
	head[s]=k;
	key[k]=t;
	b[k]=val;
}
int findson(int x,int c){
	for(int i=head[x];i;i=Nxt[i])
		if(key[i]==c)return b[i];
	return 0;
}
int S[2000010],n,nl;
char str[2000010];
int getnxt(int x){
	while(S[n]!=S[n-len[x]-1])x=nxt[x];
	return x;
}
void add(int x){
	S[++n]=x;
	int cur=getnxt(last);
	if(!findson(cur,x)){
		++cnt;
		len[cnt]=len[cur]+2;
		nxt[cnt]=findson(getnxt(nxt[cur]),x);
		dep[cnt]=dep[nxt[cnt]]+1;
		push(cur,x,cnt);
	}
	last=findson(cur,x);
}
int main(){
	cnt=1;
	nxt[0]=1;
	len[1]=-1;
	S[0]=-1;
	scanf("%d%s",&nl,str+1);
	for(int i=1;i<=nl;i++){
		add(str[i]-'a');
		(val[0][i]=val[0][i-1]+dep[last])%=P;
	}
	std::reverse(str+1,str+nl+1);
	memset(dep,0,sizeof dep);
	memset(nxt,0,sizeof nxt);
	memset(len,0,sizeof len);
	memset(head,0,sizeof head);
	k=0;
	cnt=1;
	nxt[0]=1;
	len[1]=-1;
	n=0;
	long long ans=0;
	for(int i=1;i<=nl;i++){
		add(str[i]-'a');
		val[1][nl-i+1]=dep[last];
		ans-=((1ll*dep[last]*(dep[last]-1))/2ll)%P;
	}
	ans=(ans%P+P)%P;
	for(int i=1;i<=nl;i++)(val[1][i]+=val[1][i-1])%=P;
	for(int i=1;i<=nl;i++)ans+=1ll*(val[0][i]+P-val[0][i-1])*(val[1][i]+P-val[0][i-1])%P;//,printf("%lld\n",1ll*(val[0][i]-val[0][i-1])*(val[1][i]-val[0][i-1]));
//	for(int i=1;i<=nl;i++)printf("%d %d\n",val[0][i],val[1][i]);
	printf("%lld\n",(ans+P-val[0][nl])%P);
}
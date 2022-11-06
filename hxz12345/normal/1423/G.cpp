#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
map<int,int> tag;
long long E1[1001010],E2[1001010];
long long cas,lsh[1001010],tot,OPT[1001010],L[1001100],R[1001010],X[1001010],LEN[1001010],Pr[1001010],x,len,w,E[1001010],n,Q,i,a[1001010],opt,l,r,pre[1001010],suf[1001010],F[1001010],lft,rit,ans;
#define IT set<node>::iterator
#define FIT set<asking>::iterator
struct node{
	long long l,r;
	mutable long long v;
	mutable long long p;
	node (int l,int r=-1,long long v=0,long long p=0): l(l),r(r),v(v),p(p) {}
	bool operator < (const node &x) const{return l<x.l;}
};
struct asking{
	long long l,r;
	asking (int l,int r=-1): l(l),r(r){}
    bool operator < (const asking & x) const{return l<x.l;}
};
set<asking> Gd[1001010];
set<node> G;
//Gd[col] pre 
void modify(long long x,long long y){for (;x<=n;x+=x&-x) E1[x]+=y;}
long long query(long long x){long long ans=0;for (;x;x-=x&-x) ans+=E1[x];return ans;}
void modify1(long long x,long long y){for (;x<=n;x+=x&-x) E2[x]+=y;}
long long query1(long long x){long long ans=0;for (;x;x-=x&-x) ans+=E2[x];return ans;}
IT split(long long x){
	IT it=G.lower_bound(node(x));
	if ((it!=G.end())&&(it->l==x)) return it;
	it--;
	if (it->r<x) return G.end();
	long long lft=it->l,rit=it->r,val=it->v,pr=it->p;
	long long llft=lft,lrit=rit,lpr=pr;
	//lft~rit lft~x-1,x~rit 
	G.erase(it);//
	if (min(n-rit,n-pr)>0){modify(1,-rit-1);modify(min(n-rit,n-pr)+1,rit+1);}
	if (n-rit+1<=n-pr){modify(n-rit+1,-n-2);modify(n-pr+1,n+2);modify1(n-rit+1,1);modify1(n-pr+1,-1);}
	if (lft-pr<=n-pr){modify(lft-pr,pr+1);modify(n-pr+1,-pr-1);}
	if (min(lft-pr-1,n-pr)>0){modify(1,lft+1);modify(min(lft-pr-1,n-pr)+1,-lft-1);modify1(1,-1);modify1(min(lft-pr-1,n-pr)+1,1);}
	FIT git=Gd[val].lower_bound(asking(lft));
	Gd[val].erase(git);
	Gd[val].insert(asking(lft,x-1));
	rit=x-1;
	if (min(n-rit,n-pr)>0){modify(1,rit+1);modify(min(n-rit,n-pr)+1,-rit-1);}
	if (n-rit+1<=n-pr){modify(n-rit+1,n+2);modify(n-pr+1,-n-2);modify1(n-rit+1,-1);modify1(n-pr+1,1);}
	if (lft-pr<=n-pr){modify(lft-pr,-pr-1);modify(n-pr+1,pr+1);}
	if (min(lft-pr-1,n-pr)>0){modify(1,-lft-1);modify(min(lft-pr-1,n-pr)+1,lft+1);modify1(1,1);modify1(min(lft-pr-1,n-pr)+1,-1);}
	rit=lrit;
	Gd[val].insert(asking(x,rit));
	lft=x;pr=x-1;
	if (min(n-rit,n-pr)>0){modify(1,rit+1);modify(min(n-rit,n-pr)+1,-rit-1);}
	if (n-rit+1<=n-pr){modify(n-rit+1,n+2);modify(n-pr+1,-n-2);modify1(n-rit+1,-1);modify1(n-pr+1,1);}
	if (lft-pr<=n-pr){modify(lft-pr,-pr-1);modify(n-pr+1,pr+1);}
	if (min(lft-pr-1,n-pr)>0){modify(1,-lft-1);modify(min(lft-pr-1,n-pr)+1,lft+1);modify1(1,1);modify1(min(lft-pr-1,n-pr)+1,-1);}
	lft=llft;rit=lrit;pr=lpr;
	G.insert(node(lft,x-1,val,pr));//Pr[i] sufPr[i]  
	return G.insert(node(x,rit,val,x-1)).first;
}
void assign(int l,int r,long long val){
	IT itr=split(r+1),itl=split(l);
	for (IT it=itl;it!=itr;it++) {
		FIT git=Gd[it->v].lower_bound(asking(it->r+1));
		if (git!=Gd[it->v].end()){
		int L=git->l,R=git->r;
	     	if (L>r) {
		 	IT git=G.lower_bound(node(L));
		 	long long lft=git->l,rit=git->r,pr=git->p;
		 		if (min(n-rit,n-pr)>0){modify(1,-rit-1);modify(min(n-rit,n-pr)+1,rit+1);}
	if (n-rit+1<=n-pr){modify(n-rit+1,-n-2);modify(n-pr+1,n+2);modify1(n-rit+1,1);modify1(n-pr+1,-1);}
	if (lft-pr<=n-pr){modify(lft-pr,pr+1);modify(n-pr+1,-pr-1);}
	if (min(lft-pr-1,n-pr)>0){modify(1,lft+1);modify(min(lft-pr-1,n-pr)+1,-lft-1);modify1(1,-1);modify1(min(lft-pr-1,n-pr)+1,1);}
	        lft=git->l,rit=git->r;
	        FIT rgit=Gd[it->v].lower_bound(asking(it->l));
	        if (rgit==Gd[it->v].end()) pr=0;
	        else {
	        	if (rgit==Gd[it->v].begin()) pr=0;
	        	else {
	        		rgit--;
	        		pr=rgit->r;
				}
			}
	        if (min(n-rit,n-pr)>0){modify(1,rit+1);modify(min(n-rit,n-pr)+1,-rit-1);}
	if (n-rit+1<=n-pr){modify(n-rit+1,n+2);modify(n-pr+1,-n-2);modify1(n-rit+1,-1);modify1(n-pr+1,1);}
	if (lft-pr<=n-pr){modify(lft-pr,-pr-1);modify(n-pr+1,pr+1);}
	if (min(lft-pr-1,n-pr)>0){modify(1,-lft-1);modify(min(lft-pr-1,n-pr)+1,lft+1);modify1(1,1);modify1(min(lft-pr-1,n-pr)+1,-1);}
			 git=G.lower_bound(node(L));
			 git->p=pr;} 
		 }
		FIT rgit=Gd[it->v].lower_bound(asking(it->l));
		long long lft=it->l,rit=it->r,pr=it->p;
			if (min(n-rit,n-pr)>0){modify(1,-rit-1);modify(min(n-rit,n-pr)+1,rit+1);}
	if (n-rit+1<=n-pr){modify(n-rit+1,-n-2);modify(n-pr+1,n+2);modify1(n-rit+1,1);modify1(n-pr+1,-1);}
	if (lft-pr<=n-pr){modify(lft-pr,pr+1);modify(n-pr+1,-pr-1);}
	if (min(lft-pr-1,n-pr)>0){modify(1,lft+1);modify(min(lft-pr-1,n-pr)+1,-lft-1);modify1(1,-1);modify1(min(lft-pr-1,n-pr)+1,1);}
		Gd[it->v].erase(rgit);
	}
	G.erase(itl,itr);
    FIT git=Gd[val].lower_bound(asking(r+1));
    int GG=0;
    if (git!=Gd[val].end()){
    	int L=git->l,R=git->r;
    	IT git=G.lower_bound(node(L));
    	long long lft=git->l,rit=git->r,pr=git->p;
    	if (min(n-rit,n-pr)>0){modify(1,-rit-1);modify(min(n-rit,n-pr)+1,rit+1);}
	if (n-rit+1<=n-pr){modify(n-rit+1,-n-2);modify(n-pr+1,n+2);modify1(n-rit+1,1);modify1(n-pr+1,-1);}
	if (lft-pr<=n-pr){modify(lft-pr,pr+1);modify(n-pr+1,-pr-1);}
	if (min(lft-pr-1,n-pr)>0){modify(1,lft+1);modify(min(lft-pr-1,n-pr)+1,-lft-1);modify1(1,-1);modify1(min(lft-pr-1,n-pr)+1,1);}
		pr=r;	
	    if (min(n-rit,n-pr)>0){modify(1,rit+1);modify(min(n-rit,n-pr)+1,-rit-1);}
	if (n-rit+1<=n-pr){modify(n-rit+1,n+2);modify(n-pr+1,-n-2);modify1(n-rit+1,-1);modify1(n-pr+1,1);}
	if (lft-pr<=n-pr){modify(lft-pr,-pr-1);modify(n-pr+1,pr+1);}
	if (min(lft-pr-1,n-pr)>0){modify(1,-lft-1);modify(min(lft-pr-1,n-pr)+1,lft+1);modify1(1,1);modify1(min(lft-pr-1,n-pr)+1,-1);}
		git->p=r;
	}
    	FIT gitt=git;
    	if (gitt!=Gd[val].begin()){
    		gitt--;
    	    GG=gitt->r;
		}
	long long lft=l,rit=r,pr=GG;
	if (min(n-rit,n-pr)>0){modify(1,rit+1);modify(min(n-rit,n-pr)+1,-rit-1);}
	if (n-rit+1<=n-pr){modify(n-rit+1,n+2);modify(n-pr+1,-n-2);modify1(n-rit+1,-1);modify1(n-pr+1,1);}
	if (lft-pr<=n-pr){modify(lft-pr,-pr-1);modify(n-pr+1,pr+1);}
	if (min(lft-pr-1,n-pr)>0){modify(1,-lft-1);modify(min(lft-pr-1,n-pr)+1,lft+1);modify1(1,1);modify1(min(lft-pr-1,n-pr)+1,-1);}
	Gd[val].insert(asking(l,r));
	G.insert(node(l,r,val,GG));
}
long long random(long long n){
	return rand() % n+1;
}
int main()
{
	srand(time(0));
	n=read();Q=read();
	for (i=1;i<=n;i++) a[i]=read(),lsh[++tot]=a[i];
	for (i=1;i<=Q;i++){
		OPT[i]=read();
		if (OPT[i]==1) L[i]=read(),R[i]=read(),X[i]=read(),lsh[++tot]=X[i];
		else LEN[i]=read();
	}
	sort(lsh+1,lsh+tot+1);tot=unique(lsh+1,lsh+tot+1)-lsh-1;
	for (i=1;i<=n;i++) a[i]=lower_bound(lsh+1,lsh+1+tot,a[i])-lsh;
	for (i=1;i<=Q;i++)
	   if (OPT[i]==1) X[i]=lower_bound(lsh+1,lsh+tot+1,X[i])-lsh;
	for (i=1;i<=n;i++) 
	    {
		G.insert(node(i,i,a[i],Pr[a[i]]));
		modify(1,i+1);modify(min(n-i,n-Pr[a[i]])+1,-i-1);
		if (n-i+1<=n-Pr[a[i]]) modify(n-i+1,n+2),modify(n-Pr[a[i]]+1,-n-2),modify1(n-i+1,-1),modify1(n-Pr[a[i]]+1,1);
		modify(i-Pr[a[i]],-Pr[a[i]]-1);modify(n-Pr[a[i]]+1,Pr[a[i]]+1);
		if (min(i-Pr[a[i]]-1,n-Pr[a[i]])>0){
			modify(1,-i-1);
			modify(min(i-Pr[a[i]]-1,n-Pr[a[i]])+1,i+1);
			modify1(1,1);
			modify1(min(i-Pr[a[i]]-1,n-Pr[a[i]])+1,-1);
		}
		Pr[a[i]]=i;Gd[a[i]].insert(asking(i,i));
	    }
	for (cas=1;cas<=Q;cas++){
		opt=OPT[cas];l=L[cas];r=R[cas];x=X[cas];
		if (opt==1) assign(l,r,x);
		else 
		   { 
		   	IT itr=split(n+1),itl=split(1);
		   len=LEN[cas],printf("%lld\n",query(len)+len*query1(len));}
	}
return 0;
}
//Pr[i],1~5+=
//suf[i]<=n-len->len<=min(n-suf[i],n-Pr[i])tag[len]+=suf[i]+1
//suf[i]>=n-len+1->    n-suf[i]+1<=len<=n-Pr[i]tag[len]+=n-len+1+1
//pre[i]-len+1<=Pr[i]+1->pre[i]-Pr[i]<=len<=n-Pr[i] tag[len]-=Pr[i]+1
//pre[i]-len+1>Pr[i]+1->len<=min(pre[i]-Pr[i]-1,n-Pr[i]) tag[len]-=pre[i]-len+1
//tag[len]
//lensbnmsl. 
// 
//set
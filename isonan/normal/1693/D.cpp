#include <set>
#include <cstdio>
#include <algorithm>

int n,p[200010];
int Log[200010],tp[200010],nxt[200010],end[200010];
int R[200010],L[200010];
int v[200010];
std::multiset<int>set;
long long ans;
int lst[200010][2];
int pp[200010][2];
bool cmp(int a,int b){
	if(!(a>=1&&a<=n))return 1;
	if(!(b>=1&&b<=n))return 1;
	if(p[a]>p[b])return 1;
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;++i)Log[i]=Log[i>>1]+1;
	for(int i=1;i<=n;++i){
		scanf("%d",p+i);
	}
	for(int i=1;i<=n;++i)
		tp[i]=(p[i]<p[i+1]);
	int l[2]={0,0};
	end[0]=n+1;
	for(int i=1;i<=n;++i){
		lst[i][0]=lst[i-1][0];
		lst[i][1]=lst[i-1][1];
		lst[i][tp[i]]=i;
	}
	for(int i=n,_r=n;i;--i){
		nxt[i]=l[tp[i]];
		if((p[i]<p[nxt[i]])!=tp[i])nxt[i]=0;
		end[i]=nxt[i]?end[nxt[i]]:(l[tp[i]]?l[tp[i]]:(n+1));
		// printf("*%d %d %d\n",i,tp[i],end[i]);
		l[tp[i]]=i;
		_r=std::min(_r,std::min(end[l[0]],end[l[1]])-1);
		while(p[lst[_r][0]]<p[lst[_r][1]]&&lst[_r][0]>=i&&lst[_r][1]>=i)--_r;
		R[i]=_r;
		pp[i][0]=lst[R[i]][0];
		pp[i][1]=lst[R[i]][1];
		if(pp[i][0]<i)pp[i][0]=0;
		if(pp[i][1]<i)pp[i][1]=0;
		// R[i]=std::min(end[l[0]],end[l[1]])-1;
		ans+=R[i]-i+1;
	}
	for(int i=1;i<=n;++i)
		tp[i]=(p[i]<p[i-1]);
	l[0]=l[1]=0;
	end[0]=0;
	lst[n+1][0]=lst[n+1][1]=n+1;
	for(int i=n;i;--i){
		lst[i][0]=lst[i+1][0];
		lst[i][1]=lst[i+1][1];
		lst[i][tp[i]]=i;
	}
	for(int i=1,_l=1;i<=n;++i){
		nxt[i]=l[tp[i]];
		if((p[i]<p[nxt[i]])!=tp[i])nxt[i]=0;
		end[i]=nxt[i]?end[nxt[i]]:l[tp[i]];
		l[tp[i]]=i;
		_l=std::max(_l,std::max(end[l[0]],end[l[1]])+1);
		// printf("%d\n",std::max(end[l[0]],end[l[1]])+1);
		while(p[lst[_l][0]]<p[lst[_l][1]]&&lst[_l][0]<=i&&lst[_l][1]<=i)++_l;
		L[i]=_l;
		// L[i]=std::max(end[l[0]],end[l[1]])+1;
	}
	for(int i=1;i<=n;++i){
		// printf("%d %d %d %d %d\n",i,pp[i][0],lst[R[i]+1][1],lst[R[i]+1][0],pp[i][1]);
		if(cmp(pp[i][0],lst[R[i]+1][1])&&cmp(lst[R[i]+1][0],pp[i][1]))++v[R[i]+1];
		else if(cmp(pp[i][0],lst[R[i]+1][1]))ans+=lst[R[i]+1][0]-R[i]-1;
		else if(cmp(lst[R[i]+1][0],pp[i][1]))ans+=lst[R[i]+1][1]-R[i]-1;
		// else printf("%d\n",i);
	}
	// for(int i=1;i<=n;++i)printf("&&%d %d\n",L[i],R[i]);
	for(int i=n;i;--i){
		set.insert(L[i]);
		// printf("%d\n",*set.begin());
		while(*set.rbegin()>i){
			set.erase(*set.rbegin());
		}
		// printf("%d %d\n",i,set.size());
		ans+=1ll*v[i]*set.size();
	}
	printf("%lld\n",ans);
}
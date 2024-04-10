#include<cstdio>
#include<queue>
using namespace std;
typedef long long ll;
int n,m,k;
ll p,a[110000],h[110000],nowh[110000];
struct node{
    ll t,id;
    bool operator<(const node &x) const{ return x.t<t;}
};
char Getchar(){
    static char now[1<<20],*S,*T;
    if (T==S){
        T=(S=now)+fread(now,1,1<<20,stdin);
        if (T==S) return EOF;
    }
    return *S++;
}
int read(){
    int x=0,f=1;
    char ch=Getchar();
    while (ch<'0'||ch>'9'){
        if (ch=='-') f=-1;
        ch=Getchar();
    }
    while (ch<='9'&&ch>='0') x=x*10+ch-'0',ch=Getchar();
    return x*f;
}
bool check(ll mid){
    priority_queue<node> q;
    for (int i=1;i<=n;i++) nowh[i]=mid;
    for (int i=1;i<=n;i++)
        if (nowh[i]-a[i]*m<h[i]) q.push((node){nowh[i]/a[i],i});
    node u;
    for (int i=1;i<=m;i++)
    	for (int j=1;j<=k;j++){
    		if (q.empty()) return true;
    		u=q.top(); q.pop();
			if (u.t<i) return false;
            nowh[u.id]+=p;
            if (nowh[u.id]-a[u.id]*m<h[u.id]) q.push((node){nowh[u.id]/a[u.id],u.id});
		}
	return q.empty();
}
int main(){
	n=read(); m=read(); k=read(); p=read();
	ll l=0,r=-1;
	for (int i=1;i<=n;i++){
		h[i]=read(); a[i]=read();
		l=max(a[i],l); r=max(h[i]+a[i]*m,r);
	}
    while (l<r){
        ll mid=(l+r)>>1;
        if (check(mid)) r=mid;
        else l=mid+1;
    }
    printf("%lld\n",l);
	return 0;
}
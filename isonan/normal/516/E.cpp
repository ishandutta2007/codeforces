#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>

long long n,m,_gcd,cnt,orig[2000001],tem,tem1,tem2,tem3,top1,top2,n2m,m2n,tp,dm,dn;
long long B[100001],G[100001],cb,cg;
bool vis[4000001];
std::pair<long long,long long>num1[2000001],num2[2000001];
long long gcd(long long a,long long b){return (!b)?a:gcd(b,a%b);}
long long phi(long long x){
	long long ans=1;
	for(int i=2;i*i<=x;i++)
		if(x%i==0){
			ans*=i-1,x/=i;
			while(x%i==0)ans*=i,x/=i;
		}
	if(x>1)ans*=x-1;
	return ans;
}
long long qsm(long long a,long long b,long long P){
	long long ans=1;
	while(b){
		if(b&1)(ans*=a)%=P;
		(a*=a)%=P;
		b>>=1;
	}
	return ans;
}
int head[1000001],nxt[3000001],b[3000001],k;
long long v[3000001];
void print(long long x){
	if(x>=0)printf("B-%I64d ",x);
	else printf("G-%I64d ",-x-1);
}
void push(int s,int t,long long val){
//	if(s==88||t==88){
//		s?print(orig[s]):(void)(printf("S "));
//		t?print(orig[t]):(void)(printf("S "));
//		printf("%I64d\n",val);
//	}
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
int find(long long x){return std::lower_bound(orig+1,orig+tp+1,x)-orig;}
long long val(std::pair<int,long long>x,long long y,long long z){return (x.first+x.second*y)%z;}
struct point{
    long long val,index;
}num[1000001];
long long dis[1000001];
bool cmp(point a,point b){return a.val>b.val;}
long long dijkstra(){
    memset(dis,0x7f7f7f7f,sizeof dis);
    memset(vis,0,sizeof vis);
    dis[0]=0;
    int top=0;
    num[++top]=(point){0,0};
    while(top){
        point now=num[1];
        std::pop_heap(num+1,num+top+1,cmp);
        top--;
        if(vis[now.index])continue;
        vis[now.index]=1;
        for(int j=head[now.index];j;j=nxt[j])
            if(dis[b[j]]>v[j]+now.val&&!vis[b[j]]){
                dis[b[j]]=v[j]+now.val;
                num[++top]=(point){dis[b[j]],b[j]};
                std::push_heap(num+1,num+top+1,cmp);
            }
    }
    long long x=0;
    for(int i=1;i<=cb;i++)dis[find(B[i])]=0;
    for(int i=1;i<=cg;i++)dis[find(-G[i]-1)]=0;
    for(int i=1;i<=tp;i++)x=std::max(x,dis[i]);
//    for(int i=1;i<=tp;i++)print(orig[i]);putchar('\n');
//    for(int i=1;i<=tp;i++)printf("%I64d ",dis[i]);putchar('\n');
//	for(int i=1;i<=tp;i++)if(dis[i]>n*m)printf("%d\n",i);
    return x;
}
int main(){
	scanf("%I64d%I64d",&n,&m);
	cnt=_gcd=gcd(n,m);
	if(cnt>200000){
		puts("-1");
		return 0;
	}
	dm=m/_gcd,dn=n/_gcd;
	n2m=qsm(dn,phi(dm)-1,dm);
	m2n=qsm(dm,phi(dn)-1,dn);
	scanf("%I64d",&cb);
	for(int i=1;i<=cb;i++){
		scanf("%I64d",&tem1);B[i]=tem1;
		tem2=tem1%_gcd;
		if(!vis[tem2])vis[tem2]=1,--cnt;
		tem3=((tem1-tem2)/_gcd)*m2n%(dn);
		num1[++top1]=std::make_pair(tem2,tem3);
		num1[++top1]=std::make_pair(tem2,(tem3+(dn)-1)%(dn));
		orig[++tp]=tem1;
		orig[++tp]=(tem1+n-(m%n))%n;
		tem1%=m;
		tem3=(((tem1-tem2)/_gcd)*n2m)%(dm);
		num2[++top2]=std::make_pair(tem2,tem3);
		num2[++top2]=std::make_pair(tem2,(tem3+(dm)-1)%(dm));
		orig[++tp]=-tem1-1;
		orig[++tp]=-((tem1+m-(n%m))%m)-1;
	}
	scanf("%I64d",&cg);
	for(int i=1;i<=cg;i++){
		scanf("%I64d",&tem1);G[i]=tem1;
		tem2=tem1%_gcd;
		if(!vis[tem2])vis[tem2]=1,--cnt;
		tem3=(((tem1-tem2)/_gcd)*n2m)%(dm);
		num2[++top2]=std::make_pair(tem2,tem3);
		num2[++top2]=std::make_pair(tem2,(tem3+(dm)-1)%(dm));
		orig[++tp]=-tem1-1;
		orig[++tp]=-((tem1+m-(n%m))%m)-1;
		tem1%=n;
		tem3=((tem1-tem2)/_gcd)*m2n%(dn);
		num1[++top1]=std::make_pair(tem2,tem3);
		num1[++top1]=std::make_pair(tem2,(tem3+(dn)-1)%(dn));
		orig[++tp]=tem1;
		orig[++tp]=(tem1+n-(m%n))%n;
	}
	if(cnt){
		puts("-1");
		return 0;
	}
	std::sort(orig+1,orig+tp+1);
	tp=std::unique(orig+1,orig+tp+1)-orig-1;
	std::sort(num1+1,num1+top1+1);
	top1=std::unique(num1+1,num1+top1+1)-num1-1;
	std::sort(num2+1,num2+top2+1);
	top2=std::unique(num2+1,num2+top2+1)-num2-1;
	for(int i=1;i<=cb;i++){
		push(find(B[i]),find(-(B[i]%m)-1),0);
		push(0,find(B[i]),B[i]);
	}
	for(int i=1;i<=cg;i++){
		push(find(-G[i]-1),find(G[i]%n),0);
		push(0,find(-G[i]-1),G[i]);
	}
	int last=0;
	for(int i=2;i<=top1;i++){
		if(num1[i].first==num1[i-1].first){
			push(find(val(num1[i-1],m,n)),find(val(num1[i],m,n)),((num1[i].second+dn-num1[i-1].second)%dn)*m);
		}
		else{
			push(find(val(num1[i-1],m,n)),find(val(num1[last+1],m,n)),((num1[last+1].second+dn-num1[i-1].second)%dn)*m);
			last=i-1;
		}
	}
	if(last<top1)push(find(val(num1[top1],m,n)),find(val(num1[last+1],m,n)),((num1[last+1].second+dn-num1[top1].second)%dn)*m);
	last=0;
	for(int i=2;i<=top2;i++){
		if(num2[i].first==num2[i-1].first){
			push(find(-val(num2[i-1],n,m)-1),find(-val(num2[i],n,m)-1),((num2[i].second+dm-num2[i-1].second)%dm)*n);
		}
		else{
			push(find(-val(num2[i-1],n,m)-1),find(-val(num2[last+1],n,m)-1),((num2[last+1].second+dm-num2[i-1].second)%dm)*n);
			last=i-1;
		}
	}
	if(last<top2)push(find(-val(num2[top2],n,m)-1),find(-val(num2[last+1],n,m)-1),((num2[last+1].second+dm-num2[top2].second)%dm)*n);
	printf("%I64d\n",dijkstra());
}
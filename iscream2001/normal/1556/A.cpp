#include<bits/stdc++.h>
#define LL long long
#define LD long double
#define pa pair<int,int>
using namespace std;
const LL P=998244353;
const int INF=1e9;
const int N=1e5+10;
const LL g=3;
static char ss[1<<17],*A=ss,*B=ss;
char gc(){
    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
int read(){
    int f=1,c; 
	while (c=gc(),c<48||c>57) if (c=='-') f=-1; 
	int x=c-'0';
    while(c=gc(),c>47&&c<58) x=x*10+c-'0'; 
	return f>0?x:-x;
}
LL qpow(LL x,LL y){
    LL re=1;
    while(y){
        if(y&1) re=re*x%P;
        x=x*x%P;y>>=1;	
    } 
    return re;
}
//bool is_pri[N+10];
//int pri[N],cntp=0;
//void init_pri(){
//    for(int i=2;i<=N;++i){
//        if(!is_pri[i]) {
//            pri[++cntp]=i;
//        }
//        for(int j=1;j<=cntp&&pri[j]*i<=N;++j){
//            is_pri[pri[j]*i]=1;
//            if(i%pri[j]==0) {
//                break;
//            }
//        }
//    }
//}

int n;
//
//#define ls id<<1
//#define rs id<<1|1
//
//struct seg{
//	int l,r;
//	LL mx,se,cnt;
//	LL lazy;
//}d[N*4];
//
//void pushup(int id){
//	if(d[id].l==d[id].r) return;
//	d[id].se=max(d[ls].se,d[rs].se);
//	d[id].mx=max(d[ls].mx,d[rs].mx);
//	d[id].cnt=0;
//	if(d[ls].mx==d[id].mx) d[id].cnt+=d[ls].cnt;
//	else d[id].se=max(d[id].se,d[ls].mx);
//	if(d[rs].mx==d[id].mx) d[id].cnt+=d[rs].cnt;
//	else d[id].se=max(d[id].se,d[rs].mx);
//	return;
//}
//
//void upd(int id,int c){
//	if(c>=d[id].lazy) return;
//	d[id].lazy=c;
//	if(d[id].mx>c) d[id].mx=c;
//	return;
//}
//
//void pushdown(int id){
//	if(d[id].l==d[id].r) return;
//	if(d[id].lazy<d[ls].lazy)upd(ls,d[id].lazy);
//	if(d[id].lazy<d[rs].lazy)upd(rs,d[id].lazy);
//	return;
//}
//
//void build(int l,int r,int id){
//	d[id].l=l;d[id].r=r;d[id].lazy=n;
//	if(l==r){
//		d[id].mx=n;
//		d[id].se=0;
//		d[id].cnt=1;
//		return;
//	}
//	int mid=(l+r)>>1;
//	build(l,mid,ls);
//	build(mid+1,r,rs);
//	pushup(id);
//	return;
//}
//
//LL co;
//LL re;
//void change(int r,int id){
//	pushdown(id);
//	if(co>=d[id].mx||d[id].l>r) return;
//	if(d[id].r>r) {
//		change(r,ls);
//		change(r,rs);
//		pushup(id);
//		return;
//	}
//	if(co>d[id].se){
//		re+=(d[id].mx-co)*d[id].cnt;
//		d[id].lazy=min(d[id].lazy,co);
//		d[id].mx=co;
//		return;
//	}
//	change(r,ls);
//	change(r,rs);
//	pushup(id);
//	return;
//}
//
//int a[N];
//vector<int> di[100005],V[100005];
//void init(){
//	for(int i=1;i<=100000;++i){
//		for(int j=i;j<=100000;j+=i){
//			di[j].push_back(i);
//		}
//	}
//}
//LL ans[100005];
void MAIN(){
	int u,v;
	scanf("%d%d",&u,&v);
	if((u&1)!=(v&1)) puts("-1");
	else if(u==0&&v==0) puts("0");
	else if(u==v) puts("1");
	else puts("2");
	return;
} 

int main(){
	//init();
	//srand(time(0));
	//init_pri();
	int ttt=1;scanf("%d",&ttt);
	while(ttt--) {
		MAIN();
	}
	return 0;
}
/*
*/
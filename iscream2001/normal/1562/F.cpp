#include<bits/stdc++.h>
#define LL long long
#define LD long double
#define pa pair<int,int>
using namespace std;
const LL P=998244353;
const int INF=1e9;
const int N=3e5;
bool is_pri[N+10];
int pri[N],cntp=0;
void init_pri(){
    for(int i=2;i<=N;++i){
        if(!is_pri[i]) {
            pri[++cntp]=i;
        }
        for(int j=1;j<=cntp&&pri[j]*i<=N;++j){
            is_pri[pri[j]*i]=1;
            if(i%pri[j]==0) {
                break;
            }
        }
    }
}
int n;
LL a[200005];
LL res[110][110];
LL ans[200005];
int q[200005];
LL re[200005];
int it;
LL cal(int x,int y){
	LL r=a[x]/__gcd(a[x],a[y])*a[y];
	//if(r<=0) puts("????????");
	return r;
}
bool check(int id,LL pp){
	LL w=0,r;
	for(int i=1;i<=15;++i){
		do{
			++it;
			if(it>=n) it=1;
		}while(q[it]==id);
		printf("? %d %d\n",id,q[it]);
		fflush(stdout);
		//r=cal(id,q[it]);
		scanf("%lld",&r);
		w=__gcd(w,r);
	}
	if(w==pp) return 1;
	return 0;
}
void sol(){
	if(abs(ans[1]-ans[2])<=2&&abs(ans[1]-ans[3])<=2&&abs(ans[3]-ans[2])<=2){
		return;
	}
	ans[1]/=2;
	if(abs(ans[1]-ans[2])<=2&&abs(ans[1]-ans[3])<=2&&abs(ans[3]-ans[2])<=2){
		return;
	}
	ans[1]*=2;
	ans[2]/=2;
	if(abs(ans[1]-ans[2])<=2&&abs(ans[1]-ans[3])<=2&&abs(ans[3]-ans[2])<=2){
		return;
	}
	ans[2]*=2;
	ans[3]/=2;
	if(abs(ans[1]-ans[2])<=2&&abs(ans[1]-ans[3])<=2&&abs(ans[3]-ans[2])<=2){
		return;
	}
	ans[3]*=2;
	return;
}
void MAIN(){
	int u,v;
	LL w;
	scanf("%d",&n);
	if(n<=100){
	//	u=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
			//	++u;
				printf("? %d %d\n",i,j);
				fflush(stdout);
				scanf("%lld",&res[i][j]);
				res[j][i]=res[i][j];
			}
		}
	//	cout<<u<<endl;
		for(int i=1;i<=n;++i){
			ans[i]=0;
			for(int j=1;j<=n;++j){
				if(i==j) continue;
				ans[i]=__gcd(ans[i],res[i][j]);
			}
		}
		if(n==3){
			sol();
		}
		printf("!");
		for(int i=1;i<=n;++i) printf(" %lld",ans[i]);
		puts("");
		fflush(stdout);
		return;
	}
	else{
//		while(1) u=0;
//		for(int i=1;i<=n;++i) a[i]=i+1;
//		random_shuffle(a+1,a+n+1);
		for(int i=1;i<n;++i)q[i]=i+1;
		random_shuffle(q+1,q+n);it=1;
		for(int i=1;i<=50;++i){
			printf("? %d %d\n",1,q[i]);
			fflush(stdout);
			scanf("%lld",&re[i]);
			//re[i]=cal(1,q[i]);
		}
		ans[1]=0;
		for(int i=1;i<=50;++i) ans[1]=__gcd(ans[1],re[i]);
		int now=1,tt=50,id=0;LL pp=0;
		//cout<<"??? "<<ans[1]<<" "<<a[1]<<endl;
		while(now<n&&tt<=4950){
			if(now>50){
				printf("? %d %d\n",1,q[now]);
				fflush(stdout);
				scanf("%lld",&re[now]);
				//re[now]=cal(1,q[now]);
				++tt;
			}
			w=re[now]/ans[1];
			//cout<<">> "<<w<<endl;
			if(w<=200000&&is_pri[w]==0&&w>=n/2&&w>pp){
				if(check(q[now],w)){
					pp=w;id=q[now];
				}
				tt+=15;
			}
			++now;
		}
		ans[id]=pp;
		//cout<<"!!! "<<id<<" "<<pp<<" "<<a[id]<<endl;
		for(int i=1;i<=n;++i){
			if(i==1||i==id) continue;
			printf("? %d %d\n",id,i);
			fflush(stdout);
			//ans[i]=cal(id,i);
			scanf("%lld",&ans[i]);
			ans[i]=ans[i]/pp;
		}
//		for(int i=1;i<=n;++i){
//			if(ans[i]!=a[i]) puts("?????????");
//		}
		printf("!");
		for(int i=1;i<=n;++i) printf(" %lld",ans[i]);
		puts("");
		fflush(stdout);
		return;
	}
	//fflush(stdout); 
	return;
} 

int main(){
	srand(time(0));
	init_pri();
	int ttt=1;scanf("%d",&ttt);
	while(ttt--) {
		MAIN();
	}
	return 0;
}
/*
5 4
1 2
2 3
3 4
4 5
*/
#include<bits/stdc++.h>
#define LL long long
#define ll long long
#define LD long double
using namespace std;
LL qpow(LL x,LL y,LL P=998244353){
	LL re;x%=P;
	for(re=1;y;y>>=1){if(y&1) re=re*x%P;x=x*x%P;}
	return re;
}
const LL P=1e9+7;
const int N=2e5+10;
const LL INF=2e18;
void init(){
}

int n,m;
LL sed,vm;
LL rnd(){
	LL ret = sed;
    sed = (sed * (LL) 7 + (LL) 13) % P;
    return ret;
}
struct Node{
	int l,r;
	LL x;
};
bool operator < (Node x,Node y){
	return x.r<y.r;
}
set<Node> S;
set<Node>::iterator it;
int tp;
pair<LL,int> q[N];
void MAIN(){
	S.clear();
	int op,l,r;
	LL x,y,ans;
	scanf("%d%d%lld%lld",&n,&m,&sed,&vm);
	for(int i=1;i<=n;++i){
		x = (rnd() % vm) + 1;
		S.insert((Node){i,i,x});
	}
	Node tmp1,tmp2;
	while(m--){
		op = (rnd() % 4) + 1;
    	l = (rnd() % n) + 1;
    	r = (rnd() % n) + 1;
    	if (l > r) 
         	swap(l, r);
    	if (op == 3){
    		x = (rnd() % (r - l + 1)) + 1;
		}
		else{
			x = (rnd() % vm) + 1;
		}
    	if (op == 4){
    		y = (rnd() % vm) + 1;
		}
        if(op==1){
        	for(int L=l;L<=r;){
        		tmp1=(Node){L,L,0};
        		it=S.lower_bound(tmp1);
        		tmp2=*it;
        		S.erase(it);
        		if(tmp2.l<L){
        			S.insert((Node){tmp2.l,L-1,tmp2.x});
        			tmp2.l=L;
				}
				if(tmp2.r>r){
					S.insert((Node){r+1,tmp2.r,tmp2.x});
        			tmp2.r=r;
				}
				tmp2.x+=x;
				S.insert(tmp2);
				L=tmp2.r+1;
			}
			continue;
		}
		if(op==2){
			for(int L=l;L<=r;){
        		tmp1=(Node){L,L,0};
        		it=S.lower_bound(tmp1);
        		tmp2=*it;
        		S.erase(it);
        		if(tmp2.l<L){
        			S.insert((Node){tmp2.l,L-1,tmp2.x});
        			tmp2.l=L;
				}
				if(tmp2.r>r){
					S.insert((Node){r+1,tmp2.r,tmp2.x});
        			tmp2.r=r;
				}
				//tmp2.x+=x;
				//S.insert(tmp2);
				L=tmp2.r+1;
			}
			S.insert((Node){l,r,x});
			continue;
		}
		if(op==3){
			tp=0;
			for(int L=l;L<=r;){
        		tmp1=(Node){L,L,0};
        		it=S.lower_bound(tmp1);
        		tmp2=*it;
        		//S.erase(it);
        		if(tmp2.l<L){
        			//S.insert((Node){tmp2.l,L-1,tmp2.x});
        			tmp2.l=L;
				}
				if(tmp2.r>r){
					//S.insert((Node){r+1,tmp2.r,tmp2.x});
        			tmp2.r=r;
				}
				//tmp2.x+=x;
				//S.insert(tmp2);
				q[++tp]=make_pair(tmp2.x,tmp2.r-tmp2.l+1);
				L=tmp2.r+1;
			}
			sort(q+1,q+1+tp);
			for(int i=1;i<=tp;++i){
				if(x<=q[i].second){
					printf("%lld\n",q[i].first);
					break;
				}
				else{
					x-=q[i].second;
				}
			}
			continue;
		}
		if(op==4){
			ans=0;
			for(int L=l;L<=r;){
        		tmp1=(Node){L,L,0};
        		it=S.lower_bound(tmp1);
        		tmp2=*it;
        		//S.erase(it);
        		if(tmp2.l<L){
        			//S.insert((Node){tmp2.l,L-1,tmp2.x});
        			tmp2.l=L;
				}
				if(tmp2.r>r){
					//S.insert((Node){r+1,tmp2.r,tmp2.x});
        			tmp2.r=r;
				}
				//tmp2.x+=x;
				//S.insert(tmp2);
				//q[++tp]=make_pair(tmp2.x,tmp2.r-tmp2.l+1);
				ans+=qpow(tmp2.x,x,y)*(LL)(tmp2.r-tmp2.l+1)%y;
				L=tmp2.r+1;
			}
			ans=(ans%y+y)%y;
			printf("%lld\n",ans);
		}
	}
	return;
}
/*
*/
int main(){
    init();
    int ttt=1;//scanf("%d",&ttt);
    while(ttt--) MAIN();
    return 0;    
}
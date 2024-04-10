#include <cstdio>
#include <vector>

struct BIT_2D{
	int n,m;
	std::vector<int>num[5001];
	void set(int a,int b){
		n=a,m=b;
		for(int i=1;i<=n;i++)num[i].resize(m+1);
	}
	void update(int x,int y,int delta){
		for(;x<=n;x+=x&-x){
			for(int tem=y;tem<=m;tem+=tem&-tem){
				num[x][tem]+=delta;
			}
		}
	}
	int query(int x,int y){
		int tot=0;
		for(;x;x-=x&-x)
			for(int tem=y;tem;tem-=tem&-tem)
				tot+=num[x][tem];
		return tot;
	}
}A,B,C;
int N,Q,opt,t1,t2,t3,t4;
int main(){
	scanf("%d%d",&N,&Q);
	A.set(N,N);
	B.set(N,N<<1);
	C.set(N,N<<1);
	for(int i=1;i<=Q;i++){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
			int flag=1;
			if(t1==3){
				A.update(t2-t4,t3,1);
				A.update(t2+1,t3,-1);
				A.update(t2-t4,t3+t4+1,-1);
				A.update(t2+1,t3+t4+1,1);
				t1=2,t2-=t4,t3+=t4,flag=-1,--t4;
			}
			if(t1==4){
				A.update(t2-t4,t3-t4,1);
				A.update(t2+1,t3-t4,-1);
				A.update(t2-t4,t3+1,-1);
				A.update(t2+1,t3+1,1);
				t1=1,t2-=t4,t3-=t4,flag=-1,--t4;
			}
			if(t1==1){
				A.update(t2,t3,flag);
				A.update(t2+t4+1,t3,-flag);
				B.update(t2,t2+t3+t4+1,-flag);
				B.update(t2+t4+1,t2+t3+t4+1,flag);
			}
			if(t1==2){
				A.update(t2,t3+1,-flag);
				A.update(t2+t4+1,t3+1,flag);
				C.update(t2,-t2+t3-t4+N,flag);
				C.update(t2+t4+1,-t2+t3-t4+N,-flag);
			}
		}
		else{
			scanf("%d%d",&t1,&t2);
			printf("%d\n",A.query(t1,t2)+B.query(t1,t1+t2)+C.query(t1,t2-t1+N));
		}
	}
}
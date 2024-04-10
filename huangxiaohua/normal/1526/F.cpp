#include<bits/stdc++.h>
using namespace std;

int x,y,z,i,j,k,n,m,t,cur,cx,cy,mx,r1,a[25][100500],r2,it,it1,lim,t2;
vector<int> v[100500];//
#define rd() ((rand()<<16|rand())%n+1)

int get(int x,int y,int z){
	if(x==y){exit(x);}
	if(x==z){exit(z);}
	if(z==y){exit(z);}
	printf("? %d %d %d\n",x,y,z);fflush(stdout);
	scanf("%d",&x);
	it++;
	return x;
}

void ask11(){
	x=y=z=0;int tmp;
	while(x==y||x==z||y==z||x==v[mx-1][0]||x==v[mx-1][1]||x==r1||y==v[mx-1][0]||y==v[mx-1][1]||y==r1||z==v[mx-1][0]||z==v[mx-1][1]||z==r1){
		x=rd();y=rd();z=rd();
	}
	tmp=get(x,y,z);
	if(tmp<cur){cur=tmp;cx=x;cy=y;}
}

void ask1(){
	x=y=z=0;int tmp;
	while(x==y||x==z||y==z){
		x=rd();y=rd();z=rd();
	}
	tmp=get(x,y,z);
	if(tmp<cur){cur=tmp;cx=x;cy=y;}
}

void ask2(int x){
	int y=get(cx,cy,x);v[y].push_back(x);mx=max(mx,y);
}

void work(){
	for(i=1;i<=n;i++){
		v[i].clear();
	}
	cur=1000000;cx=cy=0;
	for(i=1;i<=50;i++){
		if(it>=lim-2){return;}ask1();
	}
	mx=0;
	for(i=1;i<=n;i++){
		if(i==cx||i==cy){continue;}
		if(it>=lim-2){return;}ask2(i);
	}
	cur=1000000;cx=cy=0;
	r1=v[mx][0];
	if(v[mx-1].size()==2){
		int t1,t2,t3;
		for(i=1;i<=50;i++){
			if(it>=lim-2){return;}ask11();
		}
		if(it>=lim-2){return;}t1=get(cx,cy,r1);
		if(it>=lim-2){return;}t2=get(cx,cy,v[mx-1][0]);
		if(it>=lim-2){return;}t3=get(cx,cy,v[mx-1][1]);
		if(abs(t1-t2)==1){r2=v[mx-1][0];}
		else{r2=v[mx-1][1];}
	}
	else{
		r2=v[mx-1][0];
	}
	a[it1][r1]=1;a[it1][r2]=2;
	for(i=1;i<=n;i++){
		if(i==r1||i==r2){continue;}
		if(it>=lim-2){return;}a[it1][i]=get(r1,r2,i)+2;
	}
	it1++;
}

void ans(int sb){
	printf("! ");
	for(i=1;i<=n;i++){
		printf("%d ",a[sb][i]);
	}puts("");fflush(stdout);
	scanf("%*d");
}

int main(){
	srand(time(0));
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);t2++;
		lim=n*2+420;
		it=0;it1=1;
		while(1){
			work();
			if(it>=lim-2){break;}
			int k=a[it1-1][1]<a[it1-1][2];
			for(i=1;i<=n;i++){
				a[it1-1][i]=(k)?a[it1-1][i]:n+1-a[it1-1][i];
			}
		}
		it1--;
		if(it1==1){
			ans(1);continue;
		}
		for(i=1;i<=it1;i++){
			for(j=i+1;j<=it1;j++){
				for(k=1;k<=n;k++){
					if(a[i][k]!=a[j][k]){goto aaa;}
				}
				ans(i);goto bbb;
				aaa:;
			}
		}
		return t2;
		bbb:;
	}
}
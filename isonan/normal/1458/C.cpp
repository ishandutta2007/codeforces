#include <cstdio>

struct matrix{
	int ord;
	int m1,m2,d;
	bool t;
	void moveright(){
		if(!t)++m2;
		else ++m1;
	}
	void moveleft(){
		if(!t)--m2;
		else --m1;
	}
	void moveup(){
		if(!t)--m1;
		else --m2;
	}
	void movedown(){
		if(!t)++m1;
		else ++m2;
	}
	void add(int x){
		d+=x;
	}
	void turn(){
		t^=1;
	}
}a,b,c;
int t,n,m,map[1001][1001],tem[1001];
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d",&n,&m);
		a=(matrix){0,0,0,0,0};
		b=(matrix){1,0,0,0,0};
		c=(matrix){2,0,0,0,0};
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&map[i][j]);
		for(int i=1;i<=m;i++){
			char ch=getchar();
			while(ch<'A'||ch>'Z')ch=getchar();
			switch(ch){
				case 'L':{
					a.moveleft();
					c.moveleft();
					b.add(n-1);
					break;
				}
				case 'R':{
					a.moveright();
					c.moveright();
					b.add(1);
					break;
				}
				case 'D':{
					a.movedown();
					b.movedown();
					c.add(1);
					break;
				}
				case 'U':{
					a.moveup();
					b.moveup();
					c.add(n-1);
					break;
				}
				case 'I':{
					matrix t=a;
					a=b;
					b=t;
					c.turn();
					break;
				}
				case 'C':{
					matrix t=a;
					a=c;
					c=t;
					b.turn();
					break;
				}
			}
		}
		if(a.ord==1){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++)
					tem[map[i][j]]=j;
				for(int j=1;j<=n;j++)map[i][j]=tem[j];
			}
		}
		else if(a.ord==2){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++)
					tem[map[j][i]]=j;
				for(int j=1;j<=n;j++)map[j][i]=tem[j];
			}
		}
//		a.m1=0;
//		printf("%d %d %d %d %d\n",a.ord,a.m1,a.m2,a.d,a.t);
		for(int i=1;i<=n;i++,putchar('\n'))
			for(int j=1;j<=n;j++){
				int nx,ny;
				if(a.t){
					nx=(j-(a.m1%n)+n)%n,ny=(i-(a.m2%n)+n)%n;
				}
				else{
					nx=(i-(a.m1%n)+n)%n,ny=(j-(a.m2%n)+n)%n;
				}
				if(!nx)nx=n;
				if(!ny)ny=n;
				int v=(map[nx][ny]+(a.d%n)+n)%n;
//				printf("\n%d %d %d %d\n",i,j,nx,ny);
				if(!v)v=n;
				printf("%d ",v);
			}
				
	}
}
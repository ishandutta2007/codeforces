#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a;i<=b;i++)
#define fd(i,a,b)for(int i=b;i>=a;i--)
#define L long long
#define mo 1000000007
using namespace std;
const int Mn=3333;
int gN,p,k,su,f[Mn][Mn][2][2];
L N[Mn],P[Mn],ans;
char c;
int div(){
	L y=0;
	fd(i,1,gN)y=N[i]+y*1000000000,N[i]=y/p,y%=p;
	if(!N[gN])gN--;
	return y;
}
int main(){
	scanf("%d%d\n",&p,&k);
	while((c=getchar())>='0'&&c<='9')N[++gN]=c-48;
	fo(i,1,gN/2)swap(N[i],N[gN-i+1]);
	fo(i,1,gN/9){su=0;fd(j,(i-1)*9+1,i*9)su=su*10+N[j];N[i]=su;}
	if(gN%9){su=0;fd(j,gN/9*9+1,gN)su=su*10+N[j];N[gN/9+1]=su;}
	gN=gN/9+(gN%9?1:0);
	while(gN)P[++P[0]]=div();
	if(P[0]<k){putchar('0');return 0;}
	f[0][0][0][0]=1;
	fo(i,0,P[0]-1)fo(j,0,i){
		f[i+1][j][0][0]=((L)f[i+1][j][0][0]+((P[i+1]+1)*(P[i+1]+2)/2)%mo*(L)f[i][j][0][0]%mo+
					(P[i+1]*(P[i+1]+1)/2)%mo*(L)f[i][j][1][0]%mo+
					P[i+1]*(P[i+1]-1)/2%mo*(L)f[i][j][1][1]%mo+
					P[i+1]*(P[i+1]+1)/2%mo*(L)f[i][j][0][1]%mo)%mo;
		f[i+1][j+1][0][1]=((L)f[i+1][j+1][0][1]+((P[i+1]+1)*(2*p-2-P[i+1])/2)%mo*(L)f[i][j][0][0]%mo+
					((2*p-P[i+1])*(P[i+1]+1)/2)%mo*(L)f[i][j][0][1]%mo+
					(P[i+1]*(2*p-1-P[i+1])/2)%mo*(L)f[i][j][1][0]%mo+
					(P[i+1]*(2*p-P[i+1]+1)/2)%mo*(L)f[i][j][1][1]%mo)%mo;
		f[i+1][j][1][0]=((L)f[i+1][j][1][0]+((P[i+1]+p+2)*(p-P[i+1]-1)/2)%mo*(L)f[i][j][0][0]%mo+
					(P[i+1]+p)*(p-P[i+1]-1)/2%mo*(L)f[i][j][0][1]%mo+
					((p+P[i+1]+1)*(p-P[i+1])/2)%mo*(L)f[i][j][1][0]%mo+
					(p+P[i+1]-1)*(p-P[i+1])/2%mo*(L)f[i][j][1][1]%mo)%mo;	
		f[i+1][j+1][1][1]=((L)f[i+1][j+1][1][1]+((p-2-P[i+1])*(p-P[i+1]-1)/2)%mo*(L)f[i][j][0][0]%mo+
					((p-P[i+1])*(p-P[i+1]-1)/2)%mo*(L)f[i][j][0][1]%mo+
					((p-1-P[i+1])*(p-P[i+1])/2)%mo*(L)f[i][j][1][0]%mo+
					((p-P[i+1]+1)*(p-P[i+1])/2)%mo*(L)f[i][j][1][1]%mo)%mo;
	}
	fo(i,k,P[0])ans+=(L)f[P[0]][i][0][0];
	printf("%lld",ans%=mo+(ans<0?mo:0));
}
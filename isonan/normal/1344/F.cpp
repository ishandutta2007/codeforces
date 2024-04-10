#include <cstdio>
#include <bitset>
#include <utility>
#include <cstring>

int n,k;
int stk[1001],m,v[1001][2][2],cnt,ans[2001];
int mat[2][2],tem[2][2];
char str[11];
void mul(int a[2][2],int b[2][2]){
	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j)
			tem[i][j]=(a[i][0]&b[0][j])^(a[i][1]&b[1][j]);
	memcpy(a,tem,sizeof a);
}
std::bitset<2010>map[2010];
int Pos[2010];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)v[i][0][0]=v[i][1][1]=1;
	for(int i=1;i<=k;++i){
		scanf("%s%d",str+1,&m);
		for(int j=1;j<=m;++j)scanf("%d",stk+j);
		if(str[1]=='m'){
			char ch=getchar();
			while(ch<'A'||ch>'Z')ch=getchar();
			for(int b=0;b<2;++b){
				++cnt;
				for(int j=1;j<=m;++j)
					map[cnt][(stk[j]<<1)-1]=v[stk[j]][b][0],
					map[cnt][(stk[j]<<1)-0]=v[stk[j]][b][1];
			}
			map[cnt-1][(n<<1)+1]=ch=='R'||ch=='B';
			map[cnt-0][(n<<1)+1]=ch=='Y'||ch=='B';
		}
		else{
			char c1='R'+'Y'+'B'-str[1]-str[2];
			for(int j=1;j<=m;++j)
				if(c1=='B')std::swap(v[stk[j]][0],v[stk[j]][1]);
				else if(c1=='Y')v[stk[j]][1][0]^=v[stk[j]][0][0],v[stk[j]][1][1]^=v[stk[j]][0][1];
				else v[stk[j]][0][0]^=v[stk[j]][1][0],v[stk[j]][0][1]^=v[stk[j]][1][1];
		}
	}
	for(int i=1,now=1;i<=(n<<1)&&now<=cnt;++i,++now){
		for(int j=now;j<=cnt;++j)
			if(map[j][i]==1){
				std::swap(map[now],map[j]);
				break;
			}
		if(map[now][i]==0){
			--now;
			continue;
		}
		Pos[now]=i;
		for(int j=now+1;j<=cnt;++j)
			if(map[j][i]==1)map[j]^=map[now];
	}
	for(int i=cnt;i;--i)
		for(int j=i-1;j;--j)
			if(map[j][Pos[i]]==1)map[j]^=map[i];
	for(int i=1;i<=cnt;++i){
		if(!Pos[i]&&map[i][(n<<1)+1]==1){
			puts("NO");
			return 0;
		}
		ans[Pos[i]]=(int)map[i][(n<<1)+1];
	}
	puts("YES");
	for(int i=1;i<=n;++i){
		switch((ans[(i<<1)-1]<<1)|ans[i<<1]){
			case 0:{
				putchar('.');
				break;
			}
			case 1:{
				putchar('Y');
				break;
			}
			case 2:{
				putchar('R');
				break;
			}
			case 3:{
				putchar('B');
				break;
			}
		}
	}
}
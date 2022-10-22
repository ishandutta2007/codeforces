#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[8][3],b[8][3];
long long dis[28];
int tot;
bool chk(){
	int i,j;
	int cnt=0;
	for(i=0;i<8;++i){
		for(j=0;j<i;++j){
			long long x=a[i][0]-a[j][0];
			long long y=a[i][1]-a[j][1];
			long long z=a[i][2]-a[j][2];
			dis[cnt]=x*x+y*y+z*z;
			if(!dis[cnt])return 0;
			++cnt;
		}
	}
	sort(dis,dis+28);
	for(i=0;i<12;++i)if(dis[i]!=dis[0])return 0;
	for(i=0;i<12;++i)if(dis[i+12]!=dis[0]*2)return 0;
	for(i=0;i<4;++i)if(dis[i+24]!=dis[0]*3)return 0;
	return 1;
}
void solve(int i){
	if(i==8){
		if(chk()){
			puts("YES");
			for(int j=0;j<8;++j)for(int k=0;k<3;++k){
				printf("%d",a[j][k]);
				if(k==2)putchar('\n');else putchar(' ');
			}
			exit(0);
		}
		return;
	}
	int id[3]={0,1,2};
	do{for(int j=0;j<3;++j)a[i][j]=b[i][id[j]];solve(i+1);}
	while(next_permutation(id,id+3));
}
int main(){
	for(int i=0;i<8;++i)scanf("%d%d%d",a[i],a[i]+1,a[i]+2);
	memcpy(b,a,sizeof b);
	solve(1);
	puts("NO");return 0;
}
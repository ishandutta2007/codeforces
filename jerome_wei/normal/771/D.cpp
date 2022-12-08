#include<bits/stdc++.h>
using namespace std;
const int N=110;
int read(){
	char x=0;while(x<'A'||x>'Z')x=getchar();
	if(x=='V')return 1;if(x=='K')return 2;return 0;
}
int ch[N],sz[3];
int f[N][N][N][2];
vector<int> pos[3];
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		ch[i]=read();
		pos[ch[i]].push_back(i);
		sz[ch[i]]++;
	}
	//cout<<sz[0]<<"   ,   "<<sz[1]<<"   ,   "<<sz[2]<<endl;
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)for(int k=0;k<=n;k++)f[i][j][k][0]=f[i][j][k][1]=0x3f3f3f3f;
	f[0][0][0][0]=0;
	for(int i=0;i<=sz[0];i++)for(int j=0;j<=sz[1];j++)for(int k=0;k<=sz[2];k++)if(i||j||k){
		//cout<<i<<" "<<j<<" "<<k<<"  ";
		int id=i+j+k;
		//others
		if(i){
			int t=pos[0][i-1],cnt=0 ;
			for(int x=i;x<pos[0].size()&&pos[0][x]<t;x++)++cnt;
			for(int x=j;x<pos[1].size()&&pos[1][x]<t;x++)++cnt;
			for(int x=k;x<pos[2].size()&&pos[2][x]<t;x++)++cnt;
			//cout<<"O"<<cnt;
			f[i][j][k][0]=min(f[i-1][j][k][0]+cnt ,f[i][j][k][0]);
			f[i][j][k][0]=min(f[i-1][j][k][1]+cnt ,f[i][j][k][0]);
		}
		//V
		if(j){
			int t=pos[1][j-1],cnt=0;
			for(int x=i;x<pos[0].size()&&pos[0][x]<t;x++)++cnt;
			for(int x=j;x<pos[1].size()&&pos[1][x]<t;x++)++cnt;
			for(int x=k;x<pos[2].size()&&pos[2][x]<t;x++)++cnt;
			//cout<<"V"<<cnt;
			//cout<<"V!"<<max(0,id-t);
			f[i][j][k][1]=min(f[i][j-1][k][0]+cnt ,f[i][j][k][1]);
			f[i][j][k][1]=min(f[i][j-1][k][1]+cnt ,f[i][j][k][1]);
		}
		//K
		if(k){
			int t=pos[2][k-1],cnt=0;
			for(int x=i;x<pos[0].size()&&pos[0][x]<t;x++)++cnt;
			for(int x=j;x<pos[1].size()&&pos[1][x]<t;x++)++cnt;
			for(int x=k;x<pos[2].size()&&pos[2][x]<t;x++)++cnt;
			//cout<<"K"<<cnt;
			//cout<<"K!"<<max(0,id-t);
			f[i][j][k][0]=min(f[i][j][k-1][0]+cnt ,f[i][j][k][0]);
		}//puts("");
		//cout<<f[i][j][k][0]<<' '<<f[i][j][k][1]<<endl;
	}
//	puts("");
	cout<<min(f[sz[0]][sz[1]][sz[2]][0],f[sz[0]][sz[1]][sz[2]][1])<<endl;
}
#include<bits/stdc++.h>
using namespace std;
const int N = 2010;
bitset<N> b[N];
/* 
[0\\0]
[1\\0]
[0\\1]
[1\\1]
RY:
0 1
1 0
RB:
1 0
1 1
YB:
1 1
0 1
 */

int s[N][2][2];

void perform(int x,int type){
	if(type==1){
		swap(s[x][0],s[x][1]);
	}
	else if(type==2){
		int nw[2][2]={{0,0},{0,0}};
		for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++){
			if(i==0&&j==1)continue;//1->0 : no contribution
			nw[i][k]^=s[x][j][k];
		}
		for(int i=0;i<2;i++)for(int j=0;j<2;j++)s[x][i][j]=nw[i][j];
	}
	else if(type==3){
		int nw[2][2]={{0,0},{0,0}};
		for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++){
			if(i==1&&j==0)continue;//0->1 : no contribution
			nw[i][k]^=s[x][j][k];
		}
		for(int i=0;i<2;i++)for(int j=0;j<2;j++)s[x][i][j]=nw[i][j];
	}
}
int cnt=0,n,q;
const char cvt[4]={'.','R','Y','B'};
inline void Solve(vector<int> st,int w){
	b[++cnt][n*2+1]=w=='R'||w=='B';
	for(int i=0;i<(int)st.size();i++){
		int x=st[i];
		int v1 = s[x][0][0];
		int v2 = s[x][0][1];
		b[cnt][x*2-1]=v1,b[cnt][x*2]=v2;
	}
	b[++cnt][n*2+1]=w=='Y'||w=='B';
	for(int i=0;i<(int)st.size();i++){
		int x=st[i];
		int v1 = s[x][1][0];
		int v2 = s[x][1][1];
		b[cnt][x*2-1]=v1,b[cnt][x*2]=v2;
	}
}
int v[N];
int ans[N];
inline void guass(){
	// cerr << n << endl;
	// for(int i=1;i<=cnt;i++){
	// 	for(int j=1;j<=n*2+1;j++)cout << b[i][j] << " ";puts("");
	// }
	int h=0;
	for(int i=1;i<=n*2;i++){
		int p=0;
		for(int j=h+1;j<=cnt;j++)if(b[j][i]){p=j;break;}
		if(!p)continue;
		swap(b[p],b[h+1]);
		v[++h]=i;
		// cout << h << " " << i << "|";
		// for(int j=1;j<=n*2+1;j++)cout << b[h][j] << " ";puts("");
		for(int j=h+1;j<=cnt;j++)if(b[j][i])b[j]^=b[h];
	}

	
	// for(int i=1;i<=cnt;i++){
	// 	for(int j=1;j<=n*2+1;j++)cout << b[i][j] << " ";puts("");
	// }
	for(int i=h;i;i--){
		for(int j=i-1;j;j--){
			if(b[j][v[i]]){
				// cout << j << "<-" << i << endl;
				b[j]^=b[i];
			}
		}
		
	}
	
	// for(int i=1;i<=cnt;i++){
	// 		for(int j=1;j<=n*2+1;j++)cout << b[i][j] << " ";puts("");
	// 	}
	// 	puts("-<>-");
	for(int i=h+1;i<=cnt;i++){
		if(b[i][n*2+1]){
			puts("NO");return ;
		}
	}
	for(int i=1;i<=h;i++){
		// cout << b[i][n*2+1] << ":" << v[i+1]
		ans[(v[i]+1)/2]|=(int)b[i][n*2+1]<<((v[i]+1)%2);
	}
	
	puts("YES");
	// printf("%c",'.');
	for(int i=1;i<=n;i++){
		// cout << i << ":" << n << ":" << ans[i] << endl;
		// cout << ans[i] << " " << cvt[ans[i]] << endl;
		printf("%c",cvt[ans[i]]);
		// cout << "???" << endl;
	}
	puts("");
}

int main()
{
	cin >> n >> q;
	for(int i=1;i<=n;i++)s[i][0][0]=s[i][1][1]=1;
	while(q--){
		char s[5];
		scanf("%s",s);
		if(s[0]=='m'){
			int d;scanf("%d",&d);
			vector<int> st;
			while(d--){
				int x;scanf("%d",&x);
				st.push_back(x);
			}
			scanf("%s",s);
			Solve(st,s[0]);
		}else{
			int t=0;
			if(s[0]=='R'&&s[1]=='Y')t=1;
			if(s[0]=='R'&&s[1]=='B')t=2;
			if(s[0]=='Y'&&s[1]=='B')t=3;
			int d;scanf("%d",&d);
			while(d--){
				int x;scanf("%d",&x);
				perform(x,t);
			}
		}
	}
	guass();
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5,maxs=(1<<6)+5;
int n;
char s[maxn];
char can[7];
int num[6];
bool ban[maxn][6];
int suf[maxs][maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
    scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i++)num[s[i]-'a']++;
	int m;
	m=read();
	for(int i=1;i<=m;i++){
		int pos,len;
		pos=read();
		scanf("%s",can+1);len=strlen(can+1);
		for(int j=0;j<6;j++)ban[pos][j]=1;
		for(int j=1;j<=len;j++)ban[pos][can[j]-'a']=0;
	}
	int S=(1<<6)-1;
	for(int i=n;i>=1;i--){
		for(int s=1;s<=S;s++){
			int tag=0;
			for(int c=0;c<6;c++)if(((s>>c)&1)&&!ban[i][c]){tag=1;break;}
			suf[s][i]=suf[s][i+1]+tag;
		}
	}
	bool tag=1;
	for(int s=1;s<=S;s++){
		int cur=0;
		for(int j=0;j<6;j++)if((s>>j)&1)cur+=num[j];
		if(cur>suf[s][1]){tag=0;break;}
	}
	if(!tag){puts("Impossible");return 0;}
	for(int i=1;i<=n;i++){
		for(int c=0;c<6;c++){
			if(!num[c]||ban[i][c])continue;
			num[c]--;
			bool flag=1;
			for(int s=1;s<=S;s++){
				int cur=0;
				for(int j=0;j<6;j++)if((s>>j)&1)cur+=num[j];
				if(cur>suf[s][i+1]){flag=0;break;}
			}
			if(!flag){num[c]++;continue;}
			printf("%c",'a'+c);break;
		}
	}
    return 0;
}
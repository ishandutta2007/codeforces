#include <cstdio>

int T,n;
char str[3][200001];
bool bb[3];
void solve(int a,int b){
//	printf("solve %d %d\n",a,b);
	char ch=bb[a]?'1':'0';
	int ans=0;
	for(int i=1,j=1,k=1;i<=(n<<1);++i){
		int cnt0=0,cnt1=0;
		while(j<=(n<<1)&&str[a][j]!=ch)++j,++cnt0;
		while(k<=(n<<1)&&str[b][k]!=ch)++k,++cnt1;
		if(cnt0<cnt1)cnt0=cnt1;
//		printf("\n&%d\n",cnt0);
		for(int l=1;l<=cnt0&&ans<=(n*3);++l)putchar(ch^1),++ans;
		if((j<=(n<<1)&&str[a][j]==ch)||(k<=(n<<1)&&str[b][k]==ch))putchar(ch),++ans;
		if(j>(n<<1)&&k>(n<<1))break;
		if(j<=(n<<1))++j;
		if(k<=(n<<1))++k;
	}
	while(ans<(n*3))putchar(ch^1),++ans;
}
int main(){
	scanf("%d",&T);
	for(int fd=1;fd<=T;++fd){
		scanf("%d",&n);
		for(int i=0;i<3;++i){
			scanf("%s",str[i]+1);
			int cnt=0;
			for(int j=1;j<=(n<<1);++j)cnt+=(str[i][j]=='1');
			bb[i]=(cnt>=n);
		}
		if(bb[0]==bb[1])solve(0,1);
		else if(bb[0]==bb[2])solve(0,2);
		else if(bb[2]==bb[1])solve(2,1);
		putchar('\n');
	}
}
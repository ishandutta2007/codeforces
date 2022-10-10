#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0;do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=410;
int get2(){
	char c;
	do c=getchar();while(c!='0' && c!='1');
	return c=='1';
}
int i,j,k,n,m,T,a[maxn][maxn],s[maxn][maxn];
int get(int x1,int y1,int x2,int y2){
	//cout<<"get "<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<' '<<s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1]<<endl;
	if(x1>x2 || y1>y2)exit(1);
	return s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1];
}
int main(){
	cin>>T;
	while(T--){
		int ans=1e9;
		cin>>n>>m;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)a[i][j]=get2(),s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
		//cout<<"n="<<n<<' '<<m<<endl;
		for(int x1=1;x1<=n;x1++)
			for(int x2=x1+4;x2<=n;x2++){
				int Min=1e9;
				for(int y1=1;y1<=m;y1++){
					//cout<<"y1="<<y1<<endl;
					int need=(x2-x1-1)-get(x1+1,y1,x2-1,y1);
					int l=1;
					if(y1>=4){
						//cout<<"---"<<endl;
						int w=get(x1+1,y1-2,x2-1,y1-1);
						//cout<<x1<<' '<<x2<<' '<<y1<<' '<<l<<' '<<w+need<<endl;
						Min+=get(x1+1,y1-1,x2-1,y1-1)+(1-a[x1][y1-1])+(1-a[x2][y1-1]);
						//cout<<"w="<<w<<' '<<y1<<endl;
						w+=(x2-x1-1-get(x1+1,y1-1-2,x2-1,y1-1-2));
						//cout<<"w="<<w<<endl;
						w+=(2-get(x1,y1-2,x1,y1-1))+(2-get(x2,y1-2,x2,y1-1));
						//cout<<"w="<<w<<' '<<Min<<endl;
						if(w<Min)Min=w,l=y1-1-2;
						//if(w+need==9){cout<<x1<<' '<<x2<<' '<<y1<<' '<<l<<' '<<w<<' '<<need<<endl;}
						ans=min(ans,Min+need);
					}
				}
			}
		printf("%d\n",ans);
	}
}
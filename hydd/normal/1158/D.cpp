/*********************************************************************
 * Source
 * ProblemCF1158D
 * Authorhydd
 * Date2020/9/9
 * EncodingSimplified Chinese (GB2312)
*********************************************************************/
#include<cstdio>
//#define File(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
typedef long long ll;
int n,x[110000],y[110000],p[110000];
char s[110000];
bool vis[110000];
inline ll cross(int x1,int y1,int x2,int y2){ return 1ll*x1*y2-1ll*x2*y1;}
inline ll cross(int i,int j,int k){ return cross(x[j]-x[i],y[j]-y[i],x[k]-x[i],y[k]-y[i]);}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		if (!p[1]||x[i]<x[p[1]]) p[1]=i; 
	}
	scanf("%s",s+1);
	vis[p[1]]=true;
	for (int i=1;i<=n-2;i++){
		int tmp=0;
		for (int j=1;j<=n;j++){
			if (vis[j]) continue;
			if (!tmp||s[i]=='L'&&cross(p[i],j,tmp)>0
					||s[i]=='R'&&cross(p[i],j,tmp)<0) tmp=j;
		}
		p[i+1]=tmp; vis[tmp]=true;
	}
	for (int i=1;i<=n-1;i++) printf("%d ",p[i]);
	for (int i=1;i<=n;i++)
		if (!vis[i]) printf("%d\n",i);
	return 0;
}
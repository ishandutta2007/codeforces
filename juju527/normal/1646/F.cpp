//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=105,maxs=1e4+5;
vec a[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int len;
int op[maxs][maxn];
int main(){
    int n;
	n=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i].eb(read());
	while(1){
		int p=0,lst;
		for(int i=1;i<=n;i++){
			sort(a[i].begin(),a[i].end());
			int tag=0;
			for(int j=1;j<n;j++)if(a[i][j]==a[i][j-1])tag=a[i][j];
			if(tag){
				len++;
				p=i,lst=tag;op[len][i]=lst;
				a[i].erase(find(a[i].begin(),a[i].end(),lst));
				break;
			}
		}
		if(!p)break;
		for(int i=p%n+1;i!=p;i=i%n+1){
			sort(a[i].begin(),a[i].end());
			int tag=0;
			for(int j=1;j<n;j++)if(a[i][j]==a[i][j-1])tag=a[i][j];
			a[i].eb(lst);
			if(tag)lst=tag;
			op[len][i]=lst;
			a[i].erase(find(a[i].begin(),a[i].end(),lst));
		}
		a[p].eb(lst);
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			len++;
			for(int x=1;x<=n;x++)op[len][x]=(x+i-j+n)%n;
		}
	}
	printf("%d\n",len);
	for(int i=1;i<=len;i++,puts(""))
		for(int j=1;j<=n;j++)
			printf("%d ",(!op[i][j])?n:op[i][j]);
    return 0;
}
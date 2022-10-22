#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxs=(1<<18)+5;
char s[maxs];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int sa[maxs],x[maxs],t[maxs],y[maxs];
int main(){
    int n,m,w=26;
	n=read();m=(1<<n);
	scanf("%s",s);
	for(int i=0;i<m;i++)t[x[i]=s[i]-'a']++;
	for(int i=1;i<w;i++)t[i]+=t[i-1];
	for(int i=m-1;i>=0;i--)sa[--t[x[i]]]=i;
	for(int k=1;k<m;k<<=1){
		for(int i=0;i<m;i++)y[i]=sa[i]^k;
		for(int i=0;i<w;i++)t[i]=0;
		for(int i=0;i<m;i++)t[x[y[i]]]++;
		for(int i=1;i<w;i++)t[i]+=t[i-1];
		for(int i=m-1;i>=0;i--)sa[--t[x[y[i]]]]=y[i],y[i]=0;
		swap(x,y);
		w=0;
		x[sa[0]]=w;
		for(int i=1;i<m;i++)
			x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]^k]==y[sa[i-1]^k])?w:++w;
		w++;
	}
	int p=sa[0];
	for(int i=0;i<m;i++)printf("%c",s[i^p]);
	puts("");
    return 0;
}
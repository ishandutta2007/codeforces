//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define vec vector<int>
#define eb emplace_back
using namespace std;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int cnt[105];
int main(){
    int T;
	T=read();
	while(T--){
		int n,c,res=0;
		n=read();c=read();
		for(int i=1;i<=100;i++)cnt[i]=0;
		for(int i=1;i<=n;i++)cnt[read()]++;
		for(int i=1;i<=100;i++)res+=min(cnt[i],c);
		printf("%d\n",res);
	}
    return 0;
}
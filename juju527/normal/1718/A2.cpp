//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
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
map<int,int> mp;
int main(){
	int T;
	T=read();
    while(T--){
		int n,s=0,res;
		n=read();res=n;
		mp.clear();mp[0]=1;
		for(int i=1;i<=n;i++){
			s^=read();
			if(mp[s])res--,mp.clear();
			mp[s]=1;
		}
		printf("%d\n",res);
	}
    return 0;
}
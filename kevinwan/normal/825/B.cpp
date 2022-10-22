#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll mod=998244353;
const int mn=3e2+10;
string g[10];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    for(int i=0;i<10;i++)cin>>g[i];
    for(int i=0;i<10;i++)for(int j=0;j<10;j++){
    	if(g[i][j]=='X')g[i][j]=1;
    	else if(g[i][j]=='O')g[i][j]=5;
    	else g[i][j]=0;
    }
    bool ans=0;
    for(int i=0;i<10;i++)for(int j=0;j<6;j++){
    	int sum=0;
    	for(int k=0;k<5;k++)sum+=g[i][j+k];
    	if(sum==4)ans=1;
    	sum=0;
    	for(int k=0;k<5;k++)sum+=g[j+k][i];
    	if(sum==4)ans=1;
    }
    for(int i=0;i<6;i++)for(int j=0;j<6;j++){
    	int sum=0;
    	for(int k=0;k<5;k++)sum+=g[i+k][j+k];
    	if(sum==4)ans=1;
    }
    for(int i=0;i<6;i++)for(int j=4;j<10;j++){
    	int sum=0;
    	for(int k=0;k<5;k++)sum+=g[i+k][j-k];
    	if(sum==4)ans=1;
    }
    printf("%s",ans?"YES":"NO");
}
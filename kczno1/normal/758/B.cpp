#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=105,D=1e9+7;
const char ch[]={"RBYG"};
int n;char s[N];
bool vis[1000];
char dy[4];int cnt[4];

int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    rep(i,1,n) 
	if(s[i]=='!') ++cnt[i%4];
	else {vis[s[i]]=1;dy[i%4]=s[i];}
    
    rep(i,0,3)
    if(!dy[i])
    rep(j,0,3)
    if(!vis[ch[j]])
     dy[i]=ch[j];
    
    rep(i,0,3) 
	rep(j,0,3) 
	if(dy[j]==ch[i])printf("%d ",cnt[j]);
}
#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

const int maxn=2e5+10;

int ecnt,h[maxn],din[maxn],dou[maxn];
struct edges{
  int nxt,to;
}E[maxn];
void addline(int u,int v){
  E[++ecnt]={h[u],v},h[u]=ecnt,din[v]++,dou[u]++;
}
int trans(char a,char b){return 130*a+b;}

string ans;
void dfs(int u){
  int&i=h[u];
  while(i){
    int v=E[i].to;i=E[i].nxt,dfs(v);
  }
  ans+=u%130;
}

int main(){
  int n;cin>>n;
  rep(i,1,n){
    char str[5];scanf("%s",str);
    addline(trans(str[0],str[1]),trans(str[1],str[2]));
  }
  int S=-1,T=-1,tp=-1;bool asf=1;
  rep(i,1,114514){
    if(din[i]==dou[i]-1){
      asf&=S==-1,S=i;
    }else if(din[i]==dou[i]+1){
      asf&=T==-1,T=i;
    }else if(din[i]!=dou[i]){
      asf=0;
    }else if(din[i])tp=i;
  }
  if(((S==-1)^(T==-1))||!asf)return puts("NO"),0;
  if(S==-1)S=tp;
  dfs(S),ans+=S/130;
  if((int)ans.size()<n+2)return puts("NO"),0;
  printf("YES\n");
  reverse(ans.begin(),ans.end()),cout<<ans<<endl;
  return 0;
}
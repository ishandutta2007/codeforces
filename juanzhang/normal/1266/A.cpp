#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

int main(){
  int T;cin>>T;while(T--){
    char str[105];
    scanf("%s",str+1);
    int len=strlen(str+1);
    int cnt[10];
    memset(cnt,0,sizeof cnt);
    bool flg=0;int su=0;
    rep(i,1,len)flg|=str[i]=='0',su+=str[i]-48,cnt[str[i]-48]++;
    if(flg&&su%3==0){
      bool asf=cnt[0]>1;
      rep(i,1,9)if(i%2==0&&cnt[i])asf=1;
      if(asf){
        puts("red");continue;
      }
    }
    puts("cyan");
  }
  return 0;
}
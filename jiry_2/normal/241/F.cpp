#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
struct bian{
    int next,point,w;
}b[60000];
int p[11000],tim,len,n,m,pd[110][110],f[110][110],gox[4]={1,0,-1,0},goy[4]={0,1,0,-1},where[26],w[26][26],d[11000],bo[11000],s,t;
char getin(){
    char ch=getchar(); while (ch!='#'&&(ch<'0'||ch>'9')&&(ch<'a'||ch>'z')) ch=getchar(); return ch;
}
void add(int k1,int k2,int k3){
    b[++len]=(bian){p[k1],k2,k3}; p[k1]=len;
}
queue<int>Q;
int get(){
    int k1,k2; scanf("%d%d",&k1,&k2); return f[k1][k2];
}
char ch[2000];
void spfa(int s){
    memset(d,0x3f,sizeof d); memset(bo,0x00,sizeof bo);
    d[s]=0; bo[1]=1; Q.push(s);
    while (!Q.empty()){
        int k=Q.front();
        for (int i=p[k];i;i=b[i].next){
            int j=b[i].point;
            if (d[j]>d[k]+b[i].w){
                d[j]=d[k]+b[i].w;
                if (bo[j]==0){
                    bo[j]=1; Q.push(j);
                }
            }
        }
        Q.pop(); bo[k]=0;
    }
}
void print(int s,int t,int d){
    int k1=(s-1)/m+1,k2=(s-1)%m+1;
    int k3=(t-1)/m+1,k4=(t-1)%m+1;
//  cout<<s<<" "<<t<<" "<<d<<" "<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<endl;
    if (k1==k3){
        if (k2<=k4){
            for (int i=k2;i<=k4;i++) if (pd[k1][i]>tim) {printf("%d %d\n",k1,i); return;} else tim-=pd[k1][i];
        } else {
            for (int i=k2;i>=k4;i--) if (pd[k1][i]>tim) {printf("%d %d\n",k1,i); return;} else tim-=pd[k1][i];
        }
    } else {
        if (k1<=k3){
            for (int i=k1;i<=k3;i++) if (pd[i][k2]>tim) {printf("%d %d\n",i,k2); return;} else tim-=pd[i][k2];
        } else {
            for (int i=k1;i>=k3;i--) if (pd[i][k2]>tim) {printf("%d %d\n",i,k2); return;} else tim-=pd[i][k2];
        }
    }
}
int getdis(int s,int t){
    if (s==t) return 0;
    int k1=(s-1)/m+1,k2=(s-1)%m+1;
    int k3=(t-1)/m+1,k4=(t-1)%m+1;
    if (k1==k3){
        int ans=1;
        for (int i=min(k2,k4)+1;i<=max(k2,k4)-1;i++) ans+=pd[k1][i]; return ans;
    } else {
        int ans=1;
        for (int i=min(k1,k3)+1;i<=max(k1,k3)-1;i++) ans+=pd[i][k2]; return ans;
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&tim); int cnt=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            char ch=getin(); f[i][j]=++cnt;
            if (ch!='#'){
                if (ch>='0'&&ch<='9') pd[i][j]=ch-'0'; else {where[ch-'a']=cnt; pd[i][j]=1;}
            }
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            for (int k=0;k<4;k++){
                int k1=i+gox[k],k2=j+goy[k];
                if (pd[k1][k2]&&pd[i][j])
                    add(f[k1][k2],f[i][j],pd[k1][k2]);
            }
    memset(w,0x3f,sizeof w);
    for (int i=0;i<26;i++) if (where[i]){
        for (int j=0;j<26;j++) if (where[j]) w[i][j]=getdis(where[i],where[j]);
    }
    s=get(); scanf("%s",ch+1); t=get(); len=strlen(ch+1);
    spfa(s);// cout<<d[where[ch[1]-'a']]<<endl;
//  if (tim==898) cout<<(s-1)/m+1<<" "<<(s-1)%m+1<<" "<<(t-1)/m+1<<" "<<(t-1)%m+1<<" "<<ch+1<<endl;
    if (tim<=d[where[ch[1]-'a']]){
        print(s,where[ch[1]-'a'],tim); return 0;
    } else tim-=d[where[ch[1]-'a']];
    for (int i=1;i<len;i++){
//      cout<<i<<" "<<k<<endl;
        if (tim<=w[ch[i]-'a'][ch[i+1]-'a']){
            print(where[ch[i]-'a'],where[ch[i+1]-'a'],tim); return 0;
        } else tim-=w[ch[i]-'a'][ch[i+1]-'a'];
    }
//  cout<<k<<endl;
    spfa(where[ch[len]-'a']);
    if (tim<=d[t]){
        print(where[ch[len]-'a'],t,tim); return 0;
    } else printf("%d %d\n",(t-1)/m+1,(t-1)%m+1);
    return 0;
}
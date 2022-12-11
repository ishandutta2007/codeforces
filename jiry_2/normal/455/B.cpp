#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
struct tree{
    int go[26],w,f,g;
}t[100010];
int n,k,len,pd[30];
char ch[100010];
void add(){
    int n=strlen(ch+1),now=1;
    for (int i=1;i<=n;i++){
        if (t[now].go[ch[i]-'a']==0){len++; t[now].go[ch[i]-'a']=len;} now=t[now].go[ch[i]-'a'];
    }
}
void dfs1(int k){
    for (int i=0;i<26;i++)
        if (t[k].go[i]) dfs1(t[k].go[i]);
    int flag=0;
    for (int i=0;i<26;i++)
        if (t[k].go[i]&&t[t[k].go[i]].w==0) flag=1;
    t[k].w=flag;
}
void dfs2(int k){
    for (int i=0;i<26;i++)
        if (t[k].go[i]) dfs2(t[k].go[i]);
    int flag=1,pd=0;
    for (int i=0;i<26;i++){
        if (t[k].go[i]) pd=1;
        if (t[k].go[i]&&t[t[k].go[i]].f)flag=0;
    }
    t[k].f=flag; if (pd==0) t[k].f=0;
}
int main(){
    scanf("%d%d",&n,&k);
    memset(t,0x00,sizeof t); len=1;
    for (int i=1;i<=n;i++){
        scanf("%s",ch+1); add();
    }
    dfs1(1); dfs2(1); int pd=0;
    for (int i=0;i<26;i++) if (t[1].go[i]&&t[t[1].go[i]].f){pd=1; break;}
    if (t[1].f==0&&t[1].w==1){cout<<"First"<<endl; return 0;}
    if (t[1].f==1){
        if (t[1].w==0) cout<<"Second"<<endl; else if (k%2==0) cout<<"Second"<<endl; else cout<<"First"<<endl; return 0;
    }
    cout<<"Second"<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
int a[25],b[25],c[25];
int p[15];
struct three{int a,b,c;bool operator<(const three&ot)const{if(b!=ot.b)return b<ot.b;if(c!=ot.c)return c<ot.c;return a<ot.a;}};
map<pii,pii>m;
vector<three>f,s;
vector<int>fi,si;
int main(){
    int n;
    scanf("%d",&n);
    p[0]=1;
    for(int i=1;i<15;i++)p[i]=p[i-1]*3;
    int ln=n/2,rn=n-ln;
    for(int i=0;i<n;i++)scanf("%d%d%d",a+i,b+i,c+i);
    for(int i=0;i<p[ln];i++){
        int aa=0,bb=0,cc=0;
        for(int j=0;j<ln;j++){
            aa+=a[j],bb+=b[j],cc+=c[j];
            if(i/p[j]%3==0){
                aa-=a[j];
            }
            else if(i/p[j]%3==1){
                bb-=b[j];
            }
            else{
                cc-=c[j];
            }
        }
        auto it=m.find({bb-aa,cc-aa});
        if(it==m.end())m[{bb-aa,cc-aa}]={aa,i};
        else it->second=max(it->second,{aa,i});
    }
    int ans=0xc0c0c0c0,ansa,ansb;
    for(int i=0;i<p[rn];i++){
        int aa=0,bb=0,cc=0;
        for(int j=0;j<rn;j++){
            aa+=a[ln+j],bb+=b[ln+j],cc+=c[ln+j];
            if(i/p[j]%3==0){
                aa-=a[ln+j];
            }
            else if(i/p[j]%3==1){
                bb-=b[ln+j];
            }
            else{
                cc-=c[ln+j];
            }
        }
        auto it=m.find({aa-bb,aa-cc});
        if(it==m.end())continue;
        if(aa+it->second.first>ans){
            ans=aa+it->second.first;
            ansa=it->second.second;
            ansb=i;
        }
    }
    if(ans==0xc0c0c0c0){
        printf("Impossible");
        return 0;
    }
    for(int i=0;i<ln;i++){
        if(ansa/p[i]%3==0)printf("MW\n");
        else if(ansa/p[i]%3==1)printf("LW\n");
        else printf("LM\n");
    }
    for(int i=0;i<rn;i++){
        if(ansb/p[i]%3==0)printf("MW\n");
        else if(ansb/p[i]%3==1)printf("LW\n");
        else printf("LM\n");
    }
}
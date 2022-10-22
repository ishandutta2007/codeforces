#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=3e5+10;
int p[mn],fcd[mn],s[mn],z[mn],cp[mn];
int f(int x){
    if(p[x]==x)return x;
    else{
        f(p[x]);
        cp[x]^=cp[p[x]];
        return p[x]=p[p[x]];
    }
}
int ans;
inline int eval(int x){
    if(fcd[x]==1)return s[x]-z[x];
    else if(fcd[x]==0)return z[x];
    else return min(s[x]-z[x],z[x]);
}
void mrg(int a,int b,bool on){
    f(a),f(b);
    on^=cp[a]^cp[b];
    a=f(a),b=f(b);
    if(a==b)return;
    ans-=eval(a)+eval(b);
    if(fcd[b]!=-1)swap(a,b);
    if(on)z[a]+=s[b]-z[b];
    else z[a]+=z[b];
    s[a]+=s[b];
    p[b]=a;
    cp[b]=on;
    ans+=eval(a);
}
vector<int>sw[mn];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    string str;
    cin>>str;
    for(int i=0;i<n;i++)str[i]-='0';
    for(int i=0;i<k;i++)p[i]=i,s[i]=z[i]=1,fcd[i]=-1;
    for(int i=0;i<k;i++){
        int m;
        scanf("%d",&m);
        while(m--){
            int x;
            scanf("%d",&x);
            x--;
            sw[x].push_back(i);
        }
    }
    for(int i=0;i<n;i++){
        if(sw[i].size()==1){
            ans-=eval(f(sw[i][0]));
            fcd[f(sw[i][0])]=str[i]^cp[sw[i][0]];
            ans+=eval(f(sw[i][0]));
        }
        else if(sw[i].size()==2){
            mrg(sw[i][0],sw[i][1],str[i]^1);
        }
        printf("%d\n",ans);
    }
}
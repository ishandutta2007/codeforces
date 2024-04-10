#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=1e5+10;
int seg[mn*2][60],t[60],a[mn];
void mer(int c[60],int a[60],int b[60]){
    for(int i=0;i<60;i++)t[i]=a[i]+b[(i+a[i])%60];
    memcpy(c,t,sizeof(t));
}
void ini(int a[60],int b){
    for(int i=0;i<60;i++)a[i]=1+(i%b==0);
}
void upd(int a,int b){
    for(ini(seg[a+=mn],b),a>>=1;a;a>>=1)mer(seg[a],seg[a*2],seg[a*2+1]);
}
int lef[60],rig[60];
int qu(int a,int b){
    memset(lef,0,sizeof(lef));
    memset(rig,0,sizeof(rig));
    for(a+=mn,b+=mn;a<=b;a>>=1,b>>=1){
        if(a&1)mer(lef,lef,seg[a++]);
        if(!(b&1))mer(rig,seg[b--],rig);
    }
    return lef[0]+rig[lef[0]%60];
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i),ini(seg[mn+i],a[i]);
    for(int i=mn-1;i;i--)mer(seg[i],seg[i*2],seg[i*2+1]);
    int q;
    scanf("%d",&q);
    while(q--){
        char s[2];
        int a,b;
        scanf("%s%d%d",s,&a,&b);
        if(s[0]=='C')upd(a,b);
        else printf("%d\n",qu(a,b-1));
    }
}
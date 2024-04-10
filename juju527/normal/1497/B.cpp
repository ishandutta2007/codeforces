#include<bits/stdc++.h>
using namespace std;
const int maxm=1e5+5;
int t[maxm];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
    int T;
    T=read();
    while(T--){
        int n,m;
        n=read();m=read();
        for(int i=0;i<m;i++)t[i]=0;
        for(int i=1;i<=n;i++)t[read()%m]++;
        int c=0;
        if(t[0])c++;
        for(int i=1;i<m;i++){
            if(m-i<i)break;
            if(m-i==i){
                if(t[i])c++;
                break;
            }
            if(t[i]||t[m-i]){
                if(t[i]==t[m-i])c++;
                else if(t[i]<t[m-i]){c++;c+=t[m-i]-t[i]-1;}
                else{c++;c+=t[i]-t[m-i]-1;}
            }
        }
        printf("%d\n",c);
    }
    return 0;
}
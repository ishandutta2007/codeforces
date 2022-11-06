//Problem C
#include<bits/stdc++.h>
using namespace std;
int rd(){
    int a=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
    return a;
}
const int N=107;
int n,a[N];
string str;
int main(){
    cin>>n>>str;
    for(int i=0;i<n;i++)a[i+1]=(str[i]^48)+a[i];
    for(int i=2;i<=n;i++)if(a[n]%i==0){
        int len=a[n]/i,f=1;//printf("Judging %d %d\n",i,len);
        for(int l=1,r=1;l<=n;l=r){
            while(r<=n&&a[r]-a[l-1]<=len)++r;//printf("%d %d\n",l,r);
            if(a[r-1]-a[l-1]!=len){f=0;break;}
        }
        if(f){printf("Yes");return 0;}
    }printf("No");
    return 0;
}
#include<cstdio>  
#define F(i,a,b) for(int i=a;i<=b;i++)  
const int N=2E5+7;
int a[N],fa[N];  
  
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}  
  
int main(){  
    int n,boss=-1,cnt=0;  
    scanf("%d",&n);  
    F(i,1,n)fa[i]=i;  
    F(i,1,n){  
        scanf("%d",a+i);  
        if(a[i]==i)boss=i,cnt++;//  
        else{  
            int fx=find(i),fy=find(a[i]);  
            if(fx==fy){//  
                cnt++,a[i]=i;  
            }else fa[fx]=fy;//  
        }  
    }  
    if(boss==-1){  
        F(i,1,n)if(fa[i]==i){boss=i;break;}  
        cnt++;  
    }  
    printf("%d\n",cnt-1);//  
    F(i,1,n){  
        if(a[i]==i)a[i]=boss;  
        printf("%d%c",a[i]," \n"[i==n]);  
    }  
    return 0;  
}
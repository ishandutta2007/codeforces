#include<cstdio>
#include<cctype>

#define maxn 222

template<class T>

inline T read(){
    T r=0,f=0;
    char c;
    while(!isdigit(c=getchar()))f|=(c=='-');
    while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
    return f?-r:r;
}

template<class T>

inline void swap(T &a,T &b){
    T c=a;
    a=b;
    b=c;
}

int n,k,a[maxn];

inline void work(){
    for(int i=1;i<=2*n;i++)a[i]=0;
    n=read<int>();
    k=read<int>();
    for(int i=1;i<=k;i++){
	int u=read<int>();
	int v=read<int>();
        a[u]=v,a[v]=u;
    }
    int tot=0;
    static int b[222];
    for(int i=1;i<=2*n;i++)
	if(!a[i])b[++tot]=i;
    int mid=n-k;
    for(int i=1;i<=mid;i++){
	a[b[i]]=b[i+mid];
	a[b[i+mid]]=b[i];
    }
    int sum=0;
    for(int i=1;i<=2*n;i++){
	if(a[i]<i)continue;
	for(int j=i+1;j<a[i];j++)
	    if(a[j]>j)sum+=a[i]<a[j];
    }
    printf("%d\n",sum);
}

int main(){
    int t=read<int>();
    while(t--)work();
    return 0;
}
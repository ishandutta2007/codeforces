#include<iostream>
#include<cmath> 
#include<cstdio>
#include<algorithm>
//#include <queue>
#define N 400005
#define MM 1000000009
#define INF 0x4fffffff
#define PI 3.14159265358979323846

#define rep(i,j,k) for(i=j;i<=k;i++)
#define rrep(i,j,k) for(i=j;i>=k;i--)

using namespace std;

struct Node{
    int x,y,num;
};

int i,j,k,w,v,s,flag,n,tmp,b[N][5],c[N][5],vis[N],pos[N],L[N],R[N],sum[N];
long long ans;
struct Node a[N];
FILE *fp1=fopen("CF521_B_1.txt","r");
FILE *fp2=fopen("CF521_B_5.txt","w");

bool operator < (const Node&p, const Node& q){
    if (p.y==q.y)
        return p.x<q.x;
    else
        return p.y<q.y;
}

void Build(int u, int l, int r){
    L[u]=l;
    R[u]=r;
    sum[u]=0;
    if (l!=r){
        Build(u<<1, l, (l+r)>>1);
        Build((u<<1)|1, ((l+r)>>1)+1, r);
    }
}

void add(int u , int x){
    if (L[u]!=R[u]){
        if (x<=((L[u]+R[u])>>1))
            add(u<<1, x);
        else
            add((u<<1)|1,x);
        sum[u]=sum[u<<1]+sum[(u<<1)|1];
    }
    else{
        sum[u]=1;
    }
}

void sub(int u , int x){
    if (L[u]!=R[u]){
        if (x<=((L[u]+R[u])>>1))
            sub(u<<1, x);
        else
            sub((u<<1)|1,x);
        sum[u]=sum[u<<1]+sum[(u<<1)|1];
    }
    else{
        sum[u]=0;
    }
}

int Large(int u){
    sum[u]--;
    if (L[u]==R[u])
        return L[u];
    else{
        if (sum[(u<<1)|1])
            return Large((u<<1)|1);
        else
            return Large(u<<1);
    }
}

int Small(int u){
    sum[u]--;
    if (L[u]==R[u])
        return L[u];
    else{
        if (sum[u<<1])
            return Small(u<<1);
        else
            return Small((u<<1)|1);
    }
}

int main(){
    cin>>n;
//  fscanf(fp1,"%d",&n);
    Build(1,1,n);
    rep(i,1,n){
        scanf("%d%d",&a[i].x,&a[i].y);
//      fscanf(fp1,"%d%d",&a[i].x,&a[i].y);
        a[i].num=i;
    }
    sort(a+1,a+n+1);
    rep(i,1,n)
        b[i][0]=c[i][0]=vis[i]=0;
    i=n;
    j=n-1;
    while (a[j].y==a[i].y)
        j--;
    while (i>=1){
        while ((j>=1)&&((a[j].y>a[i].y-1)||((a[j].y==a[i].y-1)&&(a[j].x>=a[i].x-1)))){
            if (a[j].y==a[i].y-1){
                if ((a[i].x-a[j].x<=1)&&(a[j].x-a[i].x<=1)){
                    b[i][0]++;
                    b[i][b[i][0]]=j;
                    c[j][0]++;
                    c[j][c[j][0]]=i;
                } 
            }
            j--;
        }
        i--;
        j+=3;
        if (j>=i)
            j=i-1;
    }
    
//  rep(i,1,n){
//      fprintf(fp2,"%d %d\n",a[i].num,b[i][0]);
//      rep(j,1,b[i][0])
//          fprintf(fp2,"%d ",a[b[i][j]].num);
//      fprintf(fp2,"\n");
//  }
//  
//      fprintf(fp2,"\n");
//      fprintf(fp2,"\n");
//      
//  rep(i,1,n){
//      fprintf(fp2,"%d %d\n",a[i].num,c[i][0]);
//      rep(j,1,c[i][0])
//          fprintf(fp2,"%d ",a[c[i][j]].num);
//      fprintf(fp2,"\n");
//  }
//  
    rep(i,1,n){
        flag=1;
        rep(j,1,c[i][0])
            if (b[c[i][j]][0]<=1)
                flag=0;
        if (flag)
            add(1,a[i].num);
    }
    rep(i,1,n)
        pos[a[i].num]=i;
    ans=0;
    rep(i,1,n){
        ans=(ans*n)%MM;
        if (i%2==1)
            tmp=Large(1);
        else
            tmp=Small(1);
//  fprintf(fp2,"%3d",tmp);
        ans=(ans+tmp-1)%MM;
        w=pos[tmp];
        rep(j,1,c[w][0]){
            v=c[w][j];
            b[v][0]--;
            k=1;
            while (b[v][k]!=w)
                k++;
            while (k<=b[v][0]){
                b[v][k]=b[v][k+1];
                k++;
            }
            if (b[v][0]==1)
                sub(1,a[b[v][1]].num);
        }
        rep(j,1,b[w][0]){
            v=b[w][j];
            c[v][0]--;
            k=1;
            while (c[v][k]!=w)
                k++;
            while (k<=c[v][0]){
                c[v][k]=c[v][k+1];
                k++;
            }
            flag=1;
            rep(k,1,c[v][0])
                if (b[c[v][k]][0]<=1)
                    flag=0;
            if (flag)
                add(1,a[v].num);
        }
    }
    cout<<ans<<endl;
    return 0;
}
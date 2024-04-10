#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct atom{
    int a,b,c;
}x[1210000];
vector<int>A[310000];
queue<int>Q;
vector<int>ans;
int n,f[310000],pd[1210000];
int check(int k){
    if (x[k].b==x[k].c){
        return f[x[k].b]+2-(x[k].a==x[k].b)<=9;
    } else return (f[x[k].b]+1-(x[k].a==x[k].b)<=9)&&(f[x[k].c]+1-(x[k].a==x[k].c)<=9);
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n*4;i++){
        int k1,k2,k3; scanf("%d%d%d",&k1,&k2,&k3); x[i]=(atom){k1,k2,k3};
        A[k2].push_back(i);
        if (k2!=k3) A[k3].push_back(i);
        Q.push(i); pd[i]=1;
    }
    for (int i=1;i<=n;i++) f[i]=4;
    while (!Q.empty()){
        int k1=Q.front(); Q.pop();
        if (check(k1)==0) {pd[k1]=0; continue;}
        ans.push_back(k1);
        f[x[k1].a]--; f[x[k1].b]++; f[x[k1].c]++;
        for (int i=0;i<A[x[k1].a].size();i++)
            if (check(A[x[k1].a][i])&&pd[A[x[k1].a][i]]==0){
                pd[A[x[k1].a][i]]=1; Q.push(A[x[k1].a][i]);
            }
    }
    printf("YES\n"); 
    for (int i=0;i<ans.size();i++) printf("%d ",ans[i]);
    return 0;
}
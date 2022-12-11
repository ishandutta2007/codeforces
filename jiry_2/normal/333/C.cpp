#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;
map<int,int>pd;
vector<int>x[10000],a[5][5];
int m,k,check[10000],sign;
void add(int k){
    for (int i=1;i<=4;i++)
        for (int j=1;j<=4;j++) a[i][j].clear();
    int kkk=k;
    for (int i=4;i;i--){
        int k1=10;
        for (int j=i;j;j--) {a[j][i].push_back(k%k1); k1*=10;}
        k/=10;
    }
    sign++;
    for (int i=2;i<=4;i++)
        for (int j=1;j<=4-i+1;j++){
            int l=j,r=j+i-1;
            for (int k1=l;k1<r;k1++)
                for (int k2=0;k2<a[l][k1].size();k2++)
                    for (int k3=0;k3<a[k1+1][r].size();k3++){
                        a[l][r].push_back(a[l][k1][k2]+a[k1+1][r][k3]);
                        a[l][r].push_back(a[l][k1][k2]-a[k1+1][r][k3]);
                        a[l][r].push_back(a[l][k1][k2]*a[k1+1][r][k3]);
                    }
        }
    for (int i=0;i<a[1][4].size();i++) if (check[abs(a[1][4][i])]!=sign){check[abs(a[1][4][i])]=sign; x[abs(a[1][4][i])].push_back(kkk);}
}
void put(int k){
    int k1=1,k2=k/10; while (k2){k1++; k2/=10;} for (int i=1;i<=8-k1;i++) printf("0"); printf("%d\n",k);
}
int main(){
    scanf("%d%d",&k,&m); int lim=1e4;
    for (int i=0;i<lim;i++) add(i);
    for (int i=0;i<10000;i++){
        int k1=abs(k-i);
        for (int j=0;j<x[i].size();j++)
            for (int k2=0;k2<x[k1].size();k2++){
                int now=x[i][j]*10000+x[k1][k2];
                if (pd[now]==0){
                    m--; put(now); if (m==0) return 0; pd[now]=1;
                }
            }
    }
    return 0;
}
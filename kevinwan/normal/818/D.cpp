#include <bits/stdc++.h>
using namespace std;
int num[100000];
vector<int> oc[1000001];
void end(int x){printf("%d",x);exit(0);}
int main() {
    int n,a,x;
    scanf("%d%d",&n,&a);
    int i,j;
    for(i=0;i<n;i++){
        scanf("%d",&x);
        if(x==a)num[i]=1;
        if(i)num[i]+=num[i-1];
        oc[x].push_back(i);
    }
    for(i=1;i<=1000000;i++){
        if(i==a)continue;
        bool fail=0;
        for(j=0;j<oc[i].size();j++){
            if(oc[i][j]==0)continue;
            if(num[oc[i][j]]>j)fail=1;
        }
        if(num[n-1]>oc[i].size())fail=1;
        if(!fail)end(i);
    }
    printf("-1");
}
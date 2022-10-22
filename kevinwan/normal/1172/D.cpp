#include <bits/stdc++.h>
using namespace std;
const int mn=1500;
int r[mn],c[mn],rr[mn],rc[mn];
vector<int>aa,bb,cc,dd;
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",r+i),rr[r[i]]=i;
    for(i=1;i<=n;i++)scanf("%d",c+i),rc[c[i]]=i;
    for(i=1;i<=n;i++){
        if(rr[i]!=i||rc[i]!=i){
            aa.push_back(i);
            bb.push_back(rc[i]);
            cc.push_back(rr[i]);
            dd.push_back(i);
            rr[r[i]]=rr[i];
            rc[c[i]]=rc[i];
            swap(r[i],r[rr[i]]);
            swap(c[i],c[rc[i]]);
        }
    }
    printf("%d",aa.size());
    for(i=0;i<aa.size();i++)printf("\n%d %d %d %d",aa[i],bb[i],cc[i],dd[i]);
}
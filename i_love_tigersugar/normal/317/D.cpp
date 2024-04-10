#include<bits/stdc++.h>
using namespace std;
const int sp[]={0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12,14,13};
bool ex[32000];
vector<int> v;
int n,k;
void anal(void) {
    scanf("%d",&n);
    int i,t;
    long long p;
    v.push_back(1);
    for (i=2;i<=n;i=i+1) {
        if (i*i>n) {
            k+=n-i+1;
            break;
        }
        if (ex[i]) continue;
        t=0;
        p=1LL;
        while (p<=1LL*n) {
            t++;
            p=p*i;          
            if (p*p<=1LL*n && p<=1LL*n) ex[(int)p]=true;
            else if (p<=1LL*n) k--;
        }
        v.push_back(t-1);
    }   
    int res=0;
    for (i=0;i<v.size();i=i+1) res=res^sp[v[i]];
    res=res^(k%2);
    if (res>0) printf("Vasya");
    else printf("Petya");
}
int main(void) {
    anal();
    return 0;
}
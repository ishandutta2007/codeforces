#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int maxn=1e5+5;
int a[maxn];
map<int,int> mp;
int main(){
    int tt;
    scanf("%d",&tt);
    while (tt--){
        int n;
        scanf("%d",&n);
        int sum=0,ans=0;
        mp={{0,maxn}};
        for (int i=0;i<n;i++){
            int t;
            scanf("%d",&t);
            sum^=t;
            int tmp=max(mp[sum^t],mp[sum]+1);
            mp[sum]=tmp;
        }
        printf("%d\n",n-mp[sum]+maxn);
    }
    return 0;
}
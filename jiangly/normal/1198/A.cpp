#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
int n,I;
int a[N];
int main(){
    scanf("%d%d",&n,&I);
    I=1<<min(I*8/n,20);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    int ans=0;
    for(int l=1,r=1,cnt=0;r<=n;++r){
        int x=a[r];
        ++cnt;
        while(r<n&&a[r+1]==x){
            ++r;
        }
        x=a[l];
        if(cnt>I){
            while(a[l]==x){
                ++l;
            }
            --cnt;
        }
        ans=max(ans,r-l+1);
    }
    printf("%d\n",n-ans);
    return 0;
}
// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    scanf("%d",&q);
    for(;q--;){
        int n;
        scanf("%d",&n);
        vector<int>c(n);
        for(int i=0;i<n;++i){
            int a;
            scanf("%d",&a);
            ++c[a-1];
        }
        vector<int>f(n);
        for(int i=0;i<n;++i){
            if(c[i]>0){
                ++f[c[i]-1];
            }
        }
        int sum=0,s=0;
        for(int i=n;i>=1;--i){
            s+=f[i-1];
            if(s>0){
                sum+=i;
                --s; 
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
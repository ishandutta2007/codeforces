#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int T,n,s;
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&s);
        int t=(n&1)?(n/2+1):(n/2);
        // printf("%d\n",t);
        int l=0,r=s,mid;
        while(l<r){
            mid=(l+r+1)>>1;
            // printf("%d %lld\n",mid,t-1+1ll*(n-t+1)*mid);
            if(1ll*(n-t+1)*mid<=s) l=mid;
            else r=mid-1;
        }
        printf("%d\n",l);
    }
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}
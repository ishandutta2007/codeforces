#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        long long a, b;
        scanf("%lld%lld",&a,&b);
        vector<int>TP;
        int tp = b;
        for(int i=2;i*i<=tp;i++){
            if(tp%i==0){
                TP.push_back(i);
                while(tp%i==0)tp/=i;
            }
        }
        if(tp!=1)TP.push_back(tp);
        long long res=0;
        for(auto &t : TP){
            long long z = a;
            while(z%b==0){
                z/=t;
            }
            res=max(res,z);
        }
        printf("%lld\n",res);
    }
}
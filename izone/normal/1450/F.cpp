#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, w[101000], C[101000], CC[101000];
struct point{
    int b, e;
};
void Solve(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)C[i]=CC[i]=0;
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        CC[w[i]]++;
    }
    for(i=1;i<=n;i++){
        if(CC[i]*2 > n+1){
            puts("-1");
            return;
        }
    }
    vector<point>V;
    int b = 1;
    for(i=1;i<n;i++){
        if(w[i]==w[i+1]){
            V.push_back({b,i});
            b=i+1;
        }
    }
    V.push_back({b,n});
    int tot=0;
    for(auto &t : V){
        tot+=2;
        C[w[t.b]]++,C[w[t.e]]++;
    }
    int res = V.size();
    res--;
    for(i=1;i<=n;i++){
//        printf("%d %d\n",C[i],tot);
        while(C[i]*2 > tot+2){
            tot+=2;
            res++;
        }
    }
    printf("%d\n",res);
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}
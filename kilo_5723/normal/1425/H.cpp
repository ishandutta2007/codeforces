#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int tt;
    scanf("%d",&tt);
    while (tt--){
        int A,B,C,D;
        scanf("%d%d%d%d",&A,&B,&C,&D);
        int f=(A+B)%2;
        int f1=(A+D)>0;
        int f2=(B+C)>0;
    //    cout<<f<<" "<<f1<<" "<<f2<<"\n";
        vector<int> ans(4);
        if(f){ans[0]=f1,ans[1]=f2;}
        else {ans[2]=f2,ans[3]=f1;}
        for(auto x:ans){
            printf(x?"Ya ":"Tidak ");
        }
        printf("\n");

    }
    return 0;
}
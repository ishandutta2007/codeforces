//Problem B
#include<bits/stdc++.h>
using namespace std;
int t,a,s;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&a),s=1;
        while(a)a^=a&-a,s<<=1;
        printf("%d\n",s);
    }
    return 0;
}
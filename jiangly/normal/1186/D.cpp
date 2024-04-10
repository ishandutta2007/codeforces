// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<int>a(n);
    long long sum=0;
    stack<int>id;
    for(int i=0;i<n;++i){
        double x;
        scanf("%lf",&x);
        a[i]=floor(x);
        sum+=a[i];
        if(x!=a[i]){
            id.push(i);
        }
    }
    for(;sum<0;){
        ++a[id.top()];
        ++sum;
        id.pop();
    }
    for(int i=0;i<n;++i){
        printf("%d\n",a[i]);
    }
    return 0;
}
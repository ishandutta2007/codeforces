#include<bits/stdc++.h>
using namespace std;
const int a[]={4,8,15,16,23,42};
int n;
set<int>s[6];
void kill(){
    printf("%d\n",n);
    exit(0);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        int x;
        scanf("%d",&x);
        x=lower_bound(a,a+6,x)-a;
        s[x].insert(i);
    }
    for(;;){
        if(s[0].size()==0)
            kill();
        int x=*s[0].begin();
        s[0].erase(s[0].begin());
        for(int i=1;i<6;++i){
            auto j=s[i].upper_bound(x);
            if(j==s[i].end())
                kill();
            x=*j;
            s[i].erase(j);
        }
        n-=6;
    }
    return 0;
}
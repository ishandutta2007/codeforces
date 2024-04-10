// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    if(n<=3){
        puts("1");
        return 0;
    }
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i].first);
        a[i].second=i+1;
    }
    sort(a.begin(),a.end());
    bool ok=true;
    int x=a[2].first-a[3].first;
    for(int i=2;i<n-1;++i){
        if(a[i].first-a[i+1].first!=x){
            ok=false;
        }
    }
    if(ok){
        if(a[0].first-a[2].first==x){
            printf("%d\n",a[1].second);
            return 0;
        }
        if(a[1].first-a[2].first==x){
            printf("%d\n",a[0].second);
            return 0;
        }
    }
    x=a[0].first-a[1].first;
    int y=a[0].first,pos=-1;
    for(int i=1;i<n;++i){
        if(y-a[i].first!=x){
            if(pos!=-1){
                puts("-1");
                return 0;
            }
            pos=i;
        }else{
            y=a[i].first;
        }
    }
    if(pos==-1){
        puts("1");
    }else{
        printf("%d\n",a[pos].second);
    }
    return 0;
}
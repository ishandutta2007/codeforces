// remote judge
#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    scanf("%d",&k);
    int n=1<<k;
    vector<int>b(n);
    for(int i=0;i<n;++i){
        scanf("%d",&b[i]);
    }
    int sum=0;
    for(int i=0;i<n;++i){
        sum^=b[i];
    }
    if(sum!=0){
        puts("Fou");
        return 0;
    }
    puts("Shi");
    vector<int>p(n),q(n),id(n),a(n);
    for(int i=0;i<n;++i){
        p[i]=i;
        q[i]=i;
        id[i]=i;
    }
    function<void(int,int)> fix=[&](int i,int j){
        if(q[i]==(p[i]^a[i])){
            return;
        }else if(q[i]==(p[i]^a[j])){
            swap(q[i],q[j]);
            swap(p[i],p[j]);
            swap(id[p[i]],id[p[j]]);
        }else if(q[i]==(p[j]^a[i])){
            swap(p[i],p[j]);
            swap(id[p[i]],id[p[j]]);
        }else if(q[i]==(p[j]^a[j])){
            swap(q[i],q[j]);
        }else{
            int t=id[a[i]^q[i]];
            swap(p[t],p[i]);
            swap(id[p[t]],id[p[i]]);
            swap(q[t],q[i]);
            swap(q[t],q[j]);
            swap(q[i],q[j]);
            fix(t,j);
        }
    };
    for(int i=0;i<n-1;++i){
        a[i+1]^=(a[i]^b[i]);
        a[i]=b[i];
        fix(i,i+1);
    }
    for(int i=0;i<n;++i){
        printf("%d ",p[i]);
    }
    puts("");
    for(int i=0;i<n;++i){
        printf("%d ",q[i]);
    }
    puts("");
    return 0;
}
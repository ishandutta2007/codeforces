#include<bits/stdc++.h>
#define vec vector<int>
using namespace std;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
vec res;
int query(int x,int y){
    printf("0 %d %d\n",x,y);fflush(stdout);
    return read();
}
void Solve(int l,int r){
    if(l+1>=r)return ;
    int mid1=floor(1.0*(l+r)/2),mid2=ceil(1.0*(l+r)/2),mid;
    int d1=query(mid1,mid1),d2=query(mid2,mid2),d;
    if(mid2==r)mid2=mid1,d2=d1;
    if(!d1){res.push_back(mid1);Solve(l,mid1);Solve(mid1,r);return ;}
    if(!d2){res.push_back(mid2);Solve(l,mid2);Solve(mid2,r);return ;}
    bool flag1=(mid1+d1==r||mid1-d1==l),flag2=(mid2+d2==r||mid2-d2==l);
    if(flag1&&flag2)return ;
    if(flag1||(!flag1&&!flag2))mid=mid2,d=d2;
    if(flag2)mid=mid1,d=d1;
    int D1=query(mid+d,mid+d),D2=query(mid-d,mid-d);
    if(!D1){res.push_back(mid+d);Solve(l,mid+d);Solve(mid+d,r);return ;}
    if(!D2){res.push_back(mid-d);Solve(l,mid-d);Solve(mid-d,r);return ;}
    return ;
}
int main(){
    Solve(-1e8-1,1e8+1);
    vec X,Y;
//    cout<<res.size()<<endl;
    sort(res.begin(),res.end());
    int p=1e9;
    for(int i=1;i<res.size();i++){
        if(res[i]==res[i-1]+1)continue;
        p=res[i]-1;
    }
    if(p==1e9){
        if(res[0]==-1e8)p=1e8;
        else p=-1e8;
    }
    for(int i=0;i<res.size();i++){
        int x=res[i];
        int d1=query(x,p),d2=query(p,x);
        if(!d1&&!d2)X.push_back(x),Y.push_back(x);
        else if(!d1)X.push_back(x);
        else if(!d2)Y.push_back(x);
    }
    printf("1 %d %d\n",X.size(),Y.size());fflush(stdout);
    for(int i=0;i<X.size();i++)printf("%d ",X[i]);puts("");fflush(stdout);
    for(int i=0;i<Y.size();i++)printf("%d ",Y[i]);puts("");fflush(stdout);
//    cout<<X.size()<<" "<<Y.size()<<endl;
    return 0;
}
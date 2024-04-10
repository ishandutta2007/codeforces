#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<vector<int>> a(min(n,m),vector<int>(max(n,m)));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(n<m){
                scanf("%d",&a[i][j]);
            }else{
                scanf("%d",&a[j][i]);
            }
        }
    }
    if(n>m){
        swap(n,m);
    }
    vector<LL> sr(n);
    vector<LL> sc(m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            sr[i]+=a[i][j];
            sc[j]+=a[i][j];
        }
    }
    LL ans=0;
    LL mx[4]={};
    for(int i=0;i<n;++i){
        LL x=sr[i];
        for(int j=0;j<4;++j){
            if(x>mx[j]){
                swap(x,mx[j]);
            }
        }
    }
    ans=max(ans,mx[0]+mx[1]+mx[2]+mx[3]);
    mx[0]=0;
    mx[1]=0;
    mx[2]=0;
    mx[3]=0;
    for(int i=0;i<m;++i){
        LL x=sc[i];
        for(int j=0;j<4;++j){
            if(x>mx[j]){
                swap(x,mx[j]);
            }
        }
    }
    ans=max(ans,mx[0]+mx[1]+mx[2]+mx[3]);
    for(int i=0;i<n;++i){
        mx[0]=0;
        mx[1]=0;
        mx[2]=0;
        for(int j=0;j<m;++j){
            LL x=sc[j]-a[i][j];
            for(int k=0;k<3;++k){
                if(x>mx[k]){
                    swap(x,mx[k]);
                }
            }
        }
        ans=max(ans,sr[i]+mx[0]+mx[1]+mx[2]);
    }
    for(int i=0;i<m;++i){
        mx[0]=0;
        mx[1]=0;
        mx[2]=0;
        for(int j=0;j<n;++j){
            LL x=sr[j]-a[j][i];
            for(int k=0;k<3;++k){
                if(x>mx[k]){
                    swap(x,mx[k]);
                }
            }
        }
        ans=max(ans,sc[i]+mx[0]+mx[1]+mx[2]);
    }
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            mx[0]=0;
            mx[1]=0;
            for(int k=0;k<m;++k){
                LL x=sc[k]-a[i][k]-a[j][k];
                for(int l=0;l<2;++l){
                    if(x>mx[l]){
                        swap(x,mx[l]);
                    }
                }
            }
            ans=max(ans,sr[i]+sr[j]+mx[0]+mx[1]);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
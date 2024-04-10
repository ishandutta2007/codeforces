#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int n,m,X[200010],Y[200010],opt[200010][2],rem[200010],nxt[200010];
int ans1[200010],ans2[510][200010];
const int B=500;
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d %d",&X[i],&Y[i]);
    for(int i=1;i<=m;i++) scanf("%d %d",&opt[i][0],&opt[i][1]);
    for(int i=1;i<=n;i++) rem[i]=m+1;
    for(int i=m;i>=1;i--){
        if(opt[i][0]==2) rem[opt[i][1]]=i;
        else nxt[i]=rem[opt[i][1]]-1;
    }
    for(int i=1;i<=m;i++){
        if(opt[i][0]==2) continue;
        int x=opt[i][1];//printf("%d %d\n",i,nxt[i]);
        if(X[x]+Y[x]>B){
            for(int j=i;j+X[x]<=nxt[i];j+=X[x]+Y[x]){
                ans1[j+X[x]]++;
                ans1[min(nxt[i]+1,j+X[x]+Y[x])]--;
            }
        }else{
            int t=(nxt[i]-i)/(X[x]+Y[x]);
            for(int j=i+X[x],r;j<i+X[x]+Y[x]&&j<=nxt[i];j++){
                ans2[X[x]+Y[x]][j]++;//printf("%d\n",j);
                r=j+t*(X[x]+Y[x]);
                if(r>nxt[i]) r-=X[x]+Y[x];
                ans2[X[x]+Y[x]][min(m+1,r+X[x]+Y[x])]--;//printf("%d\n",min(m+1,r+X[x]+Y[x]));
            } 
        }
    }
    for(int i=1;i<=m;i++) ans1[i]+=ans1[i-1];
    for(int i=1;i<=B;i++){
        for(int j=i;j<=m;j++) ans2[i][j]+=ans2[i][j-i];
    }
    for(int i=1;i<=m;i++){
        int ans=ans1[i];
        for(int j=1;j<=B;j++) ans+=ans2[j][i];
        printf("%d\n",ans);
    }
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}
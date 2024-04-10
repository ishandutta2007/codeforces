// Hydro submission #617c9f3263b6465eb4e57c32@1635557171557
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005;
int ff,_,n,m,a[N],b[N],sa,sb;
bitset<1000005> f[N];
vector<int> vecx[3],vecy[3];
void work(){
    f[0][0]=1;
    for(int i=1;i<=n;i++)f[i]=f[i-1]|(f[i-1]<<a[i]);
    if(f[n][sa/2]){
        int now=sa/2;
        for(int i=n;i;i--)if(now-a[i]>=0&&f[i-1][now-a[i]])now-=a[i],vecx[1].push_back(i);
        else vecx[2].push_back(i);
    }
    else ff=1;
    for(int i=1;i<=m;i++)f[i]=f[i-1]|(f[i-1]<<b[i]);
    if(f[n][sb/2]){
        int now=sb/2;
        for(int i=m;i;i--)if(now-b[i]>=0&&f[i-1][now-b[i]])now-=b[i],vecy[1].push_back(i);
            else vecy[2].push_back(i);
    }
    else ff=1;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin>>_;
    while(_--){
        ff=0;
        sa=0,sb=0;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i],sa+=a[i];
        cin>>m;
        for(int i=1;i<=m;i++)cin>>b[i],sb+=b[i];
        if(sa&1||sb&1||n!=m){
            puts("No");
            continue;
        }
        vecx[1].clear(),vecx[2].clear();
        vecy[1].clear(),vecy[2].clear();
        work();
        if(ff){
            puts("No");
            continue;
        }
        puts("Yes");
        if(vecx[1].size()>vecx[2].size())swap(vecx[1],vecx[2]);
        if(vecy[1].size()<vecy[2].size())swap(vecy[1],vecy[2]);
        for(int i=1;i<=2;i++)sort(vecx[i].begin(),vecx[i].end(),[](int x,int y){return a[x]>a[y];});
        for(int i=1;i<=2;i++)sort(vecy[i].begin(),vecy[i].end(),[](int x,int y){return b[x]<b[y];});
        //for(int i:vecy[1])cout<<i<<endl;
        int x=0,y=0;
        int i=0,j=0;
        for(;i<vecx[1].size();){
            printf("%d %d\n",x,y);
            x+=a[vecx[1][i]];
            i++;
            printf("%d %d\n",x,y);
            y+=b[vecy[1][j]];
            j++;
        }
        i=0;
        for(;j<vecy[1].size();){
            printf("%d %d\n",x,y);
            x-=a[vecx[2][i]];
            i++;
            printf("%d %d\n",x,y);
            y+=b[vecy[1][j]];
            j++;
        }
        j=0;
        for(;i<vecx[2].size();){
            printf("%d %d\n",x,y);
            x-=a[vecx[2][i]];
            i++;
            printf("%d %d\n",x,y);
            y-=b[vecy[2][j]];
            j++;
        }
    }
    return 0;
}
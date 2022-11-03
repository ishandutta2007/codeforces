#include <bits/stdc++.h>

using namespace std;

const int N=4e5+10;

int n,m,a[N];

int ra[N][2];



struct getne{
        int tr[N],des[N];
        void build(int n){
                memset(des,0,sizeof(des));
                for(int i=1;i<=n;i++) tr[i]=i+1;

        }
        int getnext(int pos){
                if (!des[pos]) return pos;
                tr[pos]=getnext(tr[pos]);
                return tr[pos];
        }
}mget;
void solve(){
        mget.build(n);
        for(int i=m;i>=1;i--){
                while (1){
                        int cur=mget.getnext(ra[i][0]);
                        if (cur>ra[i][1]) break;
                        mget.des[cur]=i;
                }
        }
        for(int i=1;i<=n;i++) if (a[i]!=0){
                if (a[i]!=mget.des[i]){
                        cout<<"NO";
                        return;
                }
        }
        int last=count(mget.des+1,mget.des+n+1,m);
        for(int i=1;i<=n;i++) if (mget.des[i]==0){
                if (last==0){
                        last++;
                        mget.des[i]=m;
                }else mget.des[i]=mget.des[i-1];
        }
        for(int i=n;i>=1;i--) if (mget.des[i]==0){
                if (last==0){
                        last++;
                        mget.des[i]=m;
                }else mget.des[i]=mget.des[i+1];
        }
        if (last==0){
                if (count(a+1,a+n+1,0)==0){
                        cout<<"NO";
                        return;
                }
                mget.des[find(a+1,a+n+1,0)-a]=m;
        }
        cout<<"YES\n";
        for(int i=1;i<=n;i++) cout<<mget.des[i]<<" ";
}
int main(){
        cin>>n>>m;
        for(int i=1;i<=m;i++){
                ra[i][0]=n+1;
                ra[i][1]=0;
        }
        for(int i=1;i<=n;i++){
                cin>>a[i];
                ra[a[i]][0]=min(ra[a[i]][0],i);
                ra[a[i]][1]=max(ra[a[i]][1],i);
        }
        solve();
}
#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int M=2009;
const int mod=998244353;
int n;
int a[M],f[M];
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
bool work(){
    for(int i=0;i<30;++i)f[i]=i;
    int s=0;
    vector<int>v;
    for(int i=1;i<=n;++i)s|=a[i];
    for(int i=1;i<=n;++i){
        if(a[i]==0)continue;
        v.clear();
        for(int j=0;j<30;++j){
            if(a[i]>>j&1)v.eb(j);
        }
        for(auto o:v)f[find(o)]=find(v[0]);
    }
    v.clear();
    for(int j=0;j<30;++j){
        if(s>>j&1)v.eb(j);
    }
    for(auto o:v)if(find(o)!=find(v[0]))return 0;
    return 1;
}

void solve(){
    cin>>n;
    int s=0,t=0;
    for(int i=1;i<=n;++i)cin>>a[i],s+=a[i]==0,t+=a[i]&1;
    if(s==n){
        cout<<n<<endl;
        for(int i=1;i<=n;++i)cout<<1<<" ";
        puts("");
        return;
    }
    else{
        if(work()){
            cout<<s+(!t&&s)<<endl;
            for(int i=1;i<=n;++i){
                if(a[i]%2==0&&a[i]>0&&t==0&&s)t=1,a[i]++;
                cout<<max(a[i],1)<<" ";
            }
            puts("");
            return;
        }
        for(int i=1;i<=n;++i){
            if(a[i]>0&&a[i]%2==0){
                a[i]--;
                if(work()){
                    cout<<s+1<<endl;
                    for(int i=1;i<=n;++i)cout<<max(a[i],1)<<" ";
                    puts("");
                    return;
                }
                a[i]+=2;
                if(work()){
                    cout<<s+1<<endl;
                    for(int i=1;i<=n;++i)cout<<max(a[i],1)<<" ";
                    puts("");
                    return;
                }
                a[i]--;
            }
        }
    }
    cout<<s+2<<endl;
    int ma=0,b=0;
    for(int i=1;i<=n;++i)ma=max(ma,a[i]&-a[i]);
    for(int i=1;i<=n;++i){
        if((a[i]&-a[i])==ma){
            if(b==0)a[i]--,b=1;
            else if(b==1)a[i]++,b=2;
        }
    }
    for(int i=1;i<=n;++i)cout<<max(a[i],1)<<" ";
    puts("");
    return;
}
int main(){
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}
/*
1
2
0 0
*/
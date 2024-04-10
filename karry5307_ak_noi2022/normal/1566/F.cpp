#include<bits/stdc++.h>
#define int long long
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int T,n,m,a[200010];
long long f[200010];
map<int,int> mp;
pair<int,int> pr[200010];
void solve(){
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);mp.clear();
    for(int i=1,x,y;i<=m;i++){
        scanf("%lld %lld",&x,&y);
        if(mp.find(x)!=mp.end()) mp[x]=min(mp[x],y);
        else mp[x]=y;
    }m=0;
    for(auto p:mp){
        int l=p.first,r=p.second;
        int x=lower_bound(a+1,a+n+1,l)-a;
        if(x==n+1) pr[++m]=make_pair(l,r);
        else if(a[x]!=l&&(x>=n||a[x+1]>r)) pr[++m]=make_pair(l,r);
    }f[0]=0;pr[0]=make_pair((int)-1e10,(int)-1e10);a[n+1]=1e10;
    // for(int i=1;i<=m;i++) printf("LR %lld %lld\n",pr[i].first,pr[i].second);
    for(int i=1;i<=m;i++) f[i]=1e16;
    for(int i=1,j=0,t;i<=n;i++){
        vector<pair<int,long long> > v1,v2;
        //v1 f[i]->f[j] j<=v1.first
        for(t=j;t<=m&&pr[t].first<=a[i];t++);
        int minn=(int)1e10,cp=t-1;
        v2.push_back(make_pair((int)-1e10,(long long)1e18));
        for(t--;t>=j;t--){
            int pos=(t==cp)?a[i]:pr[t+1].second;
            minn=min(minn,pos);
            int dis=a[i]-minn;
            // printf("%d\n",pos);
            v1.push_back(make_pair(a[i]+dis,f[t]+dis));
            v2.push_back(make_pair(a[i]+dis,f[t]+dis*2));
        }
        v1.push_back(make_pair((int)1e10,(long long)1e18));
        for(int l=(int)v1.size()-2;l>=0;l--) v1[l].second=min(v1[l].second,v1[l+1].second);
        for(int l=1;l<v2.size();l++) v2[l].second=min(v2[l].second,v2[l-1].second);
        // puts("v1");
        // for(auto p:v1) printf("%lld %lld\n",p.first,p.second);
        // puts("v2");
        // for(auto p:v2) printf("%lld %lld\n",p.first,p.second);
        f[cp]=min(f[cp],v1[0].second);
        for(t=cp+1;t<=m&&pr[t].first<=a[i+1];t++){
            long long min1=lower_bound(v1.begin(),v1.end(),make_pair(pr[t].first,(long long)-5e18))-v1.begin();
            long long min2=upper_bound(v2.begin(),v2.end(),make_pair(pr[t].first,(long long)5e18))-v2.begin()-1;
            int dis=pr[t].first-a[i];
            f[t]=min(v1[min1].second+2*dis,v2[min2].second+dis);
        }
        // printf("%lld %lld %lld\n",i,j,cp);
        j=cp;
    }
    printf("%lld\n",f[m]);
}
signed main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%lld",&T);
    while(T--) solve();
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}
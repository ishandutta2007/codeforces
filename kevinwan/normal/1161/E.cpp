#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=1e5+10;
bool sm[mn],m1[mn],m2[mn];
char st[mn];
int gr[mn],el[mn],col[mn];
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n,i;
        scanf("%d",&n);
        if(n/2){
            printf("Q %d ",n/2);
            for(i=1;i<n;i+=2)printf("%d %d ",i,i+1);
            printf("\n");
            fflush(stdout);
            scanf("%s",st);
        }
        for(i=0;i<n/2;i++)sm[i*2+1]=st[i]-'0';
        if((n-1)/2){
            printf("Q %d ",(n-1)/2);
            for(i=2;i<n;i+=2)printf("%d %d ",i,i+1);
            printf("\n");
            fflush(stdout);
            scanf("%s",st);
        }
        for(i=0;i<(n-1)/2;i++)sm[i*2+2]=st[i]-'0';
        int cur=1;
        gr[1]=1,el[1]=1;
        for(i=1;i<n;i++){
            if(!sm[i])gr[i+1]=++cur,el[cur]=i+1;
            else gr[i+1]=cur;
        }
        int m=cur;
        col[1]=1;
        col[2]=2;
        vector<pii>v;
        for(i=1;i+2<=m;i++){
            if((i-1)%4>=2)continue;
            v.push_back({i,i+2});
        }
        if(v.size()){
            printf("Q %d ",v.size());
            for(pii p:v)printf("%d %d ",el[p.first],el[p.second]);
            printf("\n");
            fflush(stdout);
            scanf("%s",st);
        }
        for(i=0;i<v.size();i++){
            if(v[i].first&1)m1[v[i].second]=st[i]-'0';
            else m2[v[i].second]=st[i]-'0';
        }
        v.clear();
        for(i=1;i+2<=m;i++){
            if((i-1)%4<2)continue;
            v.push_back({i,i+2});
        }
        if(v.size()){
            printf("Q %d ",v.size());
            for(pii p:v)printf("%d %d ",el[p.first],el[p.second]);
            printf("\n");
            fflush(stdout);
            scanf("%s",st);
        }
        for(i=0;i<v.size();i++){
            if(v[i].first&1)m1[v[i].second]=st[i]-'0';
            else m2[v[i].second]=st[i]-'0';
        }
        v.clear();
        for(i=1;i+3<=m;i+=2){
            v.push_back({i,i+3});
        }
        if(v.size()){
            printf("Q %d ",v.size());
            for(pii p:v)printf("%d %d ",el[p.first],el[p.second]);
            printf("\n");
            fflush(stdout);
            scanf("%s",st);
        }
        for(i=0;i<v.size();i++){
            if(v[i].first&1)m1[v[i].second]=st[i]-'0';
            else m2[v[i].second]=st[i]-'0';
        }
        v.clear();
        for(i=2;i+1<=m;i+=2){
            v.push_back({i,i+1});
        }
        if(v.size()){
            printf("Q %d ",v.size());
            for(pii p:v)printf("%d %d ",el[p.first],el[p.second]);
            printf("\n");
            fflush(stdout);
            scanf("%s",st);
        }
        for(i=0;i<v.size();i++){
            if(v[i].first&1)m1[v[i].second]=st[i]-'0';
            else m2[v[i].second]=st[i]-'0';
        }
        v.clear();
        for(i=3;i<=m;i++){
            int a=(i-1)/2*2-1,b=a+1;
            if(m1[i])col[i]=col[a];
            else if(m2[i])col[i]=col[b];
            else col[i]=6-col[a]-col[b];
        }
        vector<int> u[4];
        for(i=1;i<=n;i++)u[col[gr[i]]].push_back(i);
        printf("A %d %d %d\n",u[1].size(),u[2].size(),u[3].size());
        for(int x:u[1])printf("%d ",x);
        printf("\n");
        for(int x:u[2])printf("%d ",x);
        printf("\n");
        for(int x:u[3])printf("%d ",x);
        printf("\n");
        fflush(stdout);
    }
}
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
#define mo 1000000009
#include<set>
#include<vector>
#include<map>
int n;
map<pair<int,int>,int>nu;
pair<int,int>p[100005];
set<int> se;
int id[3]={0,1,-1};
int off[100005]={0};

int deg(int i){
    int su=0;
    for (int j=0;j<3;j++){
        int k=id[j];
        map<pair<int,int>,int>::iterator it=nu.find(make_pair(p[i].first+k,p[i].second-1));
        if(it==nu.end())continue;
        if(off[it->second])continue;
        su++;
    }
    return su;
}
int test(int i){
    for (int j=0;j<3;j++){  
        int k=id[j];
        map<pair<int,int>,int>::iterator it=nu.find(make_pair(p[i].first+k,p[i].second+1));
        if(it==nu.end())continue;
        if(off[it->second])continue;
        if(deg(it->second)==1)return 0;
    }
    return 1;
}
void rele(int i){
    off[i]=1;
    se.erase(i);
    for (int k=-2;k<=2;k++){
        if(k==0)continue;
        map<pair<int,int>,int>::iterator it=nu.find(make_pair(p[i].first+k,p[i].second));
        if(it==nu.end())continue;
        if(off[it->second])continue;
        if(!test(it->second))se.erase(it->second);
        else se.insert(it->second);
    }
    for (int k=-1;k<=1;k++){
        map<pair<int,int>,int>::iterator it=nu.find(make_pair(p[i].first+k,p[i].second-1));
        if(it==nu.end())continue;
        if(off[it->second])continue;
        if(!test(it->second))se.erase(it->second);
        else se.insert(it->second);
    }
}
int res=0;
int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d%d",&p[i].first,&p[i].second);
        nu[p[i]]=i;
    }
    for (int i=0;i<n;i++){
        if(test(i))se.insert(i);
    }
    for (int i=0;i<n;i++){
        int ge;
        if(i&1)ge=*se.begin();
        else ge=*se.rbegin();
        res=(1ll*res*n+ge)%mo;
        rele(ge);
    }
    printf("%d\n",res);
    return 0;
}
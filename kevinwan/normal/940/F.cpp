#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const ll mod=1e9+7;
const int mn=5e5+10;
const int siz=2000;
int eda[mn],edb[mn],edc[mn];
int a[mn],o[mn];
int num[mn],nnum[mn];
struct query{
    int t,l,r;
};
int pr[mn];
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    vector<int>nums;
    for(int i=1;i<=n;i++)scanf("%d",a+i),nums.push_back(a[i]);
    vector<query>v;
    for(int i=1;i<=q;i++){
        int t,a,b;
        scanf("%d%d%d",&t,&a,&b);
        if(t==1)v.push_back({i,a,b});
        else nums.push_back(b),eda[i]=a,edb[i]=b;
    }
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    map<int,int>comp;
    for(int i=0;i<nums.size();i++)comp[nums[i]]=i;
    for(int i=1;i<=n;i++)a[i]=comp[a[i]];
    for(int i=1;i<=q;i++)if(eda[i])edb[i]=comp[edb[i]];
    memcpy(o,a,sizeof(o));
    for(int i=1;i<=q;i++)if(eda[i]){
        edc[i]=o[eda[i]];
        o[eda[i]]=edb[i];
    }
    sort(v.begin(),v.end(),[](query a,query b){if(a.t/siz!=b.t/siz)return a.t/siz<b.t/siz;if(a.l/siz!=b.l/siz)return a.l/siz<b.l/siz;return a.r<b.r;});
    nnum[0]=1e9;
    int ct=0,cl=1,cr=0;
    for(query q:v){
        while(cr<q.r){
            --nnum[num[a[++cr]]];
            ++nnum[++num[a[cr]]];
        }
        while(cr>q.r){
            --nnum[num[a[cr]]--];
            ++nnum[num[a[cr--]]];
        }
        while(cl>q.l){
            --nnum[num[a[--cl]]];
            ++nnum[++num[a[cl]]];
        }
        while(cl<q.l){
            --nnum[num[a[cl]]--];
            ++nnum[num[a[cl++]]];
        }
        while(ct<q.t){
            ++ct;
            if(eda[ct]) {
                a[eda[ct]] = edb[ct];
                if (cl <= eda[ct] && eda[ct] <= cr) {
                    --nnum[num[edb[ct]]];
                    ++nnum[++num[edb[ct]]];
                    --nnum[num[edc[ct]]--];
                    ++nnum[num[edc[ct]]];
                }
            }
        }
        while(ct>q.t){
            if(eda[ct]) {
                a[eda[ct]] = edc[ct];
                if (cl <= eda[ct] && eda[ct] <= cr) {
                    --nnum[num[edc[ct]]];
                    ++nnum[++num[edc[ct]]];
                    --nnum[num[edb[ct]]--];
                    ++nnum[num[edb[ct]]];
                }
            }
            --ct;
        }
        int ans=1;
        for(;nnum[ans];ans++);
        pr[q.t]=ans;
    }
    for(int i=0;i<=q;i++)if(pr[i])printf("%d\n",pr[i]);
}
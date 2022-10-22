#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const ll mod=1e9+7;
const int mn=5e5+10;
struct hail{int a,b,c;bool operator<(const hail&ot)const{return a>ot.a;}};
hail h[mn];
int bit[mn];
void up(int a,int b){for(a++;a<mn;a+=a&-a)bit[a]=max(bit[a],b);}
int qu(int a,int b){for(a++;a;a-=a&-a)if(bit[a]>b)return 1;return 0;}
int main(){
    int n;
    scanf("%d",&n);
    vector<int>vals;
    for(int i=0;i<n;i++)scanf("%d",&h[i].a);
    for(int i=0;i<n;i++)scanf("%d",&h[i].b),h[i].b*=-1,vals.push_back(h[i].b);
    for(int i=0;i<n;i++)scanf("%d",&h[i].c);
    sort(vals.begin(),vals.end());
    vals.erase(unique(vals.begin(),vals.end()),vals.end());
    map<int,int>comp;
    for(int i=0;i<vals.size();i++)comp[vals[i]]=i;
    for(int i=0;i<n;i++)h[i].b=comp[h[i].b];
    vector<pii>ad;
    sort(h,h+n);
    int ans=0;
    for(int i=0;i<n;i++){
        if(i&&h[i].a!=h[i-1].a){
            for(pii&p:ad){
                up(p.first,p.second);
            }
            ad.clear();
        }
        ans+=qu(h[i].b-1,h[i].c);
        ad.push_back({h[i].b,h[i].c});
    }
    printf("%d",ans);
}
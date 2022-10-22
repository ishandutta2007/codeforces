#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=1e9+7;
const int mn=5e5+10;
ll a[mn];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,k,b,c;
    cin>>n>>k>>b>>c;
    b=min(b,c*5);
    for(int i=0;i<n;i++)cin>>a[i],a[i]+=1e9+100;
    sort(a,a+n);
    ll ans=0x3f3f3f3f3f3f3f3f;
    for(int m=0;m<5;m++){
        ll lv=m,pro=0;
        queue<ll>q[5];
        int num=0;
        for(int i=0;i<n;i++){
            ll v=a[i];
            while(v%5!=m)v++;
            pro+=(v-lv)/5*b*num;
            q[a[i]%5].push(a[i]);
            num++;
            pro+=(v-a[i])*c;
            if(num>k){
                int loc=-1;
                ll bv=-0x3f3f3f3f3f3f3f3f;
                for(int j=0;j<5;j++)if(q[j].size()){
                    ll pro=(v-q[j].front())/5*b+(v-q[j].front())%5*c;
                    if(pro>bv)bv=pro,loc=j;
                }
                num--;
                q[loc].pop();
                pro-=bv;
            }
            if(num==k)ans=min(ans,pro);
            lv=v;
        }
    }
    printf("%lld",ans);
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iomanip>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <stack>
using namespace std;
typedef long long ll;
const ll N=1000005;
const ll inf=0x3f3f3f3f3f3f3f3f;

int a[N];
bool cmp(const int &a,const int &b){
    return a>b;
}
int main(){
    ios::sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,cmp);
    vector<ll> v;
    ll ans=0,now=0;
    int p=1;
    while(p<=n&&now>=0){
        ans+=now;
        now+=a[p];
        p++;
    }
    v.push_back(now);
    for(;p<=n;p++) v.push_back(a[p]);
    sort(v.begin(),v.end(),cmp);
    priority_queue<ll> que;
    for(int i=0;i<=k;i++) que.push(0);
    for(auto x:v){
        ll top=que.top();
        que.pop();
        ans+=top;
        top+=x;
        que.push(top);
    }
    cout<<ans<<endl;
}
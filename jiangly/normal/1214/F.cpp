// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m,n;
    cin>>m>>n;
    vector<int> x(n*2);
    vector<int> s(n*2);
    for(int i=0;i<n*2;++i){
        cin>>x[i];
        s[i]=i;
    }
    LL sum=0;
    vector<int> ans(n*2);
    sort(s.begin(),s.end(),[&](int a,int b){
        return x[a]<x[b];
    });
    stack<int> stk;
    vector<int> y(n*2);
    for(int i=0;i<n*2;++i){
        if(stk.empty()||(stk.top()<n)==(s[i]<n)){
            stk.push(s[i]);
        }else{
            stk.pop();
        }
        if(!stk.empty()){
            if(stk.top()<n){
                y[i]=stk.size();
            }else{
                y[i]=-stk.size();
            }
        }
    }
    vector<LL> dt(n*2+1);
    LL tot=0;
    for(int i=0;i<n*2;++i){
        int w=(x[s[(i+1)%(n*2)]]-x[s[i]]+m)%m;
        dt[-y[i]+n]+=w;
        tot+=w;
    }
    LL cur=0;
    int val=0;
    for(int i=0;i<=n*2;++i){
        if((cur+dt[i])*2<tot){
            cur+=dt[i];
        }else{
            val=i-n;
            for(int j=0;j<=n*2;++j){
                sum+=dt[j]*abs(i-j);
            }
            break;
        }
    }
    for(int i=0;i<n*2;++i){
        y[i]+=val;
    }
    int k=0;
    while(y[k]!=0){
        ++k;
    }
    ++k;
    for(int i=k;i<k+n*2;++i){
        int x=i%(n*2);
        if(stk.empty()||(stk.top()<n)==(s[x]<n)){
            stk.push(s[x]);
        }else{
            ans[stk.top()]=s[x];
            ans[s[x]]=stk.top();
            stk.pop();
        }
    }
    cout<<sum<<endl;
    for(int i=0;i<n;++i){
        cout<<ans[i]+1-n<<' ';
    }
    cout<<endl;
    return 0;
}
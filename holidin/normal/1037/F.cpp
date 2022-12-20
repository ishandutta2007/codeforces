#include <bits/stdc++.h>
#define pb          push_back
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,k,A[1000005],l[1000005],r[1000005],ans;
int mul(int x,int y){
    return (1LL*x*y)%hell;
}
void solve(){
    cin>>n>>k;
    rep(i,0,n){
        cin>>A[i];
    }
    stack<int> s;
    s.push(0);
    l[0]=0;
    rep(i,1,n){
        while(!s.empty() && A[s.top()]<A[i]){
            s.pop();
        }
        if(s.empty()) l[i]=0;
        else l[i]=s.top()+1;
        s.push(i);
    }
    while(!s.empty()) s.pop();
    s.push(n-1);
    r[n-1]=n-1;
    for(int i=n-2;i>=0;--i){
        while(!s.empty() && A[s.top()]<=A[i]){
            s.pop();
        }
        if(s.empty()) r[i]=n-1;
        else r[i]=s.top()-1;
        s.push(i);
    }
    rep(i,0,n){
        int t1=(min(i-l[i],r[i]-i)-k)/(k-1)+1;
        if(min(i-l[i],r[i]-i)-k>=0){
            int cur;
            if(t1%2){
                cur=mul(A[i],t1);
                cur=mul(cur,(k+1LL*(t1-1)*(k-1)/2)%hell);
            }
            else{
                cur=mul(A[i],t1/2);
                cur=mul(cur,(2*k+1LL*(t1-1)*(k-1))%hell);
            }
            ans=(ans+cur)%hell;
        }
        if(i-l[i]+1<=k){
            int t2=(r[i]-i-k)/(k-1)+1;
            if(r[i]-i-k>=0){
                int cur=mul(A[i],t2);
                ans=(ans+mul(cur,i-l[i]+1))%hell;
            }
        }
        else{
            int ft=k+((i-l[i]-1)/(k-1))*(k-1);
            int t2=(r[i]-i-ft)/(k-1)+1;
            if(r[i]-i-ft>=0){
                int cur=mul(A[i],t2);
                ans=(ans+mul(cur,i-l[i]+1))%hell;
            }
        }
        if(r[i]-i+1<=k){
            int t3=(i-l[i]-k)/(k-1)+1;
            if(i-l[i]-k>=0){
                int cur=mul(A[i],t3);
                ans=(ans+mul(cur,r[i]-i+1))%hell;
            }
        }
        else{
            int ft=k+((r[i]-i-1)/(k-1))*(k-1);
            int t3=(i-l[i]-ft)/(k-1)+1;
            if(i-l[i]-ft>=0){
                int cur=mul(A[i],t3);
                ans=(ans+mul(cur,r[i]-i+1))%hell;
            }
        }
        int d=max(i-l[i]+1,r[i]-i+1);
        if(d<=k){
            int t4=(r[i]-l[i]+1-k)/(k-1)+1;
            if(r[i]-l[i]+1-k>=0){
                int cur;
                if(t4%2){
                    cur=(mul(r[i]-l[i]+2,t4)-mul(t4,(k+1LL*(t4-1)*(k-1)/2)%hell)+hell)%hell;
                }
                else{
                    cur=(mul(r[i]-l[i]+2,t4)-mul(t4/2,(2*k+1LL*(t4-1)*(k-1))%hell)+hell)%hell;
                }
                ans=(ans+mul(A[i],cur))%hell;
            }
        }
        else{
            int ft=k+((d-2)/(k-1))*(k-1);
            int t4=(r[i]-l[i]+1-ft)/(k-1)+1;
            if(r[i]-l[i]+1-ft>=0){
                int cur;
                if(t4%2){
                    cur=(mul(r[i]-l[i]+2,t4)-mul(t4,(ft+1LL*(t4-1)*(k-1)/2)%hell)+hell)%hell;
                }
                else{
                    cur=(mul(r[i]-l[i]+2,t4)-mul(t4/2,(2*ft+1LL*(t4-1)*(k-1))%hell)+hell)%hell;
                }
                ans=(ans+mul(A[i],cur))%hell;
            }
        }
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
        solve();
    return 0;
}
# include <bits/stdc++.h>
using namespace std;
# define int long long
# define endl "\n"
# define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

 
void primefactors(int n,map<int,int>&m){
    for(int i=2;i*i<=n;i++){
        while(n%i==0){m[i]++;n/=i;}
    }
    if(n>1)m[n]++;
}
 
int fun(int p, int n){
    int ans=0;
    int mypower = p;
    for(int i=1;;i++){
        auto tmp = (n/mypower);
        ans+=tmp;
        if(tmp<p) break;
        mypower*=p;
    }
    return ans;
}
 
int32_t main(){
    int n,b;cin>>n>>b;map<int,int>m,dup;primefactors(b,m);
    for(auto &it:m){
        dup[it.first]=fun(it.first,n);
    }
    int ans=LLONG_MAX,temp=0;
    for(auto &it:m){
        temp=(dup[it.first]/it.second);
        if(ans>temp)ans=temp;
    }
    cout<<(ans==LLONG_MAX?0:ans)<<endl;
}
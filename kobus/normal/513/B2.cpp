#include <bits/stdc++.h>
using namespace std;

#define MAXN 1123456
#define int long long
#define pb push_back

//m-esima perm de tamanho n
vector<int> find(int n,int m,int mini){
    if(n==1)return {mini};
    int val=1ll<<(n-2);
    //cout<<"val eh "<<val<<" "<<m<<endl;
    if(m<=val){
        //cout<<"entrou no if"<<endl;
        vector<int> a1={mini};
        vector<int> a2=find(n-1,m,mini+1);
        for(auto x:a2)a1.pb(x);
        return a1;
    }
    else{
        //cout<<"entrou no else"<<endl;
        vector<int> ans=find(n-1,m-val,mini+1);
        ans.pb(mini);
        return ans;

    }
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

    int n,m;
    cin>>n>>m;
    vector<int> ans=find(n,m,1ll);
    for(auto x:ans)cout<<x<<" ";
    cout<<endl;
	

    return 0;
 
}
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=200010;
int i,j,k,n,m,a[maxn];
priority_queue<int>Q;
map<int,int>M;
signed main(){
    int T;
    cin>>T;
    while(T--){
        M.clear();
        int num=0;
        while(!Q.empty())Q.pop();
        cin>>n;
        k=0;
        for(i=1;i<=n;i++)scanf("%d",&a[i]),k+=a[i],M[a[i]]++;Q.push(k);
        for(i=2;i<=n;i++){
            int x=Q.top();Q.pop();
            // cerr<<x<<endl;
            if(M[x])M[x]--,++num,i--;
            else{
                Q.push(x/2);
                Q.push((x+1)/2);
            }
        }
        while(!Q.empty()){
            int x=Q.top();Q.pop();
            if(M[x])M[x]--,++num;
        }
        // cerr<<"NUM="<<num<<endl;
        if(num==n)puts("Yes");
        else puts("No");
    }
}
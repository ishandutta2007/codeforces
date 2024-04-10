#include <bits/stdc++.h>

using namespace std;
#define DIM 200007
#define INF 1000000000000000007
typedef pair<long long,long long> pairll;
long long n,m,V[DIM],T[DIM],P[DIM],R[DIM],C[DIM],F=0;
map<pairll,pairll> M;
vector<long long> B,A[DIM];
void dfs(long long x,long long colour){
    if (colour==1)
        B.push_back(x);
    V[x]=1;
    C[x]=colour;
    for (int i = 0;i<A[x].size();i++){
        if (colour==C[A[x][i]])F = 1;
        if (V[A[x][i]]==0)dfs(A[x][i],3-colour);
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%lld %lld\n",&n,&m);
    for (int i = 1;i<=m;i++){
        long long x,y,flag = 0;
        scanf("%lld %lld\n",&x,&y);
        //cout<<x<<' '<<y<<endl;
        if (x>y){swap(x,y);
        flag = 1;}
        M[{x,y}]={i,flag};
        A[x].push_back(y);
        A[y].push_back(x);
    }
    dfs(1,1);
    if (F==1){
        cout<<"NO"<<endl;
        return 0;
    }
    for (int i = 0;i<B.size();i++){
        long long x,y,k = B[i],flag;
        for (int i = 0;i<A[k].size();i++){
            flag = 0;
            x = k; y = A[k][i];
            if (x>y){flag = 1; swap(x,y);}
            if (M[{x,y}].second==flag){
                R[M[{x,y}].first]=0;
            }
            else{
                R[M[{x,y}].first]=1;
            }
        }
    }
    cout<<"YES"<<endl;
    for (int i = 1;i<=m;i++){
        cout<<R[i];
    }
}
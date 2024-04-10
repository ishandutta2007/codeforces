#include <bits/stdc++.h>

using namespace std;
vector <long> graf[100005];
double dfs(long x, long y){
    double z=0,k=0;
    for(auto c:graf[x]){
        if(c!=y){
            z+=dfs(c,x)+1;
            k++;
        }
    }
    if(k!=0)z/=k;
    return z;
    }
int main()
{
    long n,a,b,i;
    cin>>n;
    for(i=1;i<n;i++){
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    printf("%.10f",dfs(1,0));
    return 0;
}
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
int n,m;
string s[1000005];
int dfs(int x,int y){
    if(s[x][y]=='#')return 0;
    if(x==n-1&&y==m-1)return 1;
    s[x][y]='#';
    return x+1<n&&dfs(x+1,y)||y+1<m&&dfs(x,y+1);
}
int main(){
    cin>>n>>m;
    f(i,0,n)cin>>s[i];
    int c=dfs(0,0);
    s[0][0]='.';
    c+=dfs(0,0);
    cout<<c;
    return 0;
}